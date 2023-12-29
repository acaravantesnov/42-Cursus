#include "Server.hpp"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdexcept>

// Constructor initializes the count of clients to zero.
Server::Server() : _count(0) {}

// Destructor closes all file descriptors to clean up resources.
Server::~Server() {
    for (size_t i = 0; i < _count; i++)
        if (_pollfds[i].fd >= 0)
            close(_pollfds[i].fd);
    std::cout << "Server closed" << std::endl;
}

// Returns a pointer to the array of pollfd structures for use with poll().
struct pollfd *Server::data() {
    return _pollfds.data();
}

// Adds a listening port to the server.
void Server::add_port(const std::vector<ConfigObject>& configs_vec) {
    ConfigObject config = configs_vec[0];
    struct sockaddr_in address;
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
        throw std::runtime_error("Failed to create socket.");
    
    // Set the socket to non-blocking.
    int flags = fcntl(server_fd, F_GETFL, 0);
    if (flags == -1)
        throw std::runtime_error("Failed to get socket flags.");
    if (fcntl(server_fd, F_SETFL, flags | O_NONBLOCK) == -1)
        throw std::runtime_error("Failed to set socket to non-blocking.");

    // Allow the socket to be reused immediately after closing.
    int option_value = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &option_value, sizeof(int)) < 0){
        throw std::runtime_error("Failed to set socket options.");
    }

	std::vector<std::string> ips = HttpLogic::get_ips(config);
	std::vector<int> ports = HttpLogic::get_ports(config);

    address.sin_family = AF_INET;
	// if (ips[0] == "0.0.0.0")
	// 	address.sin_addr.s_addr = INADDR_ANY;
	// else
    address.sin_addr.s_addr = inet_addr(ips[0].c_str()); //INADDR_ANY; I think INADDR_ANY means it will listen to all the ips
    address.sin_port = htons(ports[0]);


    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
        throw std::runtime_error("Bind address already in ase");

    if (listen(server_fd, 128) < 0)
        throw std::runtime_error("Failed to listen on socket.");

    std::cout << "Conexion made for " << ips[0] << ":" << ports[0] << " (server_names: ";
    for (size_t i = 0; i < configs_vec.size() - 1; i++)
        std::cout << HttpLogic::get_server_names(configs_vec[i])[0] << " ";
    if (configs_vec.size() > 0)
        std::cout << HttpLogic::get_server_names(configs_vec[configs_vec.size() - 1])[0];
    std::cout << ")" << std::endl;

    struct pollfd pfd = {server_fd, POLLIN, 0};
    _pollfds.push_back(pfd);
    _addresses[ports[0]] = address;
    _ports.push_back(ports[0]);
    _types.push_back(PORT);
    _responders.push_back(HttpResponder(server_fd, configs_vec)); // Placeholder to maintain vector alignment. Only config is used to copy to the connections
    _count++;
}

// Adds a new client connection.
void Server::add_connection(int port, int fd, const std::vector<ConfigObject>& configs_vec)    //TODO: Review if it is necesary to pass the port
{
    struct pollfd pfd = {fd, POLLIN | POLLOUT, 0};
    _pollfds.push_back(pfd);
    _types.push_back(CONNECTION);
    _ports.push_back(port); // Placeholder to maintain vector alignment. //could get port from config
    _responders.push_back(HttpResponder(fd, configs_vec));
    _count++;
}

// Removes a client connection.
void Server::remove_connection(int index)
{
    if (index < 0 || static_cast<size_t>(index) >= _pollfds.size()) {
        throw std::out_of_range("Index out of range for removing connection.");
    }
    if (close(_pollfds[index].fd) == -1)
        std::cout << "Error closing fd" << std::endl;
    _pollfds.erase(_pollfds.begin() + index);
    _types.erase(_types.begin() + index);
    _ports.erase(_ports.begin() + index);
    _responders.erase(_responders.begin() + index);
    _count--;
}

// Overloads the subscript operator for accessing pollfd objects.
struct pollfd Server::operator[](int index) {
    if (index < 0 || static_cast<size_t>(index) >= _pollfds.size()) {
        throw std::out_of_range("Index out of range for operator[].");
    }
    return _pollfds[index];
}

// Processes incoming connections and data.
void Server::spin() {
    for (unsigned int i = 0; i < _count; ++i) {
        if (_pollfds[i].revents & POLLIN)
        {
            if (_types[i] == PORT) { //Type is Type::PORT
                int new_socket_fd;
                socklen_t adresslen = sizeof(struct sockaddr_in);
                new_socket_fd = accept(_pollfds[i].fd, (struct sockaddr*)&(_addresses[_ports[i]]), &adresslen);
                if (new_socket_fd < 0) {
                    throw std::runtime_error("Failed to accept new connection.");
                }
                add_connection(_ports[i], new_socket_fd, _responders[i].get_config_vec());
            } else { //Type is Type::CONNECTION
                if (_responders[i].read() == -1)
                    remove_connection(i);
            }
        }
        if (_pollfds[i].revents & POLLOUT && _responders[i].is_response_ready_to_send())
        {
            if (_responders[i].write() == -1 || _responders[i].is_response_ready_to_send() == false){
                remove_connection(i);
                --i; // Adjust index since we've removed an item from the vector.
            }
        }
        else if (_pollfds[i].revents & POLLERR || _pollfds[i].revents & POLLHUP || _pollfds[i].revents & POLLNVAL){
            remove_connection(i);
            --i; // Adjust index since we've removed an item from the vector.
        }
        else
            _responders[i].check_cgi();
        //_responders[i].check_timeout();
    }
}

// Returns the current count of pollfd structures.
unsigned int Server::get_count() {
    return _count;
}

void Server::add_all(const ConfigObject& config)
{
    std::vector<std::vector<ConfigObject> > servers_by_listen = HttpLogic::get_servers_by_listen(config["server"]);

    for (size_t i = 0; i < servers_by_listen.size(); i++)
        add_port(servers_by_listen[i]);
}

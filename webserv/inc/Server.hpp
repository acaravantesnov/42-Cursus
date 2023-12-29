#ifndef CLIENTS_HPP
#define CLIENTS_HPP

#include <map>
#include <vector>
#include <poll.h>
#include <netinet/in.h>
#include "HttpResponder.hpp"
#include "Config.hpp"
#include "HttpLogic.hpp"
#include <fcntl.h>



// The Server class manages a collection of client connections and ports.
class Server {
public:
    // Enum class to differentiate between port and connection types.
    enum Type {
        PORT,
        CONNECTION
    };

    Server();
    ~Server();
    struct pollfd operator[](int index); // Overload the subscript operator to access pollfd.
    void spin(); // Handles incoming connections and data.
    struct pollfd *data(); // Returns a pointer to the pollfd structure.
    unsigned int get_count(); // Returns the number of connections.
    void add_all(const ConfigObject& config); // Adds all ports and connections.

private:
    unsigned int _count; // Keeps track of the number of connections.
    std::map<int, struct sockaddr_in> _addresses; // Maps a port number to its address.
    std::vector<struct pollfd> _pollfds; // Holds file descriptors being polled.
    std::vector<int> _ports; // Stores port numbers TODO:Review if it is necesary.
    std::vector<Type> _types; // Stores types (PORT or CONNECTION) for each file descriptor.
    std::vector<HttpResponder> _responders; // Holds HttpResponder objects for each connection.

    // Adds a new connection to the list of polled descriptors.
    void add_connection(int port, int fd, const std::vector<ConfigObject>& configs_vec);
    
    // Removes a connection from the list of polled descriptors.
    void remove_connection(int index);

    void add_port(const std::vector<ConfigObject>& configs); // Adds a port to listen for incoming connections.
};

#endif // CLIENTS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <poll.h>
#include <unistd.h>
#include <stdexcept> // For std::runtime_error
#include "Server.hpp"


int main(int argc, char **argv)
{
    try {
        if (argc != 2)
            throw std::runtime_error("Invalid syntax. Try ./webserv [configuration file].");

        Server          server;
        std::string     argv1 = std::string(argv[1]);
        ConfigObject    config(argv1);

        config.validateConfig();

        // std::vector<std::vector<ConfigItem> > servers_by_listen = HttpLogic::get_servers_by_listen(config["server"]);
        // std::cout << "Servers by listen size: " << servers_by_listen.size() << std::endl;
        // for (size_t i = 0; i < servers_by_listen.size(); i++)
        //     std::cout << "Server #" << i << ": " << servers_by_listen[i].size() << std::endl;

        // for (size_t i = 0; i < config["server"].size(); i++)
        //     server.add_port(config["server"][i].get_subConfig());
        server.add_all(config);

        // Server main loop
        while (true) {
            // Use poll to wait for an event on any of the sockets
            if (poll(server.data(), server.get_count(), -1) == -1) {
                throw std::runtime_error("Poll failed");
            }
            server.spin(); // Process events
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        // Log error, cleanup resources, and exit if necessary
        return EXIT_FAILURE;
    }

    return 0; // Never reached
}

// acaravan testing
// int main(int argc, char **argv)
// {
//     //atexit(leaks);
//     if (argc != 2)
//     {
//         std::cout << "Usage: ./test <config_file>" << std::endl;
//         return (0);
//     }
//     std::string config_file_path = std::string(argv[1]);
// 	ConfigObject config(config_file_path);
//     HttpRequest request(HttpRequest::GET, std::string("/files/hola.php"), std::string("2.1"), 
//     std::string("rgaebaebt"), 200, true);

// 	std::cout << "IPs:" << std::endl;
// 	for (size_t i = 0; i < config["server"].size(); i++)
// 		for (size_t j = 0; j < config["server"][i]["listen"].size(); j++)
// 			std::cout << "Server #" << i << ": " << HttpLogic::get_ips(config["server"][i].get_subConfig())[j] << std::endl;

// 	std::cout << "\nSERVER NAMES:" << std::endl;
// 	for (size_t i = 0; i < config["server"].size(); i++)
//         for (size_t j = 0; j < HttpLogic::get_server_names(config["server"][i].get_subConfig()).size(); j++)
//             std::cout << "Server #" << i << ": " << HttpLogic::get_server_names(config["server"][i].get_subConfig())[j] << std::endl;

//     std::cout << "\nPORTS:" << std::endl;
// 	for (size_t i = 0; i < config["server"].size(); i++)
// 		for (size_t j = 0; j < config["server"][i]["listen"].size(); j++)
// 			std::cout << "Server #" << i << ": " << HttpLogic::get_ports(config["server"][i].get_subConfig())[j] << std::endl;

//     // Si se especifica un path pero no existe location -> 404
//     // Si no se especifica un path -> allow_methods del server
//     std::cout << "\nLOCATION: ";
//     if (request.getPath() != "")
//         std::cout << request.getPath() << std::endl;
//     else
//         std::cout << std::endl;
//     for (size_t i = 0; i < config["server"].size(); i++)
//     {
//         std::vector<int> locs = HttpLogic::check_location(request, config["server"][i].get_subConfig());
//         for (size_t j = 0; j < locs.size(); j++)
//         {
//             std::cout << locs[j] << " ";
//         }
//         std::cout << std::endl;
//     }

//     std::cout << "\nREQUEST TYPE: " << request.getType() << std::endl;
//     for (size_t i = 0; i < config["server"].size(); i++)
//     {
//         if (HttpLogic::check_type_permision(request, config["server"][i].get_subConfig()) == false)
//             std::cout << "Server #" << i << ": " << "false" << std::endl;
//         else
//             std::cout << "Server #" << i << ": " << "true" << std::endl;
//     }

// 	std::cout << "\nROOT DIRECTORY: " << std::endl;
// 	for (size_t i = 0; i < config["server"].size(); i++)
// 		std::cout << "Server #" << i << ": " << HttpLogic::get_file_root(request, config["server"][i].get_subConfig()) << std::endl;

// 	std::cout << "\nFILE PATH: " << std::endl;
// 	for (size_t i = 0; i < config["server"].size(); i++)
//     	std::cout << "Server #" << i << ": " << HttpLogic::get_file_path(request, config["server"][i].get_subConfig()) << std::endl;

//     std::cout << "\nCLIENT BODY BUFFER SIZE: " << std::endl;
//     for (size_t i = 0; i < config["server"].size(); i++)
//         std::cout << "Server #" << i << ": " << HttpLogic::get_client_body_size(request, config["server"][i].get_subConfig()) << std::endl;

// 	std::cout << "\nAUTOINDEX: " << std::endl;
//     for (size_t i = 0; i < config["server"].size(); i++)
// 	{
// 		if (HttpLogic::get_autoindex(request, config["server"][i].get_subConfig()) == false)
// 			std::cout << "Server #" << i << ": false" << std::endl;
// 		else
// 			std::cout << "Server #" << i << ": true" << std::endl;
// 	}

//     std::cout << "\nINDEX PATH: " << std::endl;
//     for (size_t i = 0; i < config["server"].size(); i++)
//         std::cout << "Server #" << i << ": " << HttpLogic::get_index_path(request, config["server"][i].get_subConfig()) << std::endl;

// 	std::cout << "\nERROR FILE PATH: " << std::endl;
//     for (size_t i = 0; i < config["server"].size(); i++)
//         std::cout << "Server #" << i << ": " << HttpLogic::get_error_page_filepath(request, config["server"][i].get_subConfig(), 200) << std::endl;

//     std::cout << "\nCGIs: " << std::endl;
//     for (size_t i = 0; i < config["server"].size(); i++)
//         std::cout << "Server #" << i << ": " << HttpLogic::get_cgis(request, config["server"][i].get_subConfig())[".py"] << std::endl;

// 	std::cout << "\nCGI path: " << std::endl;
//     for (size_t i = 0; i < config["server"].size(); i++)
//         std::cout << "Server #" << i << ": " << HttpLogic::get_cgi_path(request, config["server"][i].get_subConfig()) << std::endl;

//     std::cout << "\nCGI ENVIRONMENT VARIABLES: " << std::endl;
//     for (size_t i = 0; i < config["server"].size(); i++)
//     {
//         std::vector<std::pair<std::string, std::string> > cgiEnvVars = HttpLogic::get_cgi_env_vars(request, config["server"][i].get_subConfig());
//         for (size_t j = 0; j < cgiEnvVars.size(); j++)
//             std::cout << "Server #" << i << ": " << cgiEnvVars[j].first << " " << cgiEnvVars[j].second << std::endl;
//     }

//     std::cout << "\nRETURN: " << std::endl;
//     for (size_t i = 0; i < config["server"].size(); i++)
//     {
//         std::pair<int, std::string> ret = HttpLogic::get_return(request, config["server"][i].get_subConfig());
//         std::cout << "Server #" << i << ": " << ret.first << " " << ret.second << std::endl;
//     }

// 	return (0);
// }

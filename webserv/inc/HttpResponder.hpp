#ifndef HTTPRESPONDER_HPP
#define HTTPRESPONDER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include "HttpRequest.hpp"
#include "Config.hpp"
#include "HttpLogic.hpp"
#include "HttpResponse.hpp"
#include "CGI.hpp"
#include "Utils.hpp"
#include "CGI.hpp"

#include <sys/stat.h>
#include <cstdio>

#ifndef READ_BUFFER_SIZE
    #define READ_BUFFER_SIZE 1024 * 128
#endif

#ifndef WRITE_BUFFER_SIZE
    #define WRITE_BUFFER_SIZE 1024 * 128
#endif

// The HttpResponder class handles the sending and receiving of HTTP requests.
class HttpResponder {
private:
    int _fd; // File descriptor for the socket connection
    bool _request_reading_completed; // Flag to check if the request has been compleatly read
    bool _response_waiting_to_be_sent; // Flag to check if a response as been read and processed and is waiting to be sent
    bool _response_sending_started; // Flag to check if the response sending process has started so we only print it once

    //For non blocking CGI
    bool _processing_cgi;
    CGI _cgi_instance;


    //std::string _request; // String to hold the request
    HttpRequest _request; // HttpRequest object to hold and parse the request
    std::vector<char> _response; // String to hold the response

    std::vector<ConfigObject> _configs_vec;
    ConfigObject _config; //Once the request is read we asign to _config the corresponding config from _configs_vec

    // Private method to process the request
    void process_request(const HttpRequest& request);

	std::vector<char> process_get_request(const HttpRequest& request);
    void              process_get_request_cgi(const HttpRequest& request);
	void              process_post_request(const HttpRequest& request);
	std::vector<char> process_delete_request(const HttpRequest& request);

	bool file_exists(const std::string& path);

public:
    // Default constructor
    HttpResponder();

    // Constructor with file descriptor to set up the connection
    HttpResponder(int fd);

    // Constructor with file descriptor and configuation
    HttpResponder(int fd, const std::vector<ConfigObject>& _configs_vec);

    // Copy constructor
    HttpResponder(const HttpResponder& other);

    // Destructor
    ~HttpResponder();

    // Copy assignment operator
    HttpResponder& operator=(const HttpResponder& other);

    // Method to handle the HTTP request and response process
    //int spin();

    //Method to handle the HTTP reading process
    int read();

    //Method to handle the HTTP writing process
    int write();

    bool is_response_ready_to_send();

    const ConfigObject& get_config() const;
    const std::vector<ConfigObject>& get_config_vec() const;

    void check_cgi();
};

#endif // HTTPRESPONDER_HPP

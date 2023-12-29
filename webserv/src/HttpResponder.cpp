#include "HttpResponder.hpp"
#include <fstream>
#include <stdexcept>
#include <sys/socket.h>

// Default constructor initializes file descriptor and request received flag
HttpResponder::HttpResponder() : _fd(-1), _request_reading_completed(false), _response_waiting_to_be_sent(false), _response_sending_started(false), _processing_cgi(false), _cgi_instance(), _request(), _response(), _configs_vec(), _config() {}

// Constructor with file descriptor initializes the connection for HTTP response
HttpResponder::HttpResponder(int fd) : _fd(fd), _request_reading_completed(false), _response_waiting_to_be_sent(false), _response_sending_started(false), _processing_cgi(false), _cgi_instance(), _request(), _response(), _configs_vec(), _config()
{
    //REMOVE
    std::cout << "It should be not used" << std::endl;
}

HttpResponder::HttpResponder(int fd, const std::vector<ConfigObject>& configs_vec) : _fd(fd),  _request_reading_completed(false), _response_waiting_to_be_sent(false), _response_sending_started(false), _processing_cgi(false), _cgi_instance(),  _request(), _response(), _configs_vec(configs_vec), _config() {}

// Copy constructor for deep copy
HttpResponder::HttpResponder(const HttpResponder& other): _fd(other._fd),  _request_reading_completed(other._request_reading_completed), _response_waiting_to_be_sent(other._response_waiting_to_be_sent), _response_sending_started(other._response_sending_started), _processing_cgi(other._processing_cgi), _cgi_instance(other._cgi_instance), _request(other._request), _response(other._response), _configs_vec(other._configs_vec), _config(other._config) {}


// Destructor closes the file descriptor if it is open
HttpResponder::~HttpResponder() {
    //Server is already closing it's file descriptors
}



// Copy assignment operator for deep copy
HttpResponder& HttpResponder::operator=(const HttpResponder& other) {
    if (this == &other)
        return *this;
    _fd = other._fd;
    _request = other._request;
    _response = other._response;
    _request_reading_completed = other._request_reading_completed;
    _response_waiting_to_be_sent = other._response_waiting_to_be_sent;
    _response_sending_started = other._response_sending_started;
    _processing_cgi = other._processing_cgi;
    _cgi_instance = other._cgi_instance;
    _configs_vec = other._configs_vec;
    _config = other._config;
    return *this;
}

void HttpResponder::process_get_request_cgi(const HttpRequest& request)
{
	try
	{
		_cgi_instance = CGI(request, _config, "./cgi-bin/time.py");
		_cgi_instance.run_cgi(request, _config);
		_processing_cgi = true;
	}
	catch (const std::exception& e)
	{
		if (std::string(e.what()) == "CGI script path not set.")
			_response = HttpResponse::general_response(request, 500, _config);
		else if (std::string(e.what()) == "CGI script does not exist.")
			_response = HttpResponse::general_response(request, 404, _config);
		else if (std::string(e.what()) == "Extension not supported.")
			_response = HttpResponse::general_response(request, 400, _config);
		else if (std::string(e.what()) == "Unable to allocate memory.")
			_response = HttpResponse::general_response(request, 500, _config);
		else if (std::string(e.what()) == "Unable to create pipe.")
			_response = HttpResponse::general_response(request, 500, _config);
		else if (std::string(e.what()) == "Unable to fork.")
			_response = HttpResponse::general_response(request, 500, _config);
		else if (std::string(e.what()) == "Cannot execute CGI script.")
			_response = HttpResponse::general_response(request, 500, _config);
		else if (std::string(e.what()) == "Waitpid failed.")
			_response = HttpResponse::general_response(request, 500, _config);

		_response_waiting_to_be_sent = true;
	}
}

std::vector<char> HttpResponder::process_get_request(const HttpRequest& request){
	std::string file_path = HttpLogic::get_file_path(request, _config);

	if (file_path[file_path.size() - 1] == '/' || Utils::is_directory(file_path)) //check if path is a directory
	{
		std::string index_path = HttpLogic::get_index_path(request, _config);
		if (index_path != "")
			file_path = index_path;
		else if (HttpLogic::get_autoindex(request, _config))
			return HttpResponse::autoindex_response(request, file_path, _config);
		else
			return HttpResponse::general_response(request, 404, _config);
	}
	//check if file exists
	if (!Utils::file_exists(file_path)){
		return HttpResponse::general_response(request, 404, _config);
    }
    return HttpResponse::file_response(request, file_path, _config);
}

void HttpResponder::process_post_request(const HttpRequest& request)
{
	try
	{
		_cgi_instance = CGI(request, _config, "./cgi-bin/upload_files.py");
		_cgi_instance.run_cgi(request, _config);
		_processing_cgi = true;
	}
	catch (const std::exception& e)
	{
		//std::cout << std::string(e.what()) << std::endl;
		if (std::string(e.what()) == "CGI script path not set.")
			_response = HttpResponse::general_response(request, 500, _config);
		else if (std::string(e.what()) == "CGI script does not exist.")
			_response = HttpResponse::general_response(request, 404, _config);
		else if (std::string(e.what()) == "Extension not supported.")
			_response = HttpResponse::general_response(request, 400, _config);
		else if (std::string(e.what()) == "Unable to allocate memory.")
			_response = HttpResponse::general_response(request, 500, _config);
		else if (std::string(e.what()) == "Unable to create pipe.")
			_response = HttpResponse::general_response(request, 500, _config);
		else if (std::string(e.what()) == "Unable to fork.")
			_response = HttpResponse::general_response(request, 500, _config);
		else if (std::string(e.what()) == "Cannot execute CGI script.")
			_response = HttpResponse::general_response(request, 500, _config);
		else if (std::string(e.what()) == "Waitpid failed.")
			_response = HttpResponse::general_response(request, 500, _config);

		_response_waiting_to_be_sent = true;
	}
}

std::vector<char> HttpResponder::process_delete_request(const HttpRequest& request){
	std::string file_path = HttpLogic::get_file_path(request, _config);
	if (!Utils::file_exists(file_path)){
		return HttpResponse::general_response(request, 404, _config);
    }
    if (file_path[file_path.size() - 1] == '/' || Utils::is_directory(file_path)){
		return HttpResponse::general_response(request, 503, _config);
    }
    //check if file exists
    if (!Utils::file_exists(file_path)){
        return HttpResponse::general_response(request, 404, _config);
    }
    //check if we have permissions to delete the file
    if (access(file_path.c_str(), W_OK) != 0){
        return HttpResponse::general_response(request, 403, _config);
    }
    //delete file
	if (remove(file_path.c_str()) != 0){
		return HttpResponse::general_response(request, 500, _config);
    }
	return HttpResponse::general_response(request, 204, _config);
}

void HttpResponder::process_request(const HttpRequest& request) {
	if (HttpLogic::get_return(request, _config).first > 0)
	{
		_response =  HttpResponse::redirect_response(request, _config);
		_response_waiting_to_be_sent = true;
        return;
	}
	if (!HttpLogic::check_type_permision(request, _config))
	{
		_response =  HttpResponse::general_response(request, 405, _config);
		_response_waiting_to_be_sent = true;
        return;
	}
	switch (request.getType())
	{
	case HttpRequest::GET:
		if (HttpLogic::is_cgi(request, _config))
			process_get_request_cgi(request);
		else
		{
			_response =  process_get_request(request);
			_response_waiting_to_be_sent = true;
		}
		break;
	case HttpRequest::POST:
		if (!Utils::is_directory(HttpLogic::get_file_path(request, _config)))
			process_post_request(request);
		else
		{
			_response = HttpResponse::general_response(request, 400, _config);
			_response_waiting_to_be_sent = true;
		}
		break;
	case HttpRequest::DELETE:
		_response =  process_delete_request(request);
		_response_waiting_to_be_sent = true;
		break;
	default:
		_response = HttpResponse::general_response(request, 405, _config);
		break;
	}
}

int HttpResponder::read() {
    try {
        if (_request_reading_completed == false)
        {
            char buffer[READ_BUFFER_SIZE];
            int size = recv(_fd, buffer, sizeof(buffer), 0);
			//std::cout << buffer;
            if (size <= 0)
                return -1;
            try {
                _request.parseInput(buffer, size);
				_request_reading_completed = _request.isParsed();
            }
            catch(const HttpRequest::LengthRequiredException_411& e){
				HttpStatusCode stc;
				stc.set(411);
				_response = HttpResponse::basic_html(stc);
				_response_waiting_to_be_sent = true;
                _request_reading_completed = true;
            }
            catch(const HttpRequest::MethodNotAllowedException_405& e){
				HttpStatusCode stc;
				stc.set(405);
				_response = HttpResponse::basic_html(stc);
                _response_waiting_to_be_sent = true;
                _request_reading_completed = true;
            }
            catch(const HttpRequest::HttpException& e){
				HttpStatusCode stc;
				stc.set(400);
				_response = HttpResponse::basic_html(stc);
                _response_waiting_to_be_sent = true;
                _request_reading_completed = true;
            }
            catch(const std::exception& e){
				HttpStatusCode stc;
				stc.set(500);
				_response = HttpResponse::basic_html(stc);
                _response_waiting_to_be_sent = true;
                _request_reading_completed = true;
            }
        }
        if (_request_reading_completed)
        {
			#if DEBUG
            std::cout << "REQUEST: \n" << _request << std::endl;
			#endif
            _config = HttpLogic::get_config_from_vec(_request, _configs_vec);
            long body_size = HttpLogic::get_client_body_size(_request, _config);
            if (body_size != -1 && _request.getBody().size() > (size_t) body_size){
                _response = HttpResponse::general_response(_request, 413, _config);
                _response_waiting_to_be_sent = true;
                return 0;
            }
            try{
                process_request(_request);
            }
            catch(const std::exception& e){
				std::cout << "Exception occurred: " << e.what() << '\n';
                _response = HttpResponse::general_response(_request, 500, _config);
                _response_waiting_to_be_sent = true;
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception occurred: " << e.what() << '\n';
    }
    return 1;
}

int HttpResponder::write() {
    try {
        if (_request_reading_completed && _response_waiting_to_be_sent)
        {
            if (!_response_sending_started){
				#if DEBUG 
                std::cout << "RESPONSE:" << std::endl;
                std::cout << "\033[1;32m";
                if (_response.size() > 400)
                    std::cout << Utils::vectorToString(Utils::substr(_response, 0, 300)) << std::endl << ". . .\n" << std::endl;
                else
                    std::cout << Utils::vectorToString(_response) << std::endl << std::endl;
				std::cout << "\033[0m";
				#endif
                _response_sending_started = true;
            }
            int size;
            char buffer[WRITE_BUFFER_SIZE];
            //copy up to WRITE_BUFFER_SIZE bytes from _response to buffer
            size = _response.size() > WRITE_BUFFER_SIZE ? WRITE_BUFFER_SIZE : _response.size();
            std::copy(_response.begin(), _response.begin() + size, buffer);
            _response = std::vector<char>(_response.begin() + size, _response.end());
            if (send(_fd, buffer, size, 0) <= 0)
                return -1;
            if (_response.size() == 0){
                _response_waiting_to_be_sent = false;
                _response_sending_started = false;
            }
        }
		
    } catch (const std::exception& e) {
        std::cerr << "Exception occurred: " << e.what() << '\n';
    }
    return 1;
}

bool HttpResponder::is_response_ready_to_send() {
    return _response_waiting_to_be_sent;
}

const ConfigObject& HttpResponder::get_config() const {
    return _config;
}

void HttpResponder::check_cgi()
{
    if (!_processing_cgi)
        return;
    if (_cgi_instance.is_cgi_done())
    {
        std::vector<char> cgiOutput = _cgi_instance.get_cgi_output();
		_response = HttpResponse::cgi_response(_request ,cgiOutput, _cgi_instance.get_child_status(), _config);
        _processing_cgi = false;
        _response_waiting_to_be_sent = true;
    }
}

const std::vector<ConfigObject>& HttpResponder::get_config_vec() const {
    return _configs_vec;
}

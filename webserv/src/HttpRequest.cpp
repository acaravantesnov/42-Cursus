#include "HttpRequest.hpp"

HttpRequest::HttpRequest(): _parsed(false)
{
}

HttpRequest::~HttpRequest()
{
}

void HttpRequest::parseInput(char *bytes, int n_bytes)
{
    if (n_bytes < 1)
        return;
    if (_unparsed_header.find("\r\n\r\n") != std::string::npos)
    {
        _body.insert(_body.end(), bytes, bytes + n_bytes);
        if (_body.size() >= (size_t) _content_length)
            _parsed = true;
        return;
    }
    _unparsed_header.append(bytes, n_bytes);

    if (_unparsed_header.find("\r\n\r\n") == std::string::npos)
        return;

    _body.insert(_body.end(), _unparsed_header.begin() + _unparsed_header.find("\r\n\r\n") + 4, _unparsed_header.end());
    _unparsed_header = _unparsed_header.substr(0, _unparsed_header.find("\r\n\r\n") + 4);
	std::string line;
    std::stringstream ss(_unparsed_header);
    std::getline(ss, line);
    std::stringstream ssl(line);
    std::string type;
    ssl >> type;
    if (type == "GET")
        _type = GET;
    else if (type == "POST")
        _type = POST;
    else if (type == "DELETE")
        _type = DELETE;
    else{
        throw MethodNotAllowedException_405();
	}

    ssl >> _path;
    ssl >> _version;
    while (std::getline(ss, line))
    {
        std::stringstream ssl(line);
        std::string key, value;
        std::getline(ssl, key, ':');
        std::getline(ssl, value);
        _header[key] = value;
    }
    if (_type == POST && _header.find("Content-Length") == _header.end() && _header.find("Content-Type") != _header.end())
        throw LengthRequiredException_411();
    if (_header.count("Content-Length") > 0)
	{
        _content_length = Utils::my_stol(_header["Content-Length"]);
		if (_body.size() >= (size_t) _content_length)
			_parsed = true;
	}
    else
        _parsed = true;
}


std::ostream &operator<<(std::ostream &os, const HttpRequest &request)
{
    os << "\033[1;31mType: " << request.getType() << std::endl;
    os << "Path: " << request.getPath() << std::endl;
    os << "Version: " << request.getVersion() << std::endl;
    os << "Header: " << std::endl;
    std::map<std::string, std::string> header = request.getHeader();
    for (std::map<std::string, std::string>::iterator it = header.begin(); it != header.end(); ++it)
        os << it->first << ": " << it->second << std::endl;
    os << "Body: " << std::endl;
    std::vector<char> body = request.getBody();
	std::vector<char>::iterator it = body.begin();
	int i = 0;
	while ((it != body.end()) && (i < 300))
	{
		os << *it;
		it++;
		i++;
	}
	if (i == 300)
		std::cout << "\n . . ." << std::endl;
    os << "\033[0m" << std::endl;
    return os;
}

bool HttpRequest::isParsed() const
{
    return _parsed;
}

std::vector<char> HttpRequest::getBody() const
{
    return _body;
}

std::map<std::string, std::string> HttpRequest::getHeader() const
{
    return _header;
}

std::string HttpRequest::getPath() const
{
    return _path;
}

HttpRequest::RequestType HttpRequest::getType() const
{
    return _type;
}

std::string HttpRequest::getVersion() const
{
    return _version;
}


//Host: server_name:port_number
std::string HttpRequest::getHost() const
{
    if (_header.count("Host") < 1)
        return "";
    std::string host;
    host = _header.at("Host");
    if (host.find(':') != std::string::npos)
        host = host.substr(0, host.find(':'));
    host = Utils::trim(host);
    return host;
}

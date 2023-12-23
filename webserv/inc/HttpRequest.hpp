#ifndef HTTPREQUEST_HPP
#define HTTPREQUEST_HPP

#include <string>
#include <map>
#include <vector>
#include <exception>
#include <iostream>
#include <sstream>

#include "Utils.hpp"

class HttpRequest
{
public:
    //Request types
    enum RequestType
    {
        GET,
        POST,
        DELETE
    };

    HttpRequest();
    HttpRequest(RequestType type, std::string path, std::string version, \
	std::string unparsed_header, int content_length, bool parsed)
	{
		this->_type = type;
		this->_path = path;
		this->_version = version;
		this->_unparsed_header = unparsed_header;
		this->_content_length = content_length;
		this->_parsed = parsed;
	}
    ~HttpRequest();

    void parseInput(char *bytes, int n_bytes);
    bool isParsed() const;

    std::vector<char> getBody() const;

    std::map<std::string, std::string> getHeader() const;

    std::string getPath() const;

    std::string getVersion() const;

    std::string getUnparsedHeader() const;

    RequestType getType() const;

    std::string getHost() const;

    class HttpException : public std::exception
    {
    };

    //411 Length required exception
    class LengthRequiredException_411 : public HttpException
    {
        virtual const char *what() const throw()
        {
            return "Length required";
        }
    };

    //400 Bad request exception
    class BadRequestException_400 : public HttpException
    {
        virtual const char *what() const throw()
        {
            return "Bad request";
        }
    };

    //405 Method not allowed exception
    class MethodNotAllowedException_405 : public HttpException
    {
        virtual const char *what() const throw()
        {
            return "Method not allowed";
        }
    };

private:

    //Request type
    RequestType _type;

    //Request path
    std::string _path;

    //Http version
    std::string _version;

    //Unparsed header
    std::string _unparsed_header;

    //Request header
    std::map<std::string, std::string> _header;

    //Request body
    std::vector<char> _body;

    //content length
    int _content_length;

    //flas to indicate if the request has been parsed
    bool _parsed;



};

std::ostream &operator<<(std::ostream &os, const HttpRequest &request);

#endif

#include "../inc/HttpHeader.hpp"
#include <cstdlib>
#include <stdlib.h>


HttpHeader::HttpHeader() {}

HttpHeader::HttpHeader(HttpHeader & hdr) { _header = hdr.get(); }

HttpHeader & HttpHeader::operator=(HttpHeader & hdr)
{ 
	_header = hdr.get();
	return *this;
}

HttpHeader::~HttpHeader() {}

std::vector<char> & HttpHeader::get( void )
{
	return _header;
}

// Methods

std::string HttpHeader::getTime( void )
{
	std::vector<std::string> date(5, "");
	time_t now = time(0);
	char *d = ctime(&now);
	//Wed Dec  6 00:48:10 2023

	// split a date
	size_t i = 0;
	size_t k = 0;
	while (d[i] != '\0')
	{
		if (d[i] != ' ')
		{
			if (d[i] != '\n')
				date[k].push_back(d[i]);
		} else {
			//std::cout << date[k] << std::endl;
			if (d[i - 1] != ' ') //so when there are two spaces in a row, it doesn't count as a new word
				k++;
		}
		i++;
	}

	// reordenar como debe ser y + GMT;
	return (date[0] + ", " + date[2] + " " + date[1] + " " + date[4] + " " + date[3] + " GMT");
}

void HttpHeader::buildHeader(const ConfigObject & config, HttpStatusCode & stc, unsigned int bytes)
{
	std::string code;
	std::string temp;

	code = Utils::uint_to_string(static_cast<unsigned int>(stc.getCode()));

	std::vector<char> http = Utils::stringToVector("HTTP/1.1 ");

	temp = code + " " + stc.wordCode() + "\n";
	std::vector<char> codeV = Utils::stringToVector(temp);
	temp.clear();

	_header = Utils::concat(http, codeV);

	temp = "Date: " + HttpHeader::getTime() + "\n";
	std::vector<char> time = Utils::stringToVector(temp);
	temp.clear();

	_header = Utils::concat(_header, time);

	temp = "Server: " + (HttpLogic::get_server_names(config))[0] + "\n";
	std::vector<char> server = Utils::stringToVector(temp);
	temp.clear();

	_header = Utils::concat(_header, server);

//	_header += "Last-Modified: " + HttpHeader::getTimeOfFile() + "\n"; // Solo GET ??

	temp = "Content-Length: " + Utils::uint_to_string(bytes) + "\n"; // Solo GET??
	std::vector<char> len = Utils::stringToVector(temp);
	temp.clear();

	_header = Utils::concat(_header, len);
//	_header += "Content-Type: " + /* RequestData.type */ + "\n"; // Solo GET ??

	temp = "Connection: Closed\n\n";
	std::vector<char> finale = Utils::stringToVector(temp);
	temp.clear();

	_header = Utils::concat(_header, finale);
}

void HttpHeader::redirectHeader(HttpStatusCode & stc, const std::string uri_path)
{
	std::string code;
	std::vector<char> header;
	std::vector<char> location;

	code = Utils::uint_to_string(static_cast<unsigned int>(stc.getCode()));

	header = Utils::stringToVector("HTTP/1.1 " + code + " " + stc.wordCode() + "\n");
	location = Utils::stringToVector("Location: " + uri_path + "\n");

	_header = Utils::concat(header, location);
}

void HttpHeader::buildLine(HttpStatusCode & stc)
{
	std::string code;
	std::string line;

	code = Utils::uint_to_string(static_cast<unsigned int>(stc.getCode()));
	line = "HTTP/1.1 " + code + " " + stc.wordCode() + "\n";
	_header = Utils::stringToVector(line);
}

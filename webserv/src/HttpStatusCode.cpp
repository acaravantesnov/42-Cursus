#include "../inc/HttpStatusCode.hpp"

HttpStatusCode::HttpStatusCode() {}

static std::map<HttpStatusCode::Code, std::string> initMap( void )
{
	std::map<HttpStatusCode::Code, std::string> mapa;

	// 1xx Informational
	mapa[HttpStatusCode::CONTINUE] = "Continue";
	mapa[HttpStatusCode::SWITCHING_PROTOCOLS] = "Switching Protocols";

	// 2xx Success
	mapa[HttpStatusCode::OK] = "OK";
	mapa[HttpStatusCode::CREATED] = "Created";
	mapa[HttpStatusCode::ACCEPTED] = "Accepted";
	mapa[HttpStatusCode::NON_AUTHORITATIVE_INFORMATION] = "Non-Authoritative Information";
	mapa[HttpStatusCode::NO_CONTENT] = "No Content";
	mapa[HttpStatusCode::RESET_CONTENT] = "Reset Content";
	mapa[HttpStatusCode::PARTIAL_CONTENT] = "Partial Content";

	// 3xx Redirection
	mapa[HttpStatusCode::MULTIPLE_CHOICES] = "Multiple Choices";
	mapa[HttpStatusCode::MOVED_PERMANENTLY] = "Moved Permanently";
	mapa[HttpStatusCode::FOUND] = "Found";
	mapa[HttpStatusCode::SEE_OTHER] = "See Other";
	mapa[HttpStatusCode::NOT_MODIFIED] = "Not Modified";
	mapa[HttpStatusCode::USE_PROXY] = "Use Proxy";
	mapa[HttpStatusCode::UNUSED] = "Unused";
	mapa[HttpStatusCode::TEMPORARY_REDIRECT] = "Temporary Redirect";

	// 4xx Client Error
	mapa[HttpStatusCode::BAD_REQUEST] = "Bad Request";
	mapa[HttpStatusCode::UNAUTHORIZED] = "Unauthorized";
	mapa[HttpStatusCode::PAYMENT_REQUIRED] = "Payment Required";
	mapa[HttpStatusCode::FORBIDDEN] = "Forbidden";
	mapa[HttpStatusCode::NOT_FOUND] = "Not Found";
	mapa[HttpStatusCode::METHOD_NOT_ALLOWED] = "Method Not Allowed";
	mapa[HttpStatusCode::NOT_ACCEPTABLE] = "Not Acceptable";
	mapa[HttpStatusCode::PROXY_AUTHENTICATION_REQUIERED] = "Proxy Authentication Required";
	mapa[HttpStatusCode::REQUEST_TIMEOUT] = "Request Timeout";
	mapa[HttpStatusCode::CONFLICT] = "Conflict";
	mapa[HttpStatusCode::GONE] = "Gone";
	mapa[HttpStatusCode::LENGTH_REQUIRED] = "Length Required";
	mapa[HttpStatusCode::PRECONDITION_FAILED] = "Precondition Failed";
	mapa[HttpStatusCode::REQUEST_ENTITY_TOO_LARGE] = "Request Entity Too Large";
	mapa[HttpStatusCode::REQUEST_URL_TOO_LONG] = "Request-URL Too Long";
	mapa[HttpStatusCode::UNSUPORTED_MEDIA_TYPE] = "Unsuported Media Type";
	mapa[HttpStatusCode::REQUEST_RANGE_NOT_SATISFABLE] = "Request Range Not Satisfable";
	mapa[HttpStatusCode::EXPECTATION_FAILED] = "Expectation Failed";

	// 5xx Server Error
	mapa[HttpStatusCode::INTERNAL_SERVER_ERROR] = "Internal Server Error";
	mapa[HttpStatusCode::NOT_IMPLEMENTED] = "Not Implemented";
	mapa[HttpStatusCode::BAD_GATEWAY] = "Bad Gateway";
	mapa[HttpStatusCode::SERVICE_UNAVAILABLE] = "Service Unavailable";
	mapa[HttpStatusCode::GATEWAY_TIMEOUT] = "Gateway Timeout";
	mapa[HttpStatusCode::HTTP_VERSION_NOT_SUPPORTED] = "HTTP Version Not Supported";

	return mapa;
}

HttpStatusCode::HttpStatusCode(HttpStatusCode & stc) {
	(void)stc;
}


HttpStatusCode::~HttpStatusCode() {}

// Overloads
HttpStatusCode & HttpStatusCode::operator=(HttpStatusCode & stc)
{
	if (this != &stc)
		this->_code = stc.getCode();
	return (*this);
}


bool HttpStatusCode::operator==(const HttpStatusCode & stc)
{
	return _code == stc.getCode();
}

bool HttpStatusCode::operator!=(const HttpStatusCode & stc)
{
	return _code != stc.getCode();
}

// Accessors

void HttpStatusCode::set(HttpStatusCode::Code code)
{
	this->_code = code;
}

void HttpStatusCode::set(std::string code)
{
	int numCode = std::atoi(code.c_str());

	if (!HttpStatusCode::isValid(numCode)){
		;// Exception
	}
	this->_code = static_cast<HttpStatusCode::Code>(numCode);
}

void HttpStatusCode::set(int code)
{
	if (!HttpStatusCode::isValid(code))
	{
		;// Exception
	}
	this->_code = static_cast<HttpStatusCode::Code>(code);
}

HttpStatusCode::Code const & HttpStatusCode::getCode( void ) const
{
	return _code;
}

// Methods

bool HttpStatusCode::isValid(int code)
{
	 if ((code == 100 || code == 101) || (code >= 200 && code <= 206) || (code >= 300 && code <= 307) || (code >= 400 && code <= 417) || (code >= 500 && code <= 505))
	 	return true;
	 else
	 	return false;
}

std::string HttpStatusCode::wordCode( void) 
{
	return this->_map[this->_code];
}


//Inizialating static variables
std::map<HttpStatusCode::Code, std::string> HttpStatusCode::_map = initMap();

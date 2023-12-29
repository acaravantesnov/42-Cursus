#ifndef HTTPSTATUSCODE_HPP
# define HTTPSTATUSCODE_HPP

# include <string>
# include <map>
# include <cstdlib>

class HttpStatusCode {

	
	public:
		enum Code {

			// 1xx Informational
			CONTINUE = 100,
			SWITCHING_PROTOCOLS = 101,

			// 2xx Success
			OK = 200, //
			CREATED = 201,
			ACCEPTED = 202,
			NON_AUTHORITATIVE_INFORMATION = 203,
			NO_CONTENT = 204,
			RESET_CONTENT = 205,
			PARTIAL_CONTENT = 206,

			// 3xx Redirection
			MULTIPLE_CHOICES = 300,
			MOVED_PERMANENTLY = 301,
			FOUND = 302,
			SEE_OTHER = 303,
			NOT_MODIFIED = 304,
			USE_PROXY = 305,
			UNUSED = 306,
			TEMPORARY_REDIRECT = 307,

			// 4xx Client Error
			BAD_REQUEST = 400,
			UNAUTHORIZED = 401,
			PAYMENT_REQUIRED = 402,
			FORBIDDEN = 403,
			NOT_FOUND = 404,
			METHOD_NOT_ALLOWED = 405,
			NOT_ACCEPTABLE = 406,
			PROXY_AUTHENTICATION_REQUIERED = 407,
			REQUEST_TIMEOUT = 408,
			CONFLICT = 409,
			GONE = 410,
			LENGTH_REQUIRED = 411,
			PRECONDITION_FAILED = 412,
			REQUEST_ENTITY_TOO_LARGE = 413,
			REQUEST_URL_TOO_LONG = 414,
			UNSUPORTED_MEDIA_TYPE = 415,
			REQUEST_RANGE_NOT_SATISFABLE = 416,
			EXPECTATION_FAILED = 417,

			// 5xx Server Error
			INTERNAL_SERVER_ERROR = 500,
			NOT_IMPLEMENTED = 501,
			BAD_GATEWAY = 502,
			SERVICE_UNAVAILABLE = 503,
			GATEWAY_TIMEOUT = 504,
			HTTP_VERSION_NOT_SUPPORTED = 505
		};

		HttpStatusCode();
		HttpStatusCode(HttpStatusCode & stc);
		HttpStatusCode & operator=(HttpStatusCode & stc);
		~HttpStatusCode();
		bool isValid(int code);
		std::string wordCode( void );
		void set(int code);
		void set(const std::string code);
		void set(const HttpStatusCode::Code code);
		HttpStatusCode::Code const & getCode( void ) const;
		bool operator==(const  HttpStatusCode & stc);
		bool operator!=(const HttpStatusCode & stc);

		private:
			HttpStatusCode::Code _code;
			static std::map<HttpStatusCode::Code, std::string> _map;


};

#endif

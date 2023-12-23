#ifndef HTTPHEADER_HPP
# define HTTPHEADER_HPP

/******************************************************/
/* 		Header Example			      */
/******************************************************/
/*                                                    */
/*   HTTP/1.1 200 OK                                  */
/*   Date: Mon, 27 Jul 2009 12:28:53 GMT              */
/*   Server: Apache/2.2.14 (Win32)                    */
/*   Last-Modified: Wed, 22 Jul 2009 19:15:56 GMT     */
/*   Content-Length: 88                               */
/*   Content-Type: text/html                          */
/*   Connection: Closed                               */
/*						      */		
/******************************************************/

# include <string>
# include <ctime>
# include "HttpStatusCode.hpp"
# include "Config.hpp"
# include "HttpLogic.hpp"

class HttpHeader {

	private:	
		std::vector<char> _header;

	public:
		HttpHeader();
		HttpHeader(HttpHeader & hdr);
		HttpHeader & operator=(HttpHeader & hdr);
		~HttpHeader();
		std::vector<char> & get( void );
		std::string getTime( void );
		void buildHeader(const ConfigObject & config, HttpStatusCode & stc, unsigned int bytes);
		void buildLine(HttpStatusCode & stc);
		void redirectHeader(HttpStatusCode & stc, const std::string uri_path);
			// RequestData + Resolution (StatusCode)
			// getTime();
			// ServerName
			// getTimeOfFile();
			// _bytes entra por parametro
			// RequestData
			// Always Closed
};

#endif

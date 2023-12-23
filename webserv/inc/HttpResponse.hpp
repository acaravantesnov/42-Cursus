#ifndef HTTPRESPONSE_HPP
# define HTTPRESPONSE_HPP

# include <string>
# include <dirent.h>
# include <unistd.h>
# include <fstream>
# include "HttpHeader.hpp"
# include "HttpStatusCode.hpp"
# include "Config.hpp"
# include "Utils.hpp"
# include "HttpLogic.hpp"

class HttpResponse {

	private:
		HttpResponse();
		HttpResponse(HttpResponse & res);
		HttpResponse & operator=(HttpResponse & res);
		~HttpResponse();

	public:
		static int readFile(const std::string & file_path, std::vector<char> *content);
		static std::string get_relative_path(std::string root, std::string file_path);
		static int index_generator(const std::string & file_path, std::vector<char> *index, std::string root);
		static std::vector<char> file_response(const HttpRequest & req, const std::string & file_path, const ConfigObject & config);
		static std::vector<char> cgi_response(const HttpRequest & request, const std::vector<char> & cgi_content, int childStatus, const ConfigObject & config);
		static std::vector<char> general_response(const HttpRequest & req, unsigned int code, const ConfigObject & config);
		static std::vector<char> autoindex_response(const HttpRequest & req, const std::string & file_path, const ConfigObject & config);
		static std::vector<char> basic_html(HttpStatusCode & stc);
		static std::vector<char> redirect_response(const HttpRequest & req, const ConfigObject & config);
};

#endif

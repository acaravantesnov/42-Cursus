#include "../inc/HttpResponse.hpp"

int HttpResponse::readFile(const std::string & file_path, std::vector<char> *content)
{
	unsigned int bytes;
	char	buffer;

	std::ifstream input(file_path.c_str());
	if (!input.good())
		return -1;
	bytes = 0;
	content->clear();
	while (input.read(&buffer, 1))
	{
		bytes++;
		(*content).push_back(buffer);
	}
	return bytes;
}

std::vector<char> HttpResponse::basic_html(HttpStatusCode & stc)
{
	std::string html;
	std::string code;

	code = Utils::uint_to_string(static_cast<unsigned int>(stc.getCode()));

	html = "<!DOCTYPE html>\n";
	html += "<html>\n";
	html += "\t<head>\n";
	html += "\t\t<title>" + code + " - " + stc.wordCode() + "</title>\n";
	html += "\t</head>\n";
	html += "\t<body>\n";
	html += "\t\t<h1><center>" + code + "</center></h1>\n";
	html += "\t\t<p><center>" + stc.wordCode() + "</center></p>\n";
	html += "\t</body>\n";
	html += "</html>\n";

	return Utils::stringToVector(html);
}

std::string HttpResponse::get_relative_path(std::string root, std::string file_path)
{
	int pos = file_path.compare(root);

	for (size_t i = 0; i < root.size(); i++)
	{
		//std::cout << file_path.at(i) << " = " << root.at(i) << std::endl;
		if (file_path.at(i) != root.at(i))
		{
			pos = i;
			break ;
		}
	}
	std::string ret = file_path.substr(pos);
	if (ret.at(ret.size() - 1) != '/')
		ret.push_back('/');

	return ret;
}

int HttpResponse::index_generator(const std::string & file_path, std::vector<char> *index, std::string root)
{
	DIR *dr;
	struct dirent *en;
	std::string relative_path;
	//std::cout << "Path index= " << file_path << std::endl;

	dr = opendir(file_path.c_str());
	if (dr == NULL)
		return -1;

	relative_path = HttpResponse::get_relative_path(root, file_path);
	std::string html;
	html = "<!DOCTYPE html>\n";
	html += "<html>\n";
	html += "\t<head>\n";
	html += "\t\t<title>" + file_path + "</title>\n";
	html += "\t</head>\n";
	html += "\t<body>\n";
	html += "\t\t<h1><center> INDEX </center></h1>\n";
	html += "\t\t<p><center>(" + file_path + ")</center></p>\n";
	html += "\t\t<ul>\n";
	while ((en = readdir(dr)) != NULL)
		html += "\t\t\t<li><a href=\"" + relative_path + std::string(en->d_name) + "\">" + std::string(en->d_name) + "</a></li>\n";
	html += "\t\t</ul>\n";
	html += "\t</body>\n";
	html += "</html>\n";
	closedir(dr);

	(*index) = Utils::stringToVector(html);
	return html.size();
}

std::vector<char> HttpResponse::general_response(const HttpRequest & req, unsigned int code, const ConfigObject & config)
{
	//std::cout << "general_response" << std::endl;
	HttpHeader header;
	HttpStatusCode stc;
	int bytes;
	std::vector<char> content;
	std::string error_path;

	if (stc.isValid(code))
		stc.set(code);
	else
		return HttpResponse::general_response(req, 500, config);

	if ((error_path = HttpLogic::get_error_page_filepath(req, config, code)) != "")
	{
		bytes = HttpResponse::readFile(error_path, &content);
	}
	else
	{
		content = HttpResponse::basic_html(stc);
		bytes = content.size();
	}
	if (bytes < 0)
		return HttpResponse::general_response(req, 503, config);
	header.buildHeader(config, stc, bytes);
	std::vector<char> ret =  Utils::concat(header.get(), content);
	return ret;
}

std::vector<char> HttpResponse::file_response(const HttpRequest & req, const std::string & file_path, const ConfigObject & config)
{
	HttpHeader header;
	HttpStatusCode stc;
	long bytes;
	std::vector<char> content;

	stc.set(200);
	bytes = HttpResponse::readFile(file_path, &content);
	if (bytes < 0)
		return HttpResponse::general_response(req, 503, config);
	// if (HttpLogic::get_client_body_size(req, config) != -1 && bytes > HttpLogic::get_client_body_size(req, config) )
	// 	return HttpResponse::general_response(req, 400, config);
	header.buildHeader(config, stc, bytes);

	return Utils::concat(header.get(), content);
}

std::vector<char> HttpResponse::cgi_response(const HttpRequest & request, const std::vector<char> & cgi_content, int childStatus, const ConfigObject & config)
{
	HttpHeader 		header;
	HttpStatusCode 	stc;
	int 			value;
	std::string		cgi_content_str = Utils::vectorToString(cgi_content);

	size_t pos[2];
	if ((pos[0] = cgi_content_str.find("Status: ")) != std::string::npos) // Status is in cgi_content
	{
		if ((pos[1] = cgi_content_str.find('\n')) != std::string::npos)
			value = Utils::my_stoi(cgi_content_str.substr(pos[0] + 8, pos[1] - (pos[0] + 1)));
		else
			value = Utils::my_stoi(cgi_content_str.substr(pos[0] + 1));
	}
	else if (cgi_content.size() == 0) // Empty cgi response
        return (HttpResponse::general_response(request, 502, config)); // BAD_GATEWAY
	else
	{
		// 0 if returned well, 1 if it had an error
		if (childStatus == 0)
			value = 200;
		else
			return (HttpResponse::general_response(request, 502, config));
	}
	stc.set(value);
	header.buildLine(stc);
	return (header.get() + cgi_content);
}

std::vector<char> HttpResponse::autoindex_response(const HttpRequest & req, const std::string & file_path, const ConfigObject & config)
{
	HttpHeader header;
	HttpStatusCode stc;
	long bytes;
	std::vector<char> index;
	std::string root;

	stc.set(200);
	root = HttpLogic::get_file_root(req, config);
	bytes = HttpResponse::index_generator(file_path, &index, root);
	if (bytes < 0)
		return HttpResponse::general_response(req, 503, config);
	// if (HttpLogic::get_client_body_size(req, config) != -1 && bytes > HttpLogic::get_client_body_size(req, config) )
	// 	return HttpResponse::general_response(req, 400, config);
	header.buildHeader(config, stc, bytes);

	return Utils::concat(header.get(), index);
}

std::vector<char> HttpResponse::redirect_response(const HttpRequest & req, const ConfigObject & config)
{
	HttpHeader header;
	HttpStatusCode stc;
	long bytes;
	std::vector<char> content;
	std::pair<int, std::string> redir = HttpLogic::get_return(req, config);
	stc.set(redir.first);
	if (!(redir.second[0] == '\"' && redir.second[redir.second.size() - 1] == '\"'))
	{
		if (stc.getCode() < 300 || stc.getCode() > 307)
			return HttpResponse::general_response(req, 400, config);
		header.redirectHeader(stc, redir.second);
		return header.get();
	}
	content = Utils::stringToVector(redir.second.substr(1, redir.second.size() - 2));
	bytes = content.size();
	if (bytes < 0)
		return HttpResponse::general_response(req, 503, config);
	// if (HttpLogic::get_client_body_size(req, config) != -1 && bytes > HttpLogic::get_client_body_size(req, config) )
	// 	return HttpResponse::general_response(req, 400, config);
	header.buildHeader(config, stc, bytes);
	return Utils::concat(header.get(), content);
}

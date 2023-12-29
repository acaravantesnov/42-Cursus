#ifndef HTTPLOGIC_HPP
# define HTTPLOGIC_HPP

# include <algorithm>
# include <cctype>
# include <limits>
# include "HttpRequest.hpp"
# include "Config.hpp"
# include "Utils.hpp"

// Static class for the logic of the http server.
class	HttpLogic
{
	public:

		// Returns the ip of the server or 0.0.0.0 if not set.
		static std::vector<std::string> get_ips(const ConfigObject &constConfig);

		// Returns the port of the server or 80 (for HTTP) if not set.
		static std::vector<int> get_ports(const ConfigObject &constConfig);

		// Returns a vector containing all the host names, empty vector if none are provided.
		static std::vector<std::string> get_server_names(const ConfigObject &constConfig);

		// Returns location indexes (each index for each location level), empty vector if request does not belong to any location.
		static std::vector<int> check_location(const HttpRequest &request, const ConfigObject &constConfig);

		// Returns true if the request method is allowed.
		static bool check_type_permision(const HttpRequest &request, const ConfigObject &constConfig);

		// Returns the root used for the request (taking into account the locations).
		static std::string get_file_root(const HttpRequest &request, const ConfigObject &constConfig);

		// Builds and returns a newPath from originalPath taking root and alias into account (only useful for creating HttpLogic functions).
		static std::string build_path(std::string originalPath, const HttpRequest &request, const ConfigObject &constConfig);

		// Returns the file path for the request path (taking into account the locations).
		static std::string get_file_path(const HttpRequest &request, const ConfigObject &constConfig);

		// Returns true if autoindex is enabled for the request (taking into account the locations).
		static bool get_autoindex(const HttpRequest &request, const ConfigObject &constConfig);

		// Returns the client body size limit for the request (taking into account the locations) or -1 if not set.
		static long get_client_body_size(const HttpRequest &request, const ConfigObject &constConfig);

		// Returns the path of the index file for the request (taking into account the locations) or an empty string if not set.
		static std::string get_index_path(const HttpRequest &request, const ConfigObject &constConfig);

		// Returns the path for the error page for the request (taking into account the locations) or an empty string if not set.
		static std::string get_error_page_filepath(const HttpRequest &request, const ConfigObject &constConfig, int error_code);

		// Returns the return directive arguments if defined. Empty pair otherwise. First arg. is code, second is string (path for redirect, or "string" for explicit string return).
		static std::pair<int, std::string> get_return(const HttpRequest &request, const ConfigObject &constConfig);

		// key is extension (for example ".py"), value is the path to the executable. Inconsistencies or empty directives return empty map.
		static std::map<std::string, std::string> get_cgis(const HttpRequest &request, const ConfigObject &constConfig);

		// Returns path for the cgi to execute or empty string if not set.
		static std::string get_cgi_path(const HttpRequest &request, const ConfigObject &constConfig);

		// Returns vector of 2 dimensional arrays of cgi environment variables (cgi_param directive).
		static std::vector<std::pair<std::string, std::string> > get_cgi_env_vars(const HttpRequest &request, const ConfigObject &constConfig);

		// Returns true if the request is CGI.
		static bool is_cgi(const HttpRequest &request, const ConfigObject &constConfig);

		// Returns the config corresponding for the request out of the vecotr of configs. (takes into account the server_name).
		static ConfigObject get_config_from_vec(const HttpRequest &request, const std::vector<ConfigObject> &configs);

		// Out of the vector of configs, returns them in roups with the same ip and port
		static std::vector<std::vector<ConfigObject> > get_servers_by_listen(const std::vector<ConfigItem> &configs);
};

#endif

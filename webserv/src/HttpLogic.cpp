#include "HttpLogic.hpp"

std::vector<std::string> HttpLogic::get_ips(const ConfigObject &constConfig)
{
	size_t									colonPos;
	size_t									dotPos;
	std::vector<std::string>				ips;
	std::vector<ConfigItem>::const_iterator it;

	if ((constConfig["listen"].size() == 0) || (constConfig["listen"][0].get_value() == ""))
	{
		ips.push_back("0.0.0.0");
		return (ips);
	}
	for (it = constConfig["listen"].begin(); \
	it != constConfig["listen"].end(); it++)
	{
		colonPos = it->get_value().find(':');
		dotPos = it->get_value().find('.');
		if (dotPos != std::string::npos) // There is '.'
		{
			if (colonPos != std::string::npos) // There is ':'
				ips.push_back(it->get_value().substr(0, colonPos));
			else
				ips.push_back(it->get_value());
		}
		else
			ips.push_back("0.0.0.0");
	}
    return (ips);
}

std::vector<int> HttpLogic::get_ports(const ConfigObject &constConfig)
{
    size_t									colonPos;
	size_t									dotPos;
	std::vector<int>						ports;
	std::vector<ConfigItem>::const_iterator it;

	if ((constConfig["listen"].size() == 0) || (constConfig["listen"][0].get_value() == ""))
	{
		ports.push_back(80);
		return (ports);
	}
	for (it = constConfig["listen"].begin(); \
	it != constConfig["listen"].end(); it++)
	{
		colonPos = it->get_value().find(':');
		dotPos = it->get_value().find('.');
		if (colonPos != std::string::npos) // There is ':'
			ports.push_back(Utils::my_stoi(it->get_value().substr(colonPos + 1)));
		else if (dotPos != std::string::npos) // There is '.'
			ports.push_back(80);
		else
			ports.push_back(Utils::my_stoi(it->get_value()));
	}
    return (ports);
}

std::vector<std::string> HttpLogic::get_server_names(const ConfigObject &constConfig)
{
	std::vector<std::string>	server_names;
	std::string					auxStr;

	if (!constConfig.contains("server_name"))
		return(std::vector<std::string>());

	auxStr = constConfig["server_name"][0].get_value();
	while (auxStr.find(' ') != std::string::npos)
	{
		server_names.push_back(auxStr.substr(0, auxStr.find(' ') - 1));
		auxStr = auxStr.substr(auxStr.find(' ') + 1);
	}
	server_names.push_back(auxStr);
	return (server_names);
}

std::vector<int> HttpLogic::check_location(const HttpRequest &request, const ConfigObject &constConfig)
{
	ConfigObject		config(constConfig);
    std::vector<int>    retVector;
    std::string         requestPath, location;

    if (request.getPath() == "")
		return (std::vector<int> ());
	requestPath = (request.getPath()[0] == '/') ? request.getPath().substr(1) : (request.getPath());
    
	while ((requestPath.find('/') != std::string::npos) && (config.contains("location")))
    {
		location = requestPath.substr(0, requestPath.find('/'));
		size_t i;
		for (i = 0; i < config["location"].size(); i++)
		{
			std::string confLocation = config["location"][i].get_value();
			if (confLocation[0] == '/')
				confLocation = confLocation.substr(1);
			if (*(confLocation.end() - 1) == '/')
				confLocation = confLocation.substr(0, confLocation.length() - 1);
			if (confLocation == location)
			{
				retVector.push_back(i);
				config = config["location"][i].get_nonconst_subConfig();
				break;
			}
		}
		if (i == config["location"].size())
			return (retVector);
		requestPath = requestPath.substr(requestPath.find('/') + 1);
    }

	if ((requestPath.find('/') == std::string::npos) && (config.contains("location")))
	{
		location = requestPath;
		size_t i;
		for (i = 0; i < config["location"].size(); i++)
		{
			std::string confLocation = config["location"][i].get_value();
			if (confLocation[0] == '/')
				confLocation = confLocation.substr(1);
			if (*(confLocation.end() - 1) == '/')
				confLocation = confLocation.substr(0, confLocation.length() - 1);
			if (confLocation == location)
			{
				retVector.push_back(i);
				config = config["location"][i].get_nonconst_subConfig();
				break;
			}
		}
		if (i == config["location"].size())
			return (retVector);
		requestPath = requestPath.substr(requestPath.find('/') + 1);
	}
	return (retVector);
}



bool HttpLogic::check_type_permision(const HttpRequest &request, const ConfigObject &constConfig)
{
	ConfigObject				config(constConfig);
	std::vector<std::string>	serverRequestTypes; // GET, POST, DELETE
	std::vector<int>			locationIndexes = check_location(request, constConfig);
	std::string					possibleMethods[3] = {"GET", "POST", "DELETE"};

	if (config.contains("allow_methods"))
	{
		for (size_t i = 0; i < config["allow_methods"].size(); i++)
		{
			std::string temp = config["allow_methods"][i].get_value();
			while (temp.find(' ') != std::string::npos)
			{
				std::string method = temp.substr(0, temp.find(' '));
				for (size_t n = 0; n < 3; n++)
					if (method == possibleMethods[n])
						serverRequestTypes.push_back(method);
				temp = temp.substr(temp.find(' ') + 1);
			}
			for (size_t n = 0; n < 3; n++)
				if (temp == possibleMethods[n])
					serverRequestTypes.push_back(temp);
		}
	}

	for (size_t i = 0; i < locationIndexes.size(); i++)
	{
		if (config["location"][locationIndexes[i]].get_nonconst_subConfig().contains("allow_methods"))
		{
			for (size_t j = 0; j < config["location"][locationIndexes[i]]["allow_methods"].size(); j++)
			{
				std::string temp = config["location"][locationIndexes[i]]["allow_methods"][j].get_value();
				while (temp.find(' ') != std::string::npos)
				{
					std::string method = temp.substr(0, temp.find(' '));
					for (size_t n = 0; n < 3; n++)
						if (method == possibleMethods[n])
							serverRequestTypes.push_back(method);
					temp = temp.substr(temp.find(' ') + 1);
				}
				for (size_t n = 0; n < 3; n++)
					if (temp == possibleMethods[n])
						serverRequestTypes.push_back(temp);
			}
		}
		config = config["location"][locationIndexes[i]].get_nonconst_subConfig();
	}

	for (size_t i = 0; i < serverRequestTypes.size(); i++)
	{
		if (((request.getType() == 0) && (serverRequestTypes.at(i) == "GET")) || \
		((request.getType() == 1) && (serverRequestTypes.at(i) == "POST")) || \
		((request.getType() == 2) && (serverRequestTypes.at(i) == "DELETE")))
			return (true);
	}
	return (false);
}

std::string HttpLogic::get_file_root(const HttpRequest &request, const ConfigObject &constConfig)
{
	ConfigObject		config(constConfig);
	std::string			rootDir = "/";
	std::vector<int>	locationIndexes = check_location(request, constConfig);

	if (config.contains("root"))
		rootDir = config["root"][0].get_value();

	for (size_t i = 0; i < locationIndexes.size(); i++)
	{
		if (config["location"][locationIndexes[i]].get_subConfig().contains("root"))
			rootDir = config["location"][locationIndexes[i]]["root"][0].get_value();
		config = config["location"][locationIndexes[i]].get_nonconst_subConfig();
	}
	return (rootDir);
}

std::string HttpLogic::build_path(std::string originalPath, const HttpRequest &request, const ConfigObject &constConfig)
{
	ConfigObject		config(constConfig);
	std::vector<int>	locationIndexes = check_location(request, constConfig);
	std::string			rootPath = get_file_root(request, constConfig);
	std::string			newPath;

	if ((*(rootPath.end() - 1) != '/') && (*(originalPath.end() - 1) != '/'))
		newPath = rootPath + '/' + originalPath;
	else
		newPath = rootPath + originalPath;

	std::string locationStr, aliasStr;
	for (size_t i = 0; i < locationIndexes.size(); i++)
	{
		if (config["location"][locationIndexes[i]].get_subConfig().contains("alias"))
		{
			locationStr = "", aliasStr = "";
			if (config["location"][locationIndexes[i]].get_value()[0] != '/')
				locationStr = '/';
			locationStr += config["location"][locationIndexes[i]].get_value();
			aliasStr = config["location"][locationIndexes[i]]["alias"][0].get_value();
			size_t found;
			if ((found = newPath.find(locationStr)) != std::string::npos)
				newPath.replace(found + 1, locationStr.length() - 1, aliasStr);
		}
		config = config["location"][locationIndexes[i]].get_nonconst_subConfig();
	}

	for (size_t i = 0; i < newPath.length() - 1; i++) // Check for // in the path.
		if ((newPath[i] == '/') && (newPath[i + 1] == '/'))
			newPath.erase(i, 1);
    return (newPath);
}


std::string HttpLogic::get_file_path(const HttpRequest &request, const ConfigObject &constConfig)
{
	return (Utils::clean_path(build_path(request.getPath(), request, constConfig)));
}

bool HttpLogic::get_autoindex(const HttpRequest &request, const ConfigObject &constConfig)
{
	ConfigObject		config(constConfig);
	std::string			temp;
	std::vector<int>	locationIndexes = check_location(request, constConfig);

	if (locationIndexes.size() > 0) // Its a location
	{
		for(size_t i = 0; i < locationIndexes.size(); i++)
			config = config["location"][locationIndexes[i]].get_nonconst_subConfig();
		if (config.contains("autoindex"))
			return ((config["autoindex"][0].get_value() == "on") ? true : false);
	}
	if (constConfig.contains("autoindex"))
		return ((constConfig["autoindex"][0].get_value() == "on") ? true : false);
	return (false);
}

long HttpLogic::get_client_body_size(const HttpRequest &request, const ConfigObject &constConfig)
{
	ConfigObject		config(constConfig);
    std::string			body_size = "";
	std::vector<int>	locationIndexes = check_location(request, constConfig);

	if (config.contains("client_max_body_size"))
		body_size = config["client_max_body_size"][0].get_value();
	
	for(size_t i = 0; i < locationIndexes.size(); i++)
	{
		if (config["location"][locationIndexes[i]].get_subConfig().contains("client_max_body_size"))
			body_size = config["location"][locationIndexes[i]]["client_max_body_size"][0].get_value();
		config = config["location"][locationIndexes[i]].get_nonconst_subConfig();
	}

	if (body_size == "")
		return (-1);
	
	std::string digits = "", zeroStr = "";
	for (size_t i = 0; i < body_size.size(); i++)
	{
		if (isdigit(body_size[i]))
			digits += body_size[i];
		else if (body_size[i] == 'K') // Current char is a letter
			zeroStr += "000";
		else if (body_size[i] == 'M')
			zeroStr += "000000";
		else if (body_size[i] == 'G')
			zeroStr += "000000000";
	}
	if (digits.size() == 0)
		return (std::numeric_limits<long>::max());
	if (Utils::my_stol(digits) == 0)
		return (0);
	// if (zeroStr.size() == 0)
	// 	return (std::numeric_limits<long>::max());
	if (((Utils::my_stol(digits + zeroStr)) < std::numeric_limits<long>::max()) && ((Utils::my_stol(digits + zeroStr)) > 0))
		return (Utils::my_stol(digits + zeroStr));
	return (std::numeric_limits<long>::max());

}

std::string HttpLogic::get_index_path(const HttpRequest &request, const ConfigObject &constConfig)
{
	ConfigObject		config(constConfig);
    std::vector<int>	locationIndexes;
	std::string			indexPath;

	if (config.contains("index"))
		indexPath = config["index"][0].get_value();
	else
		indexPath = "";
	locationIndexes = check_location(request, config);
	if (locationIndexes.size() == 0)
		return (Utils::clean_path(indexPath));
	int lastLevel = -1;
	for (size_t i = 0; i < locationIndexes.size(); i++)
	{
		if (config["location"][locationIndexes[i]].get_subConfig().contains("index"))
		{
			indexPath = config["location"][locationIndexes[i]]["index"][0].get_value();
			lastLevel = i;
		}
		config = config["location"][locationIndexes[i]].get_nonconst_subConfig();
	}
	config = constConfig;
	std::string locs = "";
	if (lastLevel != -1)
	{
		for (int i = 0; i <= lastLevel; i++)
		{
			locs += config["location"][locationIndexes[i]].get_value();
			config = config["location"][locationIndexes[i]].get_nonconst_subConfig();
		}
		if (*(locs.end() - 1) != '/')
			locs += '/';
		return (Utils::clean_path(build_path(locs + indexPath, request, constConfig)));
	}
	return (Utils::clean_path(build_path(indexPath, request, constConfig)));
}

std::string HttpLogic::get_error_page_filepath(const HttpRequest &request, const ConfigObject &constConfig, int errorCode)
{
	ConfigObject		config(constConfig);
    std::vector<int>	locationIndexes = check_location(request, constConfig);
	std::string			errorPageFilepath = "";
	
	if (!((errorCode >= 400 && errorCode <= 417) || (errorCode >= 500 && errorCode <= 505)))
			return errorPageFilepath;

	if (config.contains("error_page"))
	{
		for (size_t i = 0; i < config["error_page"].size(); i++)
		{
			std::string temp = config["error_page"][i].get_value();
			while (temp.find(' ') != std::string::npos)
			{
				if (errorCode == Utils::my_stoi(temp.substr(0, temp.find(' '))))
					errorPageFilepath = temp.substr(temp.find_last_of(' ') + 1);
				temp = temp.substr(temp.find(' ') + 1);
			}
		}
	}
	else if (locationIndexes.size() == 0)
		return (std::string(""));
	std::string locationPath = "", saveLocationPath = "";
	for (size_t i = 0; i < locationIndexes.size(); i++)
	{
		locationPath += config["location"][locationIndexes[i]].get_value();
		if (config["location"][locationIndexes[i]].get_subConfig().contains("error_page"))
		{
			for (size_t j = 0; j < config["location"][locationIndexes[i]]["error_page"].size(); j++)
			{
				std::string temp = config["location"][locationIndexes[i]]["error_page"][j].get_value();
				while (temp.find(' ') != std::string::npos)
				{
					if (errorCode == Utils::my_stoi(temp.substr(0, temp.find(' '))))
					{
						errorPageFilepath = temp.substr(temp.find_last_of(' ') + 1);
						saveLocationPath = locationPath;
					}
					temp = temp.substr(temp.find(' ') + 1);
				}
			}
		}
		config = config["location"][locationIndexes[i]].get_nonconst_subConfig();
	}
	if (errorPageFilepath == "")
		return (std::string(""));
	if (saveLocationPath == "")
		return (Utils::clean_path(get_file_root(request, constConfig) + errorPageFilepath));
	return (Utils::clean_path(build_path(saveLocationPath + errorPageFilepath, request, constConfig)));
}

std::pair<int, std::string> HttpLogic::get_return(const HttpRequest &request, const ConfigObject &constConfig)
{
	ConfigObject				config(constConfig);
	std::vector<int>			locationIndexes = check_location(request, constConfig);
	std::pair<int, std::string> retPair(-1, "");

	if (config.contains("return"))
	{
		std::string value = config["return"][0].get_value();
		value = Utils::trim(value);
		if (std::count(value.begin(), value.end(), ' ') > 0){
			retPair.first = Utils::my_stoi(value.substr(0, value.find(' ')));
			retPair.second = value.substr(value.find(' ') + 1);
		}
	}

	if (locationIndexes.size() != 0) // Belongs to a location
	{
		for(size_t i = 0; i < locationIndexes.size(); i++)
		{
			if (config["location"][locationIndexes[i]].get_subConfig().contains("return"))
			{
				std::string value = config["location"][locationIndexes[i]]["return"][0].get_value();
				value = Utils::trim(value);
				if (std::count(value.begin(), value.end(), ' ') > 0)
				{
					retPair.first = Utils::my_stoi(value.substr(0, value.find(' ')));
					retPair.second = value.substr(value.find(' ') + 1);
				}
			}
			config = config["location"][locationIndexes[i]].get_nonconst_subConfig();
		}
	}

	return (retPair);
}

std::map<std::string, std::string> HttpLogic::get_cgis(const HttpRequest &request, const ConfigObject &constConfig)
{
	ConfigObject						config(constConfig);
	std::vector<int>					locationIndexes = check_location(request, config);
	std::map<std::string, std::string>	cgis;

	if (locationIndexes.size() == 0)
		return (std::map<std::string, std::string>());
	for (size_t i = 0; i < locationIndexes.size(); i++)
	{
		if (config["location"][locationIndexes[i]].get_subConfig().contains("cgi_path") && \
		config["location"][locationIndexes[i]].get_subConfig().contains("cgi_extension"))
		{
			// Check same # of elements. If not, return empty map.
			std::string pathValue = config["location"][locationIndexes[i]]["cgi_path"][0].get_value();
			std::string extensionValue = config["location"][locationIndexes[i]]["cgi_extension"][0].get_value();
			size_t		nPathValues = (pathValue != "") ? std::count(pathValue.begin(), pathValue.end(), ' ') + 1 : 0;
			size_t		nExtensionValues = (extensionValue != "") ? std::count(extensionValue.begin(), extensionValue.end(), ' ') + 1 : 0;
			if (nPathValues != nExtensionValues)
				return (std::map<std::string, std::string>());
			// Create map.
			while (pathValue.find(' ') != std::string::npos)
			{
				cgis[extensionValue.substr(0, extensionValue.find(' '))] = pathValue.substr(0, pathValue.find(' '));
				pathValue = pathValue.substr(pathValue.find(' ') + 1);
				extensionValue = extensionValue.substr(extensionValue.find(' ') + 1);
			}
			cgis[extensionValue] = pathValue;
		}
		config = config["location"][locationIndexes[i]].get_nonconst_subConfig();
	}
	return (cgis);
}

std::string	HttpLogic::get_cgi_path(const HttpRequest &request, const ConfigObject &constConfig)
{
	ConfigObject						config(constConfig);
	std::vector<int>					locationIndexes = check_location(request, constConfig);
	std::map<std::string, std::string> 	cgis;
	
	std::string auxStr = request.getPath();
	while (auxStr.find('/') != std::string::npos)
		auxStr = auxStr.substr(auxStr.find('/') + 1);
	if (auxStr.find('.') != std::string::npos)
	{
		cgis = get_cgis(request, constConfig);
		if (cgis.find(auxStr.substr(auxStr.find('.'))) != cgis.end())
			return (Utils::clean_path(cgis[auxStr.substr(auxStr.find('.'))]));
		return ("");
	}
	return ("");
}

std::vector<std::pair<std::string, std::string> >	HttpLogic::get_cgi_env_vars(const HttpRequest &request, const ConfigObject &constConfig)
{
	ConfigObject										config(constConfig);
	std::vector<int>									locationIndexes = check_location(request, constConfig);
	std::vector<std::pair<std::string, std::string> >	envVars;

	for (size_t i = 0; i < locationIndexes.size(); i++)
	{
		if (config["location"][locationIndexes[i]].get_subConfig().contains("cgi_param"))
		{
			for (size_t j = 0; j < config["location"][locationIndexes[i]]["cgi_param"].size(); j++)
			{
				std::string valueStr = config["location"][locationIndexes[i]]["cgi_param"][j].get_value();
				if (std::count(valueStr.begin(), valueStr.end(), ' ') == 1)
					envVars.push_back(std::make_pair(valueStr.substr(0, valueStr.find(' ')), \
					valueStr.substr(valueStr.find(' ') + 1)));
			}
		}
	}
	return (envVars);
}

bool HttpLogic::is_cgi(const HttpRequest &request, const ConfigObject &constConfig)
{
	std::string file_path = HttpLogic::get_file_path(request, constConfig);
	
    if (file_path.find("/cgi-bin") != std::string::npos)
		return (true);
	return (false);
}

// Returns the config corresponding for the request out of the vecotr of configs. (takes into account the server_name).
ConfigObject HttpLogic::get_config_from_vec(const HttpRequest &request, const std::vector<ConfigObject> &configs)
{
	std::vector<std::string>	server_names;
	std::string					auxStr;

	if (configs.size() == 1)
		return (configs[0]);
	for (size_t i = 0; i < configs.size(); i++)
	{
		if (configs[i].contains("server_name"))
			if (get_server_names(configs[i])[0] == request.getHost())
				return (configs[i]);
	}
	return (configs[0]);
}

// Out of the vector of configs, returns them in roups with the same ip and port
std::vector<std::vector<ConfigObject> > HttpLogic::get_servers_by_listen(const std::vector<ConfigItem> &configs)
{
	std::vector<std::vector<ConfigObject> >	retVector;
	for (size_t i = 0; i < configs.size(); i++)
	{
		// Check if the ip and port are already in the vector.
		bool found = false;
		for (size_t j = 0; j < retVector.size(); j++)
		{
			//if ((retVector[j][0]["listen"][0].get_value() == configs[i]["listen"][0].get_value()))
			if (get_ips(retVector[j][0])[0] == get_ips(configs[i].get_subConfig())[0] && 
			get_ports(retVector[j][0])[0] == get_ports(configs[i].get_subConfig())[0])
			{
				retVector[j].push_back(configs[i].get_subConfig());
				found = true;
				break;
			}
		}
		if (!found)
		{
			std::vector<ConfigObject> temp;
			temp.push_back(configs[i].get_subConfig());
			retVector.push_back(temp);
		}
	}
	//validate the vector of vectors of configs. It there are more thann one with the same port throw an exception.
	std::vector<int> used_ports;
	for (size_t i = 0; i < retVector.size(); i++)
	{
		if (retVector[i].size() > 0)
		{
			if (std::find(used_ports.begin(), used_ports.end(), get_ports(retVector[i][0])[0]) != used_ports.end())
				throw std::runtime_error("There are more than one server listening on the same port: " + Utils::uint_to_string(get_ports(retVector[i][0])[0]));
			used_ports.push_back(get_ports(retVector[i][0])[0]);
		}
	}
	return (retVector);
}

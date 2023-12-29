#include "Config.hpp"

ConfigObject::ConfigObject(const ConfigObject& other) {
    *this = other;
}

ConfigObject::ConfigObject() {}

ConfigObject::~ConfigObject() {}

ConfigObject& ConfigObject::operator=(const ConfigObject& other) {
    if (this == &other)
        return *this;
    _config = other._config;
    return *this;
}

ConfigObject::ConfigObject(std::string filename) {
    std::ifstream in(filename.c_str());
    if (!in.is_open()) {
        throw ConfigParsingException("Could not open file: " + filename);
    }
    parseConfig_withoutBrakets(in);
    if (!in.eof()) {
        throw ConfigParsingException("Expected EOF at end of config, got: " + std::string(1, in.peek()) + " instead");
    }
}

ConfigObject::ConfigObject(std::istream& in) {
    parseConfig(in);
}

const std::map<std::string, std::vector<ConfigItem> >& ConfigObject::get_config() const {
    return _config;
}

const std::vector<ConfigItem>& ConfigObject::operator[](std::string key) const {
    //return _config[key];
    return _config.find(key)->second;
}

void ConfigObject::skipWhitespace(std::istream& in) {
    char c;
    c = in.peek();
    while (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
        in.get();
        c = in.peek();
    }
}

void ConfigObject::skipWhitespace(std::istream& in, bool skip_newline) {
    char c;
    c = in.peek();
    while (c == ' ' || c == '\t' || (skip_newline && (c == '\n' || c == '\r'))) {
        in.get();
        c = in.peek();
    }
}

void ConfigObject::parseConfig(std::istream& in) {
    skipWhitespace(in);
    if (in.peek() != '{') {
        throw ConfigParsingException("Expected '{' at start of config");
    }
    in.get();
    parseConfig_withoutBrakets(in);
    if (in.peek() != '}') {
        throw ConfigParsingException("Expected '}' at end of config");
    }
    in.get();
}

//parse configItems until we find a '}' or EOF
void ConfigObject::parseConfig_withoutBrakets(std::istream& in) {
    char c;
    c = in.peek();
    while (!in.eof() && c != '}') {
        ConfigItem item(in);
        //std::cout << "key: |" << item.get_key() << "| value: |" << item.get_value() << "|" << std::endl;
        //std::cout << "a" << std::endl;
        _config[item.get_key()].push_back(item);
        //std::cout << "key: |" << item.get_key() << "| value: |" << item.get_value() << "|" << std::endl;
        //std::cout << item;
        //std::cout << item.get_value() << std::endl;
        skipWhitespace(in);
        c = in.peek();
    }
}

bool ConfigObject::contains(std::string key) const {
    return _config.find(key) != _config.end();
}

ConfigItem::ConfigItem(const ConfigItem& other) {
    *this = other;
}

ConfigItem::ConfigItem() {}

ConfigItem::~ConfigItem() {}

ConfigItem& ConfigItem::operator=(const ConfigItem& other) {
    if (this == &other)
        return *this;
    _value = other._value;
    _subConfig = other._subConfig;
    _isSubConfigUsed = other._isSubConfigUsed;
    _isValueUsed = other._isValueUsed;
    return *this;
}

ConfigItem::ConfigItem(std::istream& in) {
    parseItem(in);
    _key = Utils::trim(_key);
    _value = Utils::trim(_value);
    //std::cout << "key: |" << _key << "| value: |" << _value << "|" << std::endl;
}

const std::string& ConfigItem::get_value() const {
    return _value;
}

const ConfigObject& ConfigItem::get_subConfig() const {
    return _subConfig;
}

ConfigObject ConfigItem::get_nonconst_subConfig() const {
    return _subConfig;
}

const std::string& ConfigItem::get_key() const {
    return _key;
}

bool ConfigItem::get_isSubConfigUsed() const {
    return _isSubConfigUsed;
}

bool ConfigItem::get_isValueUsed() const {
    return _isValueUsed;
}

void ConfigItem::skipWhitespace(std::istream& in) {
    char c;
    c = in.peek();
    while (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
        in.get();
        c = in.peek();
    }
}

//format is:    key value;
//or:           key { subconfig}
//or:           key value { subconfig } //I think this is only on location
void ConfigItem::parseItem(std::istream& in) {
    skipWhitespace(in);
    _key = "";
    while (in.peek() != ' ' && in.peek() != '\t' && in.peek() != '{' && in.peek() != ';')
        _key.push_back(in.get());
        //_key += std::string(1, in.get());
    skipWhitespace(in);
    _value = "";
    while (in.peek() != '{' && in.peek() != ';' && !in.eof() && in.peek() != '\n' && in.peek() != '\r')
    {
        _value.push_back(in.get());
        //_value += std::string(1, in.get());
    }
    //std::cout << "key: |" << _key << "| value: |" << _value << "|" << std::endl;
    if (in.peek() == '\n' || in.peek() == '\r')
        throw ConfigParsingException("Expected ';' or '{' after value");
    if (in.peek() == ';')
    {
        in.get();
        _isSubConfigUsed = false;
        return;
    }
    else if (in.peek() == '{')
    {
        _subConfig = ConfigObject(in);
        _isSubConfigUsed = true;
        skipWhitespace(in);
    }
    else
    {
        throw ConfigParsingException("Expected '{' or ';' after value");
    }
}

const std::vector<ConfigItem>& ConfigItem::operator[](std::string key) const {
    return _subConfig[key];
}


std::ostream& operator<<(std::ostream& out, const ConfigObject& config) {
    out << "{" << std::endl;
    for (std::map<std::string, std::vector<ConfigItem> >::const_iterator it = config.get_config().begin(); it != config.get_config().end(); ++it) {
        for (std::vector<ConfigItem>::const_iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
            out << it->first << *it2 << std::endl;
        }
    }
    out << "}" << std::endl;
    return out;
}

std::ostream& operator<<(std::ostream& out, const ConfigItem& item) {
    out << item.get_key() << " ";
    if (item.get_isValueUsed()) {
        out << item.get_value() << " ";
    }
    if (item.get_isSubConfigUsed()) {
        out << item.get_subConfig();
    }
    return out;
}


void ConfigObject::validateConfig() const 
{
    // Check for at least one server at the top level
    ConfigObject::const_config_iterator servers = _config.find("server");
    if (servers == _config.end() || servers->second.empty()) {
        throw std::runtime_error("Configuration must have at least one server");
    }
    std::set<std::string> serverNames;

    for (std::vector<ConfigItem>::const_iterator serverIter = servers->second.begin(); serverIter != servers->second.end(); ++serverIter) {
        validateServer(serverIter->get_subConfig(), serverNames); //This inserts the server name into serverNames
    }
}

void ConfigObject::validateServer(const ConfigObject& server, std::set<std::string>& serverNames) const
{
    // Check for server_name uniqueness
    if (!server.contains("server_name")) {
        throw std::runtime_error("Server must have a server_name");
    }
    std::string serverName = server["server_name"][0].get_value();
    if (serverNames.find(serverName) != serverNames.end()) {
        throw std::runtime_error("Duplicate server_name found: " + serverName);
    }
    serverNames.insert(serverName);

    // Check for valid configurations inside a server
    std::string validServerConfigsString = "server_name listen root index allow_methods client_max_body_size error_page autoindex location return";
    std::vector<std::string> validServerConfigs = Utils::split(validServerConfigsString, " ");
    for (ConfigObject::const_config_iterator config = server.get_config().begin(); config != server.get_config().end(); ++config) {
        if (std::find(validServerConfigs.begin(), validServerConfigs.end(), config->first) == validServerConfigs.end()) {
            throw std::runtime_error("Invalid server configuration: " + config->first);
        }

        // Additional checks for locations
        if (config->first == "location") {
            for (std::vector<ConfigItem>::const_iterator location = config->second.begin(); location != config->second.end(); ++location) {
                validateLocation(location->get_subConfig(), location->get_value());
            }
        }

        if (config->first == "listen") {
            validateListenValue(config->second[0].get_value());
        }
    }

    // Check for configs that can cannot be used more than once
    std::string uniqueConfigsString = "server_name listen root index client_max_body_size return";
    std::vector<std::string> uniqueConfigs = Utils::split(uniqueConfigsString, " ");
    for (std::vector<std::string>::iterator uniqueConfig = uniqueConfigs.begin(); uniqueConfig != uniqueConfigs.end(); ++uniqueConfig) {
        if (server.contains(*uniqueConfig) && server[*uniqueConfig].size() > 1) {
            throw std::runtime_error("Server configuration can only be used once: " + *uniqueConfig);
        }
    }

    // Check for configs that must be used at least once
    std::string requiredConfigsString = "server_name listen root";
    std::vector<std::string> requiredConfigs = Utils::split(requiredConfigsString, " ");
    for (std::vector<std::string>::iterator requiredConfig = requiredConfigs.begin(); requiredConfig != requiredConfigs.end(); ++requiredConfig) {
        if (!server.contains(*requiredConfig)) {
            throw std::runtime_error("Server configuration must be used at least once: " + *requiredConfig);
        }
    }

    // Check for configs that must have some value
    std::string requiredValueConfigsString = "server_name root index autoindex location return client_max_body_size error_page allow_methods";
    std::vector<std::string> requiredValueConfigs = Utils::split(requiredValueConfigsString, " ");
    for (std::vector<std::string>::iterator requiredValueConfig = requiredValueConfigs.begin(); requiredValueConfig != requiredValueConfigs.end(); ++requiredValueConfig) {
        if (server.contains(*requiredValueConfig) && server[*requiredValueConfig][0].get_value().empty()) {
            throw std::runtime_error("Server configuration must have a value: " + *requiredValueConfig);
        }
    }
}

void ConfigObject::validateLocation(const ConfigObject& location, std::string value) const
{
    // Check for * in location value
    if (value.find('*') != std::string::npos) {
        throw std::runtime_error("Location value should not contain '*': " + value);
    }

    // Check for empty location value
    if (value.empty())
        throw std::runtime_error("Location value should not be empty");

    // location value should start with a /
    if (value[0] != '/')
        throw std::runtime_error("Location value should start with a '/': " + value);

    // Validate configurations inside location
    std::string validLocationConfigsString = "root index allow_methods client_max_body_size error_page alias autoindex location return";
    std::vector<std::string> validLocationConfigs = Utils::split(validLocationConfigsString, " ");
    if (value == "/cgi-bin" || value == "/cgi-bin/")
    {
        std::string validCgiConfigsString = "cgi_extension cgi_path cgi_param";
        std::vector<std::string> validCgiConfigs = Utils::split(validCgiConfigsString, " ");
        validLocationConfigs.insert(validLocationConfigs.end(), validCgiConfigs.begin(), validCgiConfigs.end());
    }
    for (ConfigObject::const_config_iterator config = location.get_config().begin(); config != location.get_config().end(); ++config) {
        if (std::find(validLocationConfigs.begin(), validLocationConfigs.end(), config->first) == validLocationConfigs.end()) {
            throw std::runtime_error("Invalid location configuration: " + config->first);
        }
    }

    // Check for configs that can cannot be used more than once
    std::string uniqueConfigsString = "root index client_max_body_size alias return";
    std::vector<std::string> uniqueConfigs = Utils::split(uniqueConfigsString, " ");
    for (std::vector<std::string>::iterator uniqueConfig = uniqueConfigs.begin(); uniqueConfig != uniqueConfigs.end(); ++uniqueConfig) {
        if (location.contains(*uniqueConfig) && location[*uniqueConfig].size() > 1) {
            throw std::runtime_error("Location configuration can only be used once: " + *uniqueConfig);
        }
    }

    // check for configs that require a value
    std::string requiredValueConfigsString = "root index autoindex location return client_max_body_size error_page allow_methods";
    std::vector<std::string> requiredValueConfigs = Utils::split(requiredValueConfigsString, " ");
    for (std::vector<std::string>::iterator requiredValueConfig = requiredValueConfigs.begin(); requiredValueConfig != requiredValueConfigs.end(); ++requiredValueConfig) {
        if (location.contains(*requiredValueConfig) && location[*requiredValueConfig][0].get_value().empty()) {
            throw std::runtime_error("Location configuration must have a value: " + *requiredValueConfig);
        }
    }
}


//ip:port or port or ip
void ConfigObject::validateListenValue(std::string value) const
{
    // Check for empty listen value
    // if (value.empty())
    //     throw std::runtime_error("Listen value should not be empty");

    // Check for invalid characters
    if (value.find_first_not_of("0123456789.:") != std::string::npos) {
        throw std::runtime_error("Listen value should only contain numbers, dots, and colons: " + value);
    }

    int port = 80;
    std::string portString = "";
    std::string ip = "";
    if (value.find(':') != std::string::npos) {
        portString = value.substr(value.find(':') + 1);
        ip = value.substr(0, value.find(':'));
    }
    else if (value.find('.') != std::string::npos)
        ip = value;
    else
        portString = value;

    //check port
    try{
        port = std::atoi(portString.c_str());
    }
    catch (std::exception& e) {
        throw std::runtime_error("Invalid port: " + portString);
    }
    if (port < 0 || port > 65535) {
        throw std::runtime_error("Invalid port: " + portString);
    }

    //check ip
    if (ip == "")
        return;
    std::vector<std::string> ipParts = Utils::split(ip, ".");
    if (ipParts.size() != 4) {
        throw std::runtime_error("Invalid ip: " + ip);
    }
    for (std::vector<std::string>::iterator ipPart = ipParts.begin(); ipPart != ipParts.end(); ++ipPart) {
        try {
            if (ipPart->empty())
                throw std::runtime_error("Invalid ip: " + ip);
            int ipPartInt = std::atoi(ipPart->c_str());
            if (ipPartInt < 0 || ipPartInt > 255) {
                throw std::runtime_error("Invalid ip: " + ip);
            }
        }
        catch (std::exception& e) {
            throw std::runtime_error("Invalid ip: " + ip);
        }
    }
}

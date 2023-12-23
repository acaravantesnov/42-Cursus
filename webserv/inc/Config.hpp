#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <set>
#include <algorithm>

#include "Utils.hpp"

class ConfigParsingException : public std::exception {
private:
    std::string _msg;
public:
    ConfigParsingException(std::string msg) : _msg(msg) {}
    virtual ~ConfigParsingException() throw() {}
    virtual const char* what() const throw() {
        return _msg.c_str();
    }
};

class ConfigItem;

// Contains the configuration for an nginx server
class ConfigObject {
private:
    std::map<std::string, std::vector<ConfigItem> > _config;
    void parseConfig(std::istream& in);
    void parseConfig_withoutBrakets(std::istream& in);
    void skipWhitespace(std::istream& in);
    void skipWhitespace(std::istream& in, bool skip_newline);

    void validateServer(const ConfigObject& server, std::set<std::string>& server_names) const;
    void validateLocation(const ConfigObject& locations, std::string value) const;
    void validateListenValue(std::string value) const;

public:

    typedef std::map<std::string, std::vector<ConfigItem> >::iterator config_iterator;
    typedef std::map<std::string, std::vector<ConfigItem> >::const_iterator const_config_iterator;

    ConfigObject(const ConfigObject& other);
    ConfigObject();
    ~ConfigObject();
    ConfigObject& operator=(const ConfigObject& other);

    ConfigObject(std::string filename);
    ConfigObject(std::istream& in);
    const std::map<std::string, std::vector<ConfigItem> >& get_config() const ;

    //returns a vector of ConfigItems, associated with the kew. It is a vector because there can be multiple ConfigItems with the same key (such as server or locations)
    const std::vector<ConfigItem>& operator[](std::string key) const;

    //returns true if the key is in the config
    bool contains(std::string key) const;

    void validateConfig() const;
};

class ConfigItem{
private:
    //format is:    key value;
    //or:           key { subconfig}
    //or:           key value { subconfig } //I think this is only on location
    std::string _value;
    ConfigObject _subConfig;
    std::string _key;
    bool _isSubConfigUsed;
    bool _isValueUsed;

    void parseItem(std::istream& in);
    void skipWhitespace(std::istream& in);

public:
    ConfigItem(const ConfigItem& other);
    ConfigItem();
    ~ConfigItem();
    ConfigItem& operator=(const ConfigItem& other);

    ConfigItem(std::istream& in);
    const std::string& get_value() const;
    const ConfigObject& get_subConfig() const;
    ConfigObject get_nonconst_subConfig() const;
    const std::string& get_key() const;
    bool get_isSubConfigUsed() const ;
    bool get_isValueUsed() const ;
    const std::vector<ConfigItem> &operator[](std::string key) const;

};

std::ostream& operator<<(std::ostream& out, const ConfigObject& config);
std::ostream& operator<<(std::ostream& out, const ConfigItem& item);

#endif

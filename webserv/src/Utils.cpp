#include "Utils.hpp"

unsigned int Utils::find(std::vector<char> const &vec, std::vector<char> const &pattern, unsigned int start){
    unsigned int i = start;
    unsigned int j = 0;
    while(i < vec.size() && j < pattern.size()){
        if(vec[i] == pattern[j]){
            i++;
            j++;
        }else{
            i = i - j + 1;
            j = 0;
        }
    }
    if(j == pattern.size()){
        return i - j;
    }else{
        return Utils::npos;
    }
}

std::vector<std::string> Utils::split(std::string const &str, std::string const &pattern){
    std::vector<std::string> result;
    unsigned int start = 0;
    unsigned int end = 0;
    while(end < str.size()){
        end = str.find(pattern, start);
        if(end == Utils::npos)
            end = str.size();
        result.push_back(str.substr(start, end - start));
        start = end + pattern.size();
    }
    return result;
}

std::vector<std::vector<char> >  Utils::split(std::vector<char> const &vec, std::vector<char> const &pattern){
    std::vector<std::vector<char> > result;
    unsigned int start = 0;
    unsigned int end = 0;
    while(end < vec.size()){
        end = Utils::find(vec, pattern, start);
        if(end == Utils::npos)
            end = vec.size();
        result.push_back(Utils::substr(vec, start, end));
        start = end + pattern.size();
    }
    return result;
}

//it will use the pattern that splits earliest in the vector. If there are two patterns that split at the same position, it will use the first one. This is done for each splitting
//if the split is size 0, it will be ignored
std::vector<std::vector<char> > Utils::split(std::vector<char> const &vec, std::vector<std::vector<char> > const &patterns){
    std::vector<std::vector<char> > result;
    unsigned int start = 0;
    unsigned int end = 0;
    while(end < vec.size()){
        unsigned int min = vec.size();
        unsigned int pattern_used_size = 0;
        for(unsigned int i = 0; i < patterns.size(); i++){
            unsigned int temp = Utils::find(vec, patterns[i], start);
            if(temp < min){
                min = temp;
                pattern_used_size = patterns[i].size();
            }
        }
        end = min;
        if(end == Utils::npos)
            end = vec.size();
        std::vector<char> temp = Utils::substr(vec, start, end);
        if(temp.size() != 0)
            result.push_back(temp);
        start = end + pattern_used_size;
    }
    return result;
}


std::vector<char> Utils::substr(std::vector<char> const &vec, unsigned int start, unsigned int end){
    if(end == npos)
        end = vec.size();
    if (start > end)
        return std::vector<char>();
    return std::vector<char>(vec.begin() + start, vec.begin() + end);
}

//concatenates two std::vector<char>
std::vector<char> Utils::concat(std::vector<char> const &vec1, std::vector<char> const &vec2){
    std::vector<char> result(vec1);
    result.insert(result.end(), vec2.begin(), vec2.end());
    return result;
}

//trims whitespace from the beginning and end of a string
std::string Utils::trim(std::string const &str)
{
    if(str.size() == 0)
        return str;
    unsigned int start = 0;
    unsigned int end = str.size() - 1;
    while(start < str.size() && isspace(str[start]))
        start++;
    while(end > start && isspace(str[end]))
        end--;
    return str.substr(start, end - start + 1);

}

//concatenates two std::vector<char> with operator +
std::vector<char> operator+(std::vector<char> const &vec1, std::vector<char> const &vec2){
    return Utils::concat(vec1, vec2);
}

//TODO: remove it. This is only temporary for the transition from std::string to std::vector<char>
std::vector<char> Utils::stringToVector(std::string const &str){
    return std::vector<char>(str.begin(), str.end());
}

//TODO: remove it. This is only temporary for the transition from std::string to std::vector<char>
std::string Utils::vectorToString(std::vector<char> const &vec){
    std::string ret;
    for (size_t i = 0; i < vec.size(); i++)
        ret.push_back(vec[i]);
    return ret;
}

bool Utils::is_directory(const std::string& path){
	struct stat path_stat;
	stat(path.c_str(), &path_stat);
	return S_ISDIR(path_stat.st_mode);
}

std::string  Utils::clean_path(std::string const &str)
{
    for(size_t i = 0; i < str.size(); i++)
        if(str[i] == '/' && str[i + 1] == '/')
            return (Utils::clean_path(str.substr(0, i) + str.substr(i + 1)));
    return (str);
}

bool Utils::find_at_end(std::string str, std::string substr)
{
    if (str.size() < substr.size())
        return (false);
    return (str.substr(str.size() - substr.size()) == substr);
}

size_t	Utils::ft_strlen(const char *str)
{
	int		i;
	size_t	elementos;

	i = 0;
	elementos = 0;
	while (str[i] != '\0')
	{
		i++;
		elementos++;
	}
	return (elementos);
}

char *Utils::strdup_cpp(const char *src)
{
	char	*ptr;
	char	*start;

	ptr = new char[sizeof(char) * (ft_strlen(src) + 1)];
	if (ptr == NULL)
		return (NULL);
	start = ptr;
	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (start);
}

bool Utils::file_exists(const std::string& path)
{
	struct stat path_stat;
	if (stat(path.c_str(), &path_stat) != 0)
		return false;
	return true;
}

#include <iostream>
int Utils::my_stoi(std::string str)
{
    str = trim(str);
	int res = std::atoi(str.c_str());
	if ((str != "0") && res == 0)
		throw ("atoi failed in my_stoi.");
	return (res);
}


long Utils::my_stol(std::string str)
{
    str = trim(str);
	long res = std::atol(str.c_str());
	if ((str != "0") && res == 0)
		throw ("atol failed in my_stol.");
	return (res);
}

std::string Utils::uint_to_string(unsigned int value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

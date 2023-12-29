#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <string>
#include <sys/stat.h>
#include <cstdio>
#include <cstdlib>
#include <sstream>

# define DEBUG true

class Utils {
public:

    // npos for std::vector<char>
    static const unsigned int npos = -1;

    // find function for std::vector<char>
    static unsigned int find(std::vector<char> const &vec, std::vector<char> const &pattern, unsigned int start = 0);

    // split function for std::string
    static std::vector<std::string> split(std::string const &str, std::string const &pattern);

    // split function for std::vector<char>
    static std::vector<std::vector<char> > split(std::vector<char> const &vec, std::vector<char> const &pattern);

    // split with different patterns
    static std::vector<std::vector<char> > split(std::vector<char> const &vec, std::vector<std::vector<char> > const &patterns);

    // substr function for std::vector<char>.
    static std::vector<char> substr(std::vector<char> const &vec, unsigned int start, unsigned int end = npos);

    // Concatenates two std::vector<char>.
    static std::vector<char> concat(std::vector<char> const &vec1, std::vector<char> const &vec2);

    // Converts a string to a vector<char>.
    //TODO: remove it. This is only temporary for the transition from std::string to std::vector<char>.
    static std::vector<char> stringToVector(std::string const &str);

    // Converts a vector<char> to a string.
    //TODO: remove it. This is only temporary for the transition from std::string to std::vector<char>.
    static std::string vectorToString(std::vector<char> const &vec);

    // Trims whitespace from the beginning and end of a string.
    static std::string trim(std::string const &str);

    // Returns true if a certain directory is valid (exists).
    static bool is_directory(const std::string& path);

    // Looks for adyacent '/' and reduces them to one.
    static std::string  clean_path(std::string const &str);

    // Looks for substr at the end of str.
    static bool find_at_end(std::string str, std::string substr);

	// strlen for strdup_cpp.
	static size_t ft_strlen(const char *str);

	// C++ equivalent for C strdup function (using new instead of malloc).
	static char *strdup_cpp(const char *src);

	//Returns true if path file exists, false otherwise.
	static bool file_exists(const std::string& path);

	// C++98 equivalent for C++11 stoi using atoi and c_str
	static int my_stoi(std::string str);

	// C++98 equivalent for C++11 stol using atol and c_str
	static long my_stol(std::string str);

    // C++98 equivalent for C++11 to_string using sstream
    static std::string uint_to_string(unsigned int value);
};


//concatenates two std::vector<char> with operator +
std::vector<char> operator+(std::vector<char> const &vec1, std::vector<char> const &vec2);


#endif

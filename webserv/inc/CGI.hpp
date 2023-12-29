#ifndef CGI_HPP
# define CGI_HPP

# include "HttpLogic.hpp"
# include "HttpRequest.hpp"
# include "Utils.hpp"
# include <unistd.h> // fork()
# include <sys/wait.h> // waitpid()
# include <sys/types.h> // waitpid()
# include <cstring>

class CGI
{
    private:
        std::map<std::string, std::string>	                _cgiExecutables;
        std::map<std::string, std::string>                  _cgiEnvVars;
        std::vector<char>                                   _cgiOutput;
        std::vector<char>                                   _cgiInput;
        int                                                 _child_fd_out;
        int                                                 _child_fd_in;
        pid_t                                               _pidChild;
        bool                                                _cgiRunning;
        int                                                 _childStatus;
    public:
        CGI(const HttpRequest &request, const ConfigObject &constConfig, std::string defaultPathInfo);
        CGI(const CGI &other);
        CGI();
        CGI &operator=(const CGI &other);

        std::map<std::string, std::string>                  &getCgiExecutables();
        std::map<std::string, std::string>                  &getCgiEnvVars();
		    void								                                setCgiEnvVars(const HttpRequest &request, const ConfigObject &constConfig, std::string defaultPathInfo);
        void                                                run_cgi(const HttpRequest &request, const ConfigObject &constConfig);
        std::vector<char>                                   get_cgi_output();
        bool                                                is_cgi_done();
        int                                                 get_child_status();
};

#endif

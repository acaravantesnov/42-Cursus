#include "CGI.hpp"

CGI &CGI::operator=(const CGI &other)
{
    if (this == &other)
        return (*this);
    _cgiExecutables = other._cgiExecutables;
    _cgiEnvVars = other._cgiEnvVars;
    _cgiRunning = other._cgiRunning;
    _cgiOutput = other._cgiOutput;
    _cgiInput = other._cgiInput;
    _pidChild = other._pidChild;
    _child_fd_out = other._child_fd_out;
    _child_fd_in = other._child_fd_in;
    _childStatus = other._childStatus;
    return (*this);
}

CGI::CGI(const CGI &other){
    *this = other;
}

CGI::CGI() : _child_fd_out(-1), _pidChild(-1), _cgiRunning(false), _childStatus(0) {}

CGI::CGI(const HttpRequest &request, const ConfigObject &constConfig, std::string defaultPathInfo) : \
_cgiExecutables(HttpLogic::get_cgis(request, constConfig)), _child_fd_out(-1), _child_fd_in(-1), _pidChild(-1), _cgiRunning(false), _childStatus(0)
{
    setCgiEnvVars(request, constConfig, defaultPathInfo); 
}

std::map<std::string, std::string>  &CGI::getCgiExecutables()
{
    return (_cgiExecutables);
}

std::map<std::string, std::string>  &CGI::getCgiEnvVars()
{
    return (_cgiEnvVars);
}

// PATH_INFO define script cgi, no el ejecutable
void CGI::setCgiEnvVars(const HttpRequest &request, const ConfigObject &constConfig, std::string defaultPathInfo)
{
    _cgiEnvVars.insert(std::make_pair("PATH_INFO", defaultPathInfo));
	std::vector<std::pair<std::string, std::string> > confEnvVarsVector =  HttpLogic::get_cgi_env_vars(request, constConfig);
	for (size_t i = 0; i < confEnvVarsVector.size(); i++)
		_cgiEnvVars.insert(std::make_pair(confEnvVarsVector[i].first, confEnvVarsVector[i].second));
    HttpRequest::RequestType type = request.getType();
    if (type == HttpRequest::POST)
        _cgiEnvVars.insert(std::make_pair("REQUEST_METHOD", "POST"));
    else if (type == HttpRequest::GET)
        _cgiEnvVars.insert(std::make_pair("REQUEST_METHOD", "GET"));
    else if (type == HttpRequest::DELETE)
        _cgiEnvVars.insert(std::make_pair("REQUEST_METHOD", "DELETE"));
    else
        throw (std::runtime_error("Invalid request type."));
    if (type == HttpRequest::GET && request.getPath().find('?') != std::string::npos)
        _cgiEnvVars.insert(std::make_pair("QUERY_STRING", request.getPath().substr(request.getPath().find('?') + 1)));
    if (type == HttpRequest::POST)
    {
		if (request.getHeader().count("Content-Length"))
			_cgiEnvVars.insert(std::make_pair("CONTENT_LENGTH", request.getHeader().at("Content-Length")));
        if (request.getHeader().count("Content-Type"))
			_cgiEnvVars.insert(std::make_pair("CONTENT_TYPE", request.getHeader().at("Content-Type")));
    }
    _cgiEnvVars.insert(std::make_pair("SERVER_PROTOCOL", "HTTP/1.1"));
    _cgiEnvVars.insert(std::make_pair("SERVER_SOFTWARE", "webserv/1.0"));
    _cgiEnvVars.insert(std::make_pair("SERVER_NAME", constConfig["server_name"][0].get_value()));
    _cgiEnvVars.insert(std::make_pair("SERVER_PORT", Utils::uint_to_string(HttpLogic::get_ports(constConfig)[0])));
}

void CGI::run_cgi(const HttpRequest &request, const ConfigObject &constConfig)
{
    bool                isDir = false;
    std::string         extension = "";
    std::string			cgiScriptPath =  "";

    std::string filePath = HttpLogic::get_file_path(request, constConfig);

    //because of the query string in GET requests
    if (filePath.find('?') != std::string::npos)
        filePath = filePath.substr(0, filePath.find('?'));

    const char  *executablePath;

    if (Utils::find_at_end(filePath, "/cgi-bin/") || Utils::find_at_end(filePath, "/cgi-bin")) // Its a directory
    {
        isDir = true;
        if (_cgiEnvVars.find("PATH_INFO") == _cgiEnvVars.end())
            throw (std::runtime_error("CGI script path not set."));
        cgiScriptPath = _cgiEnvVars["PATH_INFO"];
    }
    else // Its a script
		cgiScriptPath = filePath;

	std::ifstream   script(cgiScriptPath.c_str());
    if (!script.is_open()){// Does it exist? Can it be read?
        throw (std::runtime_error("CGI script does not exist."));
    } 

	if (*(cgiScriptPath.end() - 1) != '/')
	{
		if (cgiScriptPath.substr(cgiScriptPath.find_last_of('/') + 1).find('.') != std::string::npos)
		{
			extension = cgiScriptPath.substr(cgiScriptPath.find_last_of('.'));
			if (getCgiExecutables().find(extension) == getCgiExecutables().end())
				throw std::runtime_error("Extension not supported.");
			executablePath = getCgiExecutables()[extension].c_str();
		}
	}

    char *argv[] = {(char *)getCgiExecutables()[extension].substr(getCgiExecutables()[extension].find_last_of('/') + 1).c_str(), (char *)cgiScriptPath.c_str(), NULL};
    if (isDir)
        argv[0] = (char *)cgiScriptPath.substr(cgiScriptPath.find_last_of('/') + 1).c_str();
	
    std::vector<std::pair<std::string, std::string> > envVariablesStr; 
    // Copy _cgiEnvVars map into envVariablesStr vector of pairs
    for (std::map<std::string, std::string>::iterator it = _cgiEnvVars.begin();  it != _cgiEnvVars.end(); it++)
      envVariablesStr.push_back(std::make_pair(it->first, it->second));

    char **envVars = new char *[(envVariablesStr.size()) + 1];
    if (envVars == NULL)
        throw (std::runtime_error("Unable to allocate memory."));

    for (size_t i = 0; i < envVariablesStr.size(); i++)
    {
        //envVars[i] = (envVariablesStr[i].first + "=" + envVariablesStr[i].second).c_str();
        std::string value_to_copy = (envVariablesStr[i].first + "=" + envVariablesStr[i].second);
        envVars[i] = new char[value_to_copy.size() + 1];
        if (envVars[i] == NULL)
            throw (std::runtime_error("Unable to allocate memory."));
        for (size_t j = 0; j < value_to_copy.size(); j++)
            envVars[i][j] = value_to_copy[j];
        envVars[i][value_to_copy.size()] = '\0';
    }
    envVars[envVariablesStr.size()] = NULL;

    int pipefd_child_out[2];
    if (pipe(pipefd_child_out) == -1) // Create pipe
        throw (std::runtime_error("Unable to create pipe."));
    int pipefd_child_in[2];
    if (pipe(pipefd_child_in) == -1) // Create pipe
        throw (std::runtime_error("Unable to create pipe."));

    pid_t pid = fork();
    if (pid == -1) 
        throw (std::runtime_error("Unable to fork."));
    if (pid == 0) // Child
    {
        close(pipefd_child_out[0]); // Close read end
        dup2(pipefd_child_out[1], STDOUT_FILENO);

        close(pipefd_child_in[1]); // Close write end
        dup2(pipefd_child_in[0], STDIN_FILENO);

        if (execve(executablePath, argv, (char *const *)envVars) == -1)
        {
            for (size_t i = 0; i < envVariablesStr.size(); i++)
                delete[] envVars[i];
            delete[] envVars;
            exit(1);
        }
    }
    else // Parent
    {
        _pidChild = pid;
        _child_fd_out = pipefd_child_out[0];
        _cgiInput = request.getBody();
        close(pipefd_child_out[1]); // Close write end
        _child_fd_in = pipefd_child_in[1];
        close(pipefd_child_in[0]); // Close read end

        //Free memory
        for (size_t i = 0; i < envVariablesStr.size(); i++)
            delete[] envVars[i];
        delete[] envVars;
    }
    //return (result);
    _cgiRunning = true;
}

bool CGI::is_cgi_done()
{
    if (!_cgiRunning)
        return (true);
    
    //write into pipe
    char buffer[1024 * 1024];
    if (_cgiInput.size() > 0){
        int size  = _cgiInput.size() > sizeof(buffer) ? sizeof(buffer) : _cgiInput.size();
        std::copy(_cgiInput.begin(), _cgiInput.begin() + size, buffer);
        //std::cout << "Writing " << size << " bytes to CGI script." << std::endl;
        write(_child_fd_in, buffer, size);
        _cgiInput.erase(_cgiInput.begin(), _cgiInput.begin() + size);
        if (_cgiInput.size() == 0)
            close(_child_fd_in); // Close write end of the child pipe
    }

    //find if child has finished
    int status;
    int ret;
    if ((ret = waitpid(_pidChild, &status, WNOHANG)) == -1){
        throw (std::runtime_error("Waitpid failed."));
    }
    if (ret == 0){
        return (false);
    }
    // else CGI has just finished
    //std::cout << _pidChild << " " << WIFEXITED(status) << " " << WIFSIGNALED(status) << std::endl;
    _childStatus = WEXITSTATUS(status);
    
    _cgiRunning = false;

    std::vector<char> result;
    size_t count;
    while ((count = read(_child_fd_out, buffer, sizeof(buffer))) > 0)
        result.insert(result.end(), buffer, buffer + count);
    _cgiOutput = result;
    close(_child_fd_out); // Close read end of the child pipe
    return (true);
    // _cgiRunning = false;
    // return (!_cgiRunning);
}

std::vector<char> CGI::get_cgi_output()
{
    return (_cgiOutput);
}

int CGI::get_child_status()
{
    return (_childStatus);
}

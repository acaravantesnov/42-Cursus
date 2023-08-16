#ifndef RPN_HPP
# define RPN_HPP

# include <sstream>
# include <iostream>
# include <stack>
# include <string>
# include <stdlib.h>

class RPN
{
    private:
	    std::stack<int>	*_st;

    public:
        RPN();
        RPN(const RPN &rpn);
        RPN(std::stack<int> *st);
        ~RPN();
        RPN &operator=(RPN &rpn);

        std::stack<int> *getSt() const;
        void            setSt(std::stack<int> *st);
        void            checkArgs(int argc, char *argv1);

        class   InvalidNumberofArgs : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

        class   InvalidArgs : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

# endif

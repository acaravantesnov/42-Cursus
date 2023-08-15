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
};

bool    check_args(std::string argv1);

# endif

#ifndef RPN_HPP
#define RPN_HPP

#include "Postfix.hpp"

class RPN 
{
	public:
	    double evaluate(const Postfix& pf);
};

#endif


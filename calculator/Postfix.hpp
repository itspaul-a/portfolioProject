#ifndef POSTFIX_HPP
#define POSTFIX_HPP

#include "Term.hpp"
#include <iostream>
#include <sstream>
#include <list>

class Postfix 
{
	private:
	    std::list<Term> terms;
	
	public:
	    Postfix();
	
	    void append(const Term& t);
	    const std::list<Term>& getTerms() const;
	
	    friend std::ostream& operator<<(std::ostream& os, const Postfix& pf);
	    friend std::istream& operator>>(std::istream& is, Postfix& pf);
};

#endif


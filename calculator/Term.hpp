#ifndef TERM_HPP
#define TERM_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

class Term 
{
	private:
	    bool isNumber;
	    double value;
	    char op;
	
	public:
	    Term();
	    Term(double val);
	    Term(char c);
	
	    bool getIsNumber() const;
	    double getValue() const;
	    char getOp() const;
	
	    Term operator+(const Term& other) const;
	    Term operator-(const Term& other) const;
	    Term operator*(const Term& other) const;
	    Term operator/(const Term& other) const;
	    Term operator^(const Term& other) const;
	
	    std::string toString() const;
};

#endif


#include "Term.hpp"


Term::Term() : isNumber(false), value(0), op(0) {}
Term::Term(double val) : isNumber(true), value(val), op(0) {}
Term::Term(char c) : isNumber(false), value(0), op(c) {}

bool Term::getIsNumber() const 
{ 
	return isNumber;
}

double Term::getValue() const 
{ 
	return value;
}
char Term::getOp() const 
{ 
	return op;
}

Term Term::operator+(const Term& other) const 
{
    if (isNumber && other.isNumber) 
	{
		return Term(value + other.value);
	}

    std::cout << "invalid + operation" << std::endl;
    return Term();
}

Term Term::operator-(const Term& other) const 
{
    if (isNumber && other.isNumber) 
	{
		return Term(value - other.value);
	}

    std::cout << "invalid - operation" << std::endl;
    return Term();
}

Term Term::operator*(const Term& other) const 
{
    if (isNumber && other.isNumber) 
	{
		return Term(value * other.value);
	}

    std::cout << "invalid * operation" << std::endl;
    return Term();
}

Term Term::operator/(const Term& other) const 
{
    if (isNumber && other.isNumber) 
	{
        if (other.value == 0) 
		{
            std::cout << "!!!dividing by zero!!!" << std::endl;
            return Term();
        }

        return Term(value / other.value);
    }

    std::cout << "invalid / operation" << std::endl;
    return Term();
}

Term Term::operator^(const Term& other) const 
{
    if (isNumber && other.isNumber) 
	{
		return Term(std::pow(value, other.value));
	}

    std::cout << "invalid ^ operation" << std::endl;
    return Term();
}

std::string Term::toString() const 
{
    std::ostringstream oss;

    if (isNumber)
	{
        oss << value;
	}else
	{
        oss << op;
	}

    return oss.str();
}


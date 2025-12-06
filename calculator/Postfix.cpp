#include "Postfix.hpp"

Postfix::Postfix() {}

void Postfix::append(const Term& t) 
{
    terms.push_back(t);
}

const std::list<Term>& Postfix::getTerms() const 
{
    return terms;
}

std::ostream& operator<<(std::ostream& os, const Postfix& pf) 
{
    std::ostringstream oss;

    for (auto it = pf.terms.begin(); it != pf.terms.end(); ++it) 
	{
        oss << it->toString();
        if (std::next(it) != pf.terms.end())
		{
			oss << " ";
		}
    }

    os << oss.str();
    return os;
}

std::istream& operator>>(std::istream& is, Postfix& pf) 
{
    std::string inputLine;
    std::getline(is, inputLine);
    std::stringstream ss(inputLine);
    std::string token;

    while (ss >> token) 
	{

        if (std::isdigit(token[0]) || 
           (token[0] == '-' && token.size() > 1 && std::isdigit(token[1]))) 
		{
            pf.append(Term(std::stod(token)));

        } else if (token.size() == 1) 
		{
            pf.append(Term(token[0]));
        } else 
		{
            std::cout << "Invalid token ignored: " << token << "\n";
        }
    }

    return is;
}


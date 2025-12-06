#include "RPN.hpp"
#include <stack>
#include <cmath>

double RPN::evaluate(const Postfix& pf) 
{
    std::stack<double> s;

    for (const Term& t : pf.getTerms()) 
	{
        if (t.getIsNumber()) 
		{
            s.push(t.getValue());
        } else 
		{
            if (s.size() < 2) 
			{
                return 0;
            }

            double b = s.top(); s.pop();
            double a = s.top(); s.pop();
            double res = 0;

            switch (t.getOp()) 
			{
                case '+': 
					res = a + b; 
					break;

                case '-': 
					res = a - b; 
					break;

                case '*': 
					res = a * b; 
					break;

                case '/':
                    if (b == 0) 
					{
                        std::cout << "!!!dividing by zero!!!" << std::endl;
                        return 0;
                    }

                    res = a / b;
                    break;

                case '^': 
					res = std::pow(a, b); 
					break;

                default:
                    std::cout << "invalid operator: " << t.getOp() << std::endl;
                    return 0;
            }

            s.push(res);
        }
    }

    if (s.size() != 1) 
	{
        std::cout << "invalid expression";
        return 0;
    }

    return s.top();
}


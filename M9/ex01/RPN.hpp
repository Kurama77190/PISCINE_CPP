#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <stdexcept>
# include <cctype>
# include <string>
# include <algorithm>
# include <iterator>
# include <cstdlib>
# include <cmath>
# include <limits>



class RPN {
public:

	RPN( void );
	~RPN( void );
	void evaluate(std::string const &input);
	double applyOperation(double a, double b, char op);
	void displayStack() const;
private:
	std::stack<double> _stack;
	RPN( const RPN &other );
	RPN &operator=( const RPN &other );
};

#endif
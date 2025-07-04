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
	RPN( const RPN &other );
	RPN &operator=( const RPN &other );

	void evaluate(std::string const &input);
	int applyOperation(int a, int b, char op);
	void displayStack() const;
private:
	std::stack<int> _stack;
};

#endif
#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstdlib> // for atoi
# include <cstring>

class RPN {
	private:
		std::stack<int> numbers;

	public:
		RPN() ;
		RPN(const RPN &other) ;
		RPN & operator=(const RPN &other);
		~RPN() ;

		long int evaluate(const char *expression);
		class rpnException : public std::exception {
		public:
			const char *what() const throw() {
				return "Error: bad input";
			}
};

class InfException : public std::exception {
    public:
        const char *what() const throw() {
            return "∞";
        }
    };
};

#endif

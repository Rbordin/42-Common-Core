#include "RPN.hpp"


RPN::RPN() {}

RPN::RPN(const RPN &other) {
}

RPN& RPN::operator=(const RPN &other) {
    return *this;
}

RPN::~RPN() {}

long int RPN::evaluate(const char *expression) {
    const char *token = strtok(const_cast<char*>(expression), " ");
    while (token != NULL) {
        try {
            if (isdigit(token[0]))
                numbers.push(atoi(token));
			else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/') {
                if (numbers.size() < 2) {
                    throw rpnException();
                }
                int b = numbers.top();
                numbers.pop();
                int a = numbers.top();
                numbers.pop();
                switch (token[0]) {
                    case '+':
                        numbers.push(a + b);
                        break;
                    case '-':
                        numbers.push(a - b);
                        break;
                    case '*':
                        numbers.push(a * b);
                        break;
                    case '/':
                        if (b == 0) {
                            throw InfException();
                        }
                        numbers.push(a / b);
                        break;
                    default:
                        throw rpnException();
                }
            } else {
                throw rpnException();
            }
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            exit(1);
        }
        token = strtok(NULL, " ");
    }
    if (numbers.size() != 1) {
        throw rpnException();
    }
    return numbers.top();
}

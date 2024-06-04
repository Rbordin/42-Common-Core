#include "RPN.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <RPN expression>" << std::endl;
        return 1;
    }

    RPN calculator;
    try {
        long int result = calculator.evaluate(argv[1]);
        std::cout << "Result: " << result << std::endl;
    } catch (RPN::rpnException &e) {
        std::cerr << "Error: Invalid input" << std::endl;
    } catch (RPN::InfException &e) {
        std::cerr << "Error: Division by zero" << std::endl;
    }

    return 0;
}

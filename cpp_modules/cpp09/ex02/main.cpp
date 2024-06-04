
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "Error: input some number\n";
        return (1);
    }
    double t1, t2;

    std::cout << std::fixed << std::setprecision(2);
    PmergeMe test(argv);
    test.sort_4_deque();
    t1 = test.Time();
    test.sort_4_vettor();
    t2 = test.Time();
    std::cout << "time  to process a range  elements with deque: " << t1 << "us"<< std::endl;
    std::cout << "time to process a range  elements with vector: " << t2 << "us" << std::endl;
}
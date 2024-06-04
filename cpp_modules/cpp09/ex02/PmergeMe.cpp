#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
    start = 0;
    end = 0;
}

int	isPosNumber(char *s){
    int i = -1;

    while (s[++i])
    {
        if (!isdigit(s[i]))
            return (0);
    }
    if (atof(s) > 2147483647)
        return (0);
    return (1);
}

PmergeMe::PmergeMe(char **argv): start(0), end(0){
    int	i = 0;

    while (argv[++i])
    {
        if (isPosNumber(argv[i]))
        {
            this->vettor.push_back(atoi(argv[i]));
            this->lista.push_back(atoi(argv[i]));
        }
        else
        {
            std::cout << "Error: bad input\n";
            return  ;
        }
    }
    i = -1;
    std::cout << "unsorted numbers: ";
    while ((unsigned long)++i < this->vettor.size())
        std::cout << this->lista[i] << " ";

}

PmergeMe::~PmergeMe(){}

double	get_ts(struct timeval ts){
    gettimeofday(&ts, 0);
    return ((((ts.tv_sec % 100) * 1000000) + ts.tv_usec));
}

double	PmergeMe::Time(void){
    double ret;

    ret = this->end - this->start;
    return (ret);
}

void	PmergeMe::sort_4_vettor(){

	int i = -1;
    struct timeval time;

    this->start = get_ts(time);
    mergeinsection(this->vettor, 0, this->vettor.size() - 1, 4);
    this->end = get_ts(time);
    std::cout << "\n sorted numbers: ";
    while ((unsigned long)++i < this->vettor.size())
        std::cout << this->vettor[i] << " ";
    std::cout << std::endl;
    if (sorted(this->vettor))
        std::cout << " TA DAAAA VECTOR SORTED\n";
    else
        std::cout << "Error: vector notsorted\n";
}

void	PmergeMe::sort_4_deque(){

	int i = -1;
    struct timeval time;

    this->start = get_ts(time);
    mergeinsection(this->lista, 0, this->lista.size() - 1, 4);
    this->end = get_ts(time);
    std::cout << "\n sorted numbers : ";
    while ((unsigned long)++i < this->lista.size())
        std::cout << this->lista[i] << " ";
    std::cout << std::endl;
    if (sorted(this->lista))
        std::cout << " TA DAAAA , DEQUE SORTED \n";
    else
        std::cout << "Error: lista not sorted\n";
}

PmergeMe::PmergeMe(const PmergeMe &copy){

	vettor = copy.vettor;
    lista = copy.lista;
    start = copy.start;
    end = copy.end;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &copy) {

	if (this != &copy) {
        vettor = copy.vettor;
        lista = copy.lista;
        start = copy.start;
        end = copy.end;
    }
    return *this;
}

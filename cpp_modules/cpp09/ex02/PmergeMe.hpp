
#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <vector>
#include <deque>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <sys/time.h>
#include <stdlib.h>
#include <iomanip>


class PmergeMe{
	private :
		std::vector<int> vettor;
		std::deque<int> lista;
		double  start, end;

	public :
		PmergeMe();
		~PmergeMe();
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		void sort_4_vettor();
		void sort_4_deque();
		double Time(void);
};

// Fusione in-place di due sottoarray ordinati

template<typename T>
void merge_in_place(T &arr, int left, int mid, int right){

    int index_left, index_right, index_main;
    int size_left = mid - left + 1;
    int size_right = right - mid;
    int left_array[size_left], right_array[size_right];

    for (index_left = 0; index_left < size_left; index_left++)
        left_array[index_left] = arr[left + index_left];
    for (index_right = 0; index_right < size_right; index_right++)
        right_array[index_right] = arr[mid + 1 + index_right];
    index_left = 0;
    index_right = 0;
    index_main = left;
    while (index_left < size_left && index_right < size_right)
    {
        if (left_array[index_left] <= right_array[index_right])
        {
            arr[index_main] = left_array[index_left];
            index_left++;
        }
        else
        {
            arr[index_main] = right_array[index_right];
            index_right++;
        }
        index_main++;
    }
    while (index_left < size_left)
    {
        arr[index_main] = left_array[index_left];
        index_left++;
        index_main++;
    }
    while (index_right < size_right)
    {
        arr[index_main] = right_array[index_right];
        index_right++;
        index_main++;
    }
}


template<typename T>
void insectionsort(T& num, int sx, int dx){

    for (int i = sx + 1; i <= dx; i++){
        int k = num[i];
        int j = i - 1 ;

        while(j >= sx && num[j] > k){
            num[j + 1] = num[j];
            j--;
        }
        num[j + 1] = k;
    }
}

template<typename T>
void mergeinsection(T &array, int sx, int dx, int k){

    if(sx < dx)
    {
        // Caso base: sottoarray di dimensione <= k ordinato da insection
        if(dx - sx <= k)
            insectionsort(array, sx, dx);
        else
        {
            // Caso ricorsivo: sottoarray di dimensione > k
            int median = sx + (dx - sx) / 2;
            mergeinsection(array, sx, median, k);
            mergeinsection(array, median + 1, dx, k);
            merge_in_place(array, sx, median, dx);
        }
    }
}


template <typename T>
int	sorted(T &num){

    int i = -1;

    while ((unsigned int)++i < num.size() - 1)
    {
        if (num[i] > num[i + 1])
            return (0);
    }
    return (1);
}

#endif

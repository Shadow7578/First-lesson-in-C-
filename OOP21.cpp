#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

/*
Дан вектор целых чисел. Используя алгоритмы STL (без циклов и индексов), найдите сумму всех элементов,
произведение всех четных элементов и количество элементов, больших 10.
*/


int main()
{
    std::vector<int> v = { 12,2,11,13,-5,17 };

    int sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << "Summ: " << sum << std::endl;

    int cnt_bigger_than_10 = std::count_if(v.begin(), v.end(), [](int x) {
        return x >10;
        });
    std::cout << "Number of digits greater than 10: " << cnt_bigger_than_10 << std::endl;

    std::vector<int> even_numbers;
    std::copy_if(v.begin(), v.end(), std::back_inserter(even_numbers),
        [](int x) { return (x % 2 == 0) && (x!=0); });
    int product = std::accumulate(even_numbers.begin(), even_numbers.end(), 1, std::multiplies<int>());
    std::cout << "Product: " << product << std::endl;
}


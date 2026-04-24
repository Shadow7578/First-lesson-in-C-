
#include <iostream>
#include<set>


int main()
{
    //sort arrey, exlude dublicated, calculate amount using trees
    int arr[]{ 2, 4, 8, 1, 6, 8, 7, 9, 4, 6, 8, 9, 1 };

    std::set<int> t1{ arr, arr + sizeof(arr) / sizeof(arr[0]) };

    for (auto& elem : t1) {
        std::cout << elem << " ";

    }

    std::cout << "\nclear arrey contains: " << t1.size();
}
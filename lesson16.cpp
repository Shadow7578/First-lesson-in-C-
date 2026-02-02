
#include <iostream>



void print_arrey(int* begin, int* end) {
    for (; begin < end; begin++)
        std::cout << *begin << " ";
}


int* liner_search(int* arr, int* end, int key) {
    for (; arr < end; arr++)
        if (*arr == key)
            return arr;
    return 0;
}

int* find_max(int* arr, int* end) {
    int* max = arr;
    
    for (; arr < end; arr++)
        if (*arr > *max)
            max = arr;
    return max;

}




void summ_even_value(int *arr, int *end, int *summ) {
    *summ = 0;
    
    for (; arr < end; arr++)
        if (*arr %2 == 0)
            *summ += *arr;
}

int main()
{

    const int SIZE = 10;
    int arr[SIZE] { 1, 2, 3, 4, 5, 6, 12, 8, 9, 10 };
    int key = 8;

    print_arrey(arr, arr+SIZE);
    std::cout << std::endl;

    int* search_ptr = liner_search(arr, arr + SIZE, key);

    std::cout << search_ptr << "\n";
    
    if (search_ptr == 0)
        std::cout << "no key is fount" << "\n";
    else 
        std::cout << *search_ptr << "\n";


    
    int* max_ptr = find_max(arr, arr + SIZE);

    std::cout << max_ptr << "  " << *max_ptr << "\n";



    int summ = 0;
    summ_even_value(arr, arr + SIZE, &summ);
    std::cout << summ << "\n";


}


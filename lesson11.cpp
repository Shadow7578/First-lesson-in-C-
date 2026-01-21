

#include <iostream>



//void gen_array(int arr[], int size, int min, int max);
//void gen_array(double arr[], int size, double min, double max);
//void gen_array(char arr[], int size, char min, char max);

template <typename T>
void gen_array(T arr[], int size, T min, T max);

//void print_array(int arr[], int size);
//void print_array(double arr[], int size);
//void print_array(char arr[], int size);

template <typename T>
void print_array(T arr[], int size);

//int lin_search(int arr[], int size, int key);
//int lin_search(double arr[], int size, double key);
//int lin_search(char arr[], int size, char key);

template <typename T>
int lin_search(T arr[], int size, T key);



int main()
{
    const int SIZE = 30;
    int arr_int[SIZE];
    double arr_double[SIZE];
    char arr_char[SIZE];
    int min = 11;
    int max = 127;
    int key = 20;
    
    gen_array(arr_int, SIZE, min, max);
    gen_array(arr_double, SIZE, min, max);
    gen_array(arr_char, SIZE, min, max);

    print_array(arr_int, SIZE);
    std::cout << std::endl << std::endl;
    print_array(arr_double, SIZE);
    std::cout << std::endl << std::endl;
    print_array(arr_char, SIZE);
    std::cout << std::endl << std::endl;

    if (lin_search(arr_int, SIZE, key) > (-1))
        std::cout << "Index of " << key << " is: " << lin_search(arr_int, SIZE, key);
    else
        std::cout << "Key value/character has not been found";
    std::cout << std::endl << std::endl;


    if (lin_search(arr_double, SIZE, key) > (- 1))
        std::cout << "Index of " << key << " is: " << lin_search(arr_double, SIZE, key);
    else
        std::cout << "Key value/character has not been found";
    std::cout << std::endl << std::endl;


    if (lin_search(arr_char, SIZE, key) > (- 1))
        std::cout << "Index of " << key << " is: " << lin_search(arr_char, SIZE, key);
    else
        std::cout << "Key value/character has not been found";
    std::cout << std::endl << std::endl;
}




//void gen_array(int arr[], int size, int min, int max)
//{
//    int start_i = min;
//    int end_i = max;
//    for (int i = 0; i < size; ++i)
//    {
//        arr[i] = rand() % (start_i - (end_i + 1)) + start_i;
//    }
//}
//
//void print_array(int arr[], int size) {
//    for (int i = 0; i < size; ++i) {
//        std::cout << arr[i] << " ";
//    }
//    std::cout << std::endl;
//}
//
//int lin_search(int arr[], int size, int key)
//{
//    for (int i = 0; i < size; i++)
//    {
//        if (arr[i] == key)
//            return i;
//    }
//    return -1;
//}
//
//
//
//
//
//
//void gen_array(double arr[], int size, double min, double max)
//{
//    int start_i = min;
//    int end_i = max;
//    for (int i = 0; i < size; ++i)
//    {
//        arr[i] = rand() % (start_i - (end_i + 1)) + start_i + ( (rand()%1000) / (double)1000);
//    }
//}
//
//void print_array(double arr[], int size) {
//    for (int i = 0; i < size; ++i) {
//        std::cout << arr[i] << " ";
//    }
//    std::cout << std::endl;
//}
//
//int lin_search(double arr[], int size, double key)
//{
//    for (int i = 0; i < size; ++i)
//    {
//        if (arr[i] == key)
//            return i;
//    }
//    return -1;
//}
//
//
//
//
//
//
//
//void gen_array(char arr[], int size, char min, char max)
//{
//    int start_i = min;
//    int end_i = max;
//    for (int i = 0; i < size; ++i)
//    {
//        arr[i] = rand() % (start_i - (end_i + 1)) + start_i;
//    }
//}
//
//void print_array(char arr[], int size) {
//    for (int i = 0; i < size; ++i) {
//        std::cout << arr[i] << " ";
//    }
//    std::cout << std::endl;
//}
//
//int lin_search(char arr[], int size, char key)
//{
//    for (int i = 0; i < size; ++i)
//    {
//        if (arr[i] == key)
//            return i;
//    }
//    return -1;
//}


template <typename T>
void gen_array(T arr[], int size, T min, T max)
{
    T start_i = min;
    T end_i = max;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = rand() % (start_i - (end_i + 1)) + start_i;
    }
}

template <typename T>
void print_array(T arr[], int size) {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }


template <typename T>
int lin_search(T arr[], int size, T key)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}
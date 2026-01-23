

#include <iostream>

template <typename T>
void print_array(T arr[], int size);

template <typename T>
void shift_r(T arr[], int size, int shift);

template <typename T>
void shift_l(T arr[], int size, int shift);

template <typename T, int rows, int cols>
void gen_array(T arr[rows][cols]);

template <typename T, int rows, int cols>
void print_array(T arr[rows][cols]);

template <typename T, int rows, int cols>
T get_max(T arr[rows][cols]);


int main()
{
    /*const int R = 10;
    const int C = 10;
    int arr_i[R][C]{};
    double arr_d[R][C]{};

    gen_array<int, R, C>(arr_i);
    print_array<int, R, C>(arr_i);
    std::cout << "\n Max is: " << get_max<int, R,C>(arr_i);

    std::cout << "\n\n";

    gen_array<double, R, C>(arr_d);
    print_array<double, R, C>(arr_d);
    std::cout << "\n Max is: " << get_max<double, R, C>(arr_d);*/


    int arr[10]{ 1,2,3,4,5,6,7,8,9,10 };
    print_array(arr, 10);
    shift_r(arr, 10, 1);
    print_array(arr, 10);

    shift_l(arr, 10, 2);
    print_array(arr, 10);
    




}


template <typename T>
void print_array(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}



template <typename T>
void shift_r(T arr[], int size, int shift) {
    for (int i = 0; i < shift; ++i) {
        T last = arr[size - 1];
        
        for (int j = size - 2; j >= 0; j--) {
            arr[j + 1] = arr[j];
        }
        
        arr[0] = last;
    }
}

template <typename T>
void shift_l(T arr[], int size, int shift) {
    for (int i = 0; i < shift; ++i) {
        T first = arr[0];

        for (int j = 1; j < size; j++) {
            arr[j - 1] = arr[j];
        }

        arr[size-1] = first;
    }
}



template <typename T, int rows, int cols>
void gen_array(T arr[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = rand() % 101 + ((rand() % 101)/100.0);
        }
    }
}

template <typename T, int rows, int cols>
void print_array(T arr[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }
}


template <typename T, int rows, int cols>
T get_max(T arr[rows][cols]) {
    T max = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}



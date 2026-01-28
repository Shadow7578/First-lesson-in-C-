#include <iostream>

template <typename T>
void gen_array(T arr[], int size);

template <>
void gen_array(char arr[], int size);

template <typename T>
void print_array(T arr[], int size);

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // Текущий элемент для вставки
        int j = i - 1;

        // Сдвигаем элементы больше key вправо
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;  // Вставляем key в правильную позицию
    }
}

int BinarySearch(int arr[], int end, int Key) {
    int start = 0;
    int count = 0;
    while (true) {
        int M = (start + end) / 2;
        count++;
        if (Key < arr[M])
            end = M - 1;
        else
            if (Key > arr[M])
                start = M + 1;
            else {
                std::cout << " count = " << count << std::endl;
                return M;

            }
        if (start > end) {
            std::cout << " count = " << count << std::endl;
            return -1;
        }
    }
}

void requr_star (int count, int amount ) 
{
    if (count == amount)
        return;

    std::cout << "*\n";
    
    requr_star(count+1, amount);

}


int main()
{
    srand(time(NULL));

    /*const int SIZE = 20;
    int arr[SIZE];


    gen_array(arr, SIZE);
    print_array(arr, SIZE);
    std::cout << "\n----------------------\n";
    insertionSort(arr, SIZE);
    std::cout << "\n-----------------------\n";
    print_array(arr, SIZE);
    while (1) {
        int key;
        std::cout << "Enter key :";
        std::cin >> key;

        int ind = BinarySearch(arr, SIZE - 1, key);
        if (ind == -1)
            std::cout << "NOT\n";
        else
            std::cout << "YES " << ind + 1 << std::endl;
    }*/


    /*const int SIZE = 11;
    int arr[SIZE]{ 1,2,3,4,5,6,7,8,9,10, 11};
    int check[SIZE]{};
    int sum = 0;

    insertionSort(arr, SIZE);

    print_array(arr, SIZE);

    std::cout << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < SIZE; ++i)
    {
        if (i % 2)
        {
            check[i] = arr[i / 2];
        }
        else
        {
            check[i] = arr[(SIZE - 1) - i / 2];
        }        
    }

    // need to add summ formula 

    std::cout << "Your check is: ";
    print_array(check, SIZE); 
    std::cout << "\nTotal amount: " << sum;
    std::cout << std::endl;*/

    /*const int SIZE = 10;
    int arr[SIZE]{};
    bool flag = 0;
    
    gen_array(arr, SIZE);

    print_array(arr, SIZE);

    for (int i = 0; i < SIZE - 1; ++i)
    {
        if (arr[i] > arr[i + 1])
        {
            std::cout << "First one to be smaller: " << i + 2;
            flag++;
            break;
        }
    }

    if (flag)
    {}
    else
        std::cout << "OK";*/


    requr_star(0, 10);


}


template <typename T>
void gen_array(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 101 + (rand() % 101) / 100.0;
    }
}

template <>
void gen_array(char arr[], int size) {
    std::cout << "Gen for char \n";
    for (int i = 0; i < size; ++i) {
        if (rand() % 2) {
            arr[i] = 'A' + rand() % ('Z' - 'A' + 1);
        }
        else {
            arr[i] = 'a' + rand() % ('z' - 'a' + 1);
        }

        arr[i] = ('A' + rand() % ('Z' - 'A' + 1)) + (('a' - 'A') * rand() % 2);
    }
}

template <typename T>
void print_array(T arr[], int size) {

    /*std::cout << sizeof(arr) << " "
        << typeid(arr[0]).name() << std::endl;*/

    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << "  ";
    }
    std::cout << std::endl;
}












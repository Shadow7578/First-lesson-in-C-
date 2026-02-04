#include <iostream>


int* create_array(int* size) {
    std::cout << "Enter size for array ";
    std::cin >> *size;

    if (*size <= 0) {
        *size = 0;
        return nullptr;
    }
    //int* t = new int[*size] ;
    //return t;

    return new int[*size];
}

//void print_array(int *arr, int size); 
//void print_array(int arr[], int size);

void print_array(int* begin, int* end) {

    for (;begin < end; begin++) {
        std::cout << *begin << " ";
    }
    std::cout << "\n";
}


void gen_array(int* begin, int* end) {

    for (int i=1 ;begin < end; begin++, i++) {
        *begin = i;        
    }
}


void reverse_array(int* begin, int* end) {
    end--;
    for (; begin < end; begin++, end--) {
        /*int mem = *begin;
        *begin = *(end);
        *(end) = mem;*/
        std::swap(*begin, *end);
    
    }
}

int* resize_plus(int* arr, int size, int new_size) {
    /*int* ptr = new int[new_size];

    for (int i = 0; i < new_size; i++)
        if (new_size > size)
            ptr[i] = 0;
        else
            ptr[i] = arr[i];*/

    
    int* ptr = new int[new_size] {};
    for (int i = 0; i<size; i++)
        ptr[i] = arr[i];

    delete[] arr;

    return ptr;
}

int* resize_minus(int* arr, int size, int new_size) {
    int* ptr = new int[new_size] {};
    for (int i = 0; i < new_size; i++)
        ptr[i] = arr[i];

    delete[] arr;

    return ptr;
}


int* resize_array(int* arr, int size, int new_size) {
    int* ptr = new int[new_size] {};
    for (int i = 0; i < new_size && i < size; i++)
        ptr[i] = arr[i];

    delete[] arr;

    return ptr;
}

void fill_array(int* begin, int* end) {

    for (int i = 1;begin < end; begin++, i++) {
        *begin = rand() % 1000;
    }
}


int count_of_even(int* begin, int* end) {
    int counter{};
    for (;begin < end; begin++) {
        if (*begin % 2 == 0)
            counter++;
    }
    return counter;
}

int* create_even_array(int* size, int* arr1, int* end1, int* arr2, int* end2) {  
    
    if (*size <= 0) {
        *size = 0;
        return nullptr;
    }
    int* ptr = new int[*size] ;
    
    int count=0;
    for (int i=0; &arr1[i] < end1; i++){ 
        if (arr1[i] % 2 == 0) {
            ptr[count] = arr1[i];
            count++;
        }
    }

    for (int i = 0; &arr2[i] < end2; i++) {
        if (arr2[i] % 2 == 0) {
            ptr[count] = arr2[i];
            count++;
        }
    }

    return ptr;
}








int main()
{
    srand(time(NULL));
    int size1{};
    int size2{};
    int* arr1 = create_array(&size1);
    int* arr2 = create_array(&size2);

    fill_array(arr1, arr1+size1);
    fill_array(arr2, arr2+size2);

    print_array(arr1, arr1 + size1);
    std::cout << std::endl;
    print_array(arr2, arr2 + size2);
    std::cout << std::endl;

    int even_count1 = count_of_even(arr1, arr1 + size1);
    int even_count2 = count_of_even(arr2, arr2 + size2);

    int size3 = even_count1 + even_count2;

    int* even_arr = create_even_array(&size3, arr1, arr1 + size1, arr2, arr2 + size2);
    print_array(even_arr, even_arr+size3);








    //int size{};
    //int* arr = create_array(&size);
    //gen_array(arr, arr + size);
    //print_array(arr, arr + size);
    //reverse_array(arr, arr + size);
    //print_array(arr, arr + size);

    ///*int new_size = size + 10;
    //arr = resize_plus(arr, size, new_size);
    //size = new_size;
    //print_array(arr, arr + size);*/

    //arr = resize_array(arr, size, size+10);
    //size += 10;
    //print_array(arr, arr + size);

    //arr = resize_array(arr, size, size - 10);
    //size -= 10;
    //print_array(arr, arr + size);




    

    /*int a[10] = { 1,2,3,4,5,6,7,8,9,10 };

    int *p = a;

    std::cout << *(p+0) << std::endl;
    std::cout << p[0] << std::endl;


    p++;
    p++;

    std::cout << *(p - 2) << std::endl;
    std::cout << p[-2] << std::endl;*/

    //short value{ 7 };      // &value = 0012FF60
    //short otherValue{ 3 }; // &otherValue = 0012FF54

    //short* ptr{ &value };

    //std::cout << &value << '\n';  // 0012FF60
    //std::cout << value << '\n';   //  7
    //std::cout << ptr << '\n';     // 0012FF60
    //std::cout << *ptr << '\n';    //  7 
    //std::cout << '\n';

    //*ptr = 9;

    //std::cout << &value << '\n';  // 0012FF60
    //std::cout << value << '\n';   // 7   9 
    //std::cout << ptr << '\n';     // 0012FF60
    //std::cout << *ptr << '\n';    // 9 
    //std::cout << '\n';

    //ptr = &otherValue;

    //std::cout << &otherValue << '\n';  // 0012FF54
    //std::cout << otherValue << '\n';   // 3 
    //std::cout << ptr << '\n';          // 0012FF54
    //std::cout << *ptr << '\n';         // 3   9 
    //std::cout << '\n';

    //std::cout << sizeof(ptr) << '\n';   //  8
    //std::cout << sizeof(*ptr) << '\n';  //  2

}


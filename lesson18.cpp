#include <iostream>



/*
int* create_array(size_t& size) {
    std::cout << "Enter size for array ";
    std::cin >> size;

    if (size <= 0) {
        size = 0;
        return nullptr;
    }
    return new int[size];
}*/


//template <typename T>
//int create_array(T* &arr) {
//    int size;
//    std::cout << "Enter size for array ";
//    std::cin >> size;
//
//    if (size <= 0) {
//        arr = nullptr;
//        return 0;
//    }
//    arr = new T[size] {};
//    return size;
//}
//
//template <typename T>
//void print_array(T* begin, T* end) {
//
//    for (;begin < end; begin++) {
//        std::cout << typeid(*begin).name() << " ";
//    }
//    std::cout << "\n";
//}

int get_str_len(char* str) {
    int count = 0; 
    for (; *str != '\0'; str++)
        count++;
    return count;
}



int numbers_in_str(char* str) {
    int count = 0;
    for (; *str != '\0'; str++) {
        if (*str >= '0' && *str <= '9')
            count++;
    }
    return count;
}


int special_char_in_str(char* str) {
    int count = 0;
    for (; *str != '\0'; str++) {
        if ((*str >= '0' && *str <= '9') ||
            (*str >= 'A' && *str <= 'Z') ||
            (*str >= 'a' && *str <= 'z') ||
            *str == ' ')
            continue;

        count++;
    }
    return count;
}



char*  remove_numbers_from_str(char* str) {         //Hello123!! i3 love4 y1o9u8!2!
    int size = get_str_len(str);
    int c = numbers_in_str(str);
    char* arr = new char[size + 1 - c] {};
    for (int i = 0; *str != '\0'; str++) {
        if (*str >= '0' && *str <= '9')
            continue;
        arr[i] = *str;
        i++;
        
    }
    return arr;
}

bool is_palindrome(char *str) {
    int size = get_str_len(str);
    for (char* end = str + (size - 1); str < end; str++, end--) {
        if (*str != *end)
            return false;
    }
    return true;
}

int main() {


    //char arr[] = { 'C','a','t', '\0' };

    //for (int i = 0; i < 4; ++i)
    //    std::cout << arr[i] << " ";
    //std::cout << std::endl;

    //std::cout << arr << std::endl;

    //char str1[]{ "Cat" };
    //char str[]{ "Shumakov   Konstantin!" };

    //std::cout << str << std::endl;
    //std::cout << str1 << std::endl;
    //std::cout << &str[11] << std::endl;

    //str[11] = 'S';
    //std::cout << str << std::endl;

    //const char* str_const1 = "sdvgffgkldsdsdsf";
    ////str_const1[0] = 's';

    //std::cout << str_const1 << std::endl;



    /*char str_enter[100];
    std::cout << "Enter string 1: ";
    std::cin.getline(str_enter, 100);

    int delta = get_str_len(str_enter);

    str_enter[delta] = ' ';
    delta++;

    std::cout << "Enter string 2: ";
    std::cin.getline(str_enter + delta, 100-delta);


    for (int i = 0; str_enter[i] != '\0';i++)
        std::cout << str_enter[i] << '.';

    std::cout << std::endl;*/



    char str_enter[100];
    std::cout << "Enter string: ";
    std::cin.getline(str_enter, 100);

    std::cout << std::endl;

    /*std::cout << numbers_in_str(str_enter) << std::endl;
    std::cout << special_char_in_str(str_enter) << std::endl;
    std::cout << remove_numbers_from_str(str_enter) << std::endl;*/

    std::cout << is_palindrome(str_enter) << std::endl;



    /* bool* p{};
     std::cout << p << std::endl;
     int size = create_array(p);
     std::cout << p << std::endl;
     print_array(p, p + size);

     int a, b;

     std::swap(a,b);*/

     //int* p = create_array(size);



}

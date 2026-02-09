

#include <iostream>


void print_str(const char* str) {
    for (int i = 0; str[i] != '\0'; ++i)
        std::cout << str[i];
    std::cout << "\n";
}

char* short_FIO(char* str) {
    char* shortFIO = new char[255] {};
    int i = 0;
    int j = 0;
    for (; str[i] != ' '; ++i, ++j)
        shortFIO[j] = str[i];
    i++;
    shortFIO[j] = ' ';
    j++;
    shortFIO[j] = str[i];
    j++;
    shortFIO[j] = '.';
    j++;

    for (; str[i] != ' '; ++i) {}
    i++;
    shortFIO[j] = str[i];
    j++;
    shortFIO[j] = '.';
    j++;
        
    return shortFIO;
}

int main()
{
    //user inpiut first name midlle name and last name, program shoud return first name and abbriviations.
    std::cout << "Enter first name, midlle name and last name: \n";
    char* ptr_FIO = new char{};
    std::cin.getline(ptr_FIO, 255);

    char* ptr_shortFIO = short_FIO(ptr_FIO);
    print_str(ptr_shortFIO);



}


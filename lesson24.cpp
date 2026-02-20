
//learning union. task: decode every bite of int

//union decode {
//    int a=0;
//    char arr[sizeof(a)];
//};
//
//int main()
//{
//    decode b{};
//
//    b.a = 32768;
//    for (int i = 0; i < sizeof (decode); ++i)
//        std::cout << int (b.arr[i]) << "\n";
//}




//learnin files in C


#include <iostream>
#include <vector>
#include <stdio.h>

//https://learn.microsoft.com/ru-ru/cpp/c-runtime-library/reference/fopen-s-wfopen-s?view=msvc-170

//https://learn.microsoft.com/ru-ru/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-170

void print_error(int err) {

    switch (err)
    {
    case 2:
        std::cout << "Отсутствует такой файл или каталог. " << "\n";
        break;
    case 13:
        std::cout << "в разрешении отказано.  " << "\n";
        break;
    default:
        std::cout << "Ошибка неизвестна!  " << "\n";
        break;
    }
}

FILE* open_file(const char* path, const char* mode) {

    FILE* in;

    int err = fopen_s(&in, path, mode);

    if (err != 0) {
        std::cout << "Ошибка открытия файла " << path << "\n";
        print_error(err);
        return nullptr;
    }
    return in;
}

void read_file_as_str(FILE* in) {

    const size_t kSizeBuff = 1000;
    char buf[kSizeBuff];

    while (!feof(in)) {
        fgets(buf, kSizeBuff, in);
        std::cout << buf;
    }

}

void write_in_file(FILE* in) {
    std::cout << "White a string and press ENTER to write new string. To exit - write 0 and press ENTER\n";
    const size_t kSize = 1000;
    char str[kSize]{};
    while (1) {
        std::cin.getline(str, kSize);
        if (strcmp(str, "0") == 0)
            break;
        fputs(str, in);
        fputs("\n", in);
        

    }
   
}


int main() {

    setlocale(LC_ALL, "Ru");

    char str[]{ "My Message! \n" };

    const char* path = "data1.txt";
    FILE* in = open_file(path, "w");
    
    if (in) {
        /*fputs(str, in);
        fputs(str, in);
        fputs(str, in);
        fputs(str, in);
        fputs(str, in);*/
        write_in_file(in);
        fclose(in);
    }

    in = open_file(path, "r");

    if (in) {
        read_file_as_str(in);
        fclose(in);
    }

    /*const size_t kSizeBuff = 1000;
    char buf[kSizeBuff];


    const char* path = "data.txt";


    FILE* in = open_file(path, "r");

    if (in){
        read_file_as_str(in);
        fclose(in);
    }*/
}

#include <iostream>
#include <stdio.h>
#include <errno.h>

struct Point {
    int x = 0;
    int y = 0;
};


void print_error(errno_t err) {
    /*
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
        */

    switch (err)
    {
    case EINVAL:
        std::cout << "Причина: неверный аргумент (NULL/неверный режим/битые параметры).\n";
        //fprintf(stderr, "Что делать: проверьте указатели, строку mode (например \"r\", \"rb\", \"w\" и т.п.).\n");
        break;

    case ENOENT:
        std::cout << "Причина: файл или путь не существует.\n";
        //fprintf(stderr, "Что делать: проверьте имя файла, текущую директорию, абсолютный/относительный путь.\n");
        break;

    case EACCES:
        std::cout << "Причина: нет прав доступа или файл заблокирован.\n";
        //fprintf(stderr, "Что делать: проверьте права, атрибут 'read-only', не открыт ли файл другим процессом.\n");
        break;

    case EMFILE:
        std::cout << "Причина: слишком много открытых файлов в процессе.\n";
        //fprintf(stderr, "Что делать: закройте ненужные FILE* через fclose(), проверьте утечки.\n");
        break;

    case ENFILE:
        std::cout << "Причина: достигнут системный лимит открытых файлов.\n";
        //fprintf(stderr, "Что делать: закройте файлы, проверьте лимиты ОС.\n");
        break;

    default:
        std::cout << "Причина: другая ошибка код  = " << (int)err << "\n";
        //fprintf(stderr, "Что делать: ориентируйтесь по тексту ошибки выше.\n");
        break;
    }
}

FILE* open_file(const char* path, const char* mode) {

    FILE* in;

    errno_t err = fopen_s(&in, path, mode);

    if (err != 0) {
        std::cout << "Ошибка открытия файла " << path << "\n";
        print_error(err);
        return nullptr;
    }
    return in;
}

void write_file_v1(FILE* in) {

    const size_t kSizeBuff = 1000;
    char buf[kSizeBuff];

    while (true) {
        std::cout << "Enter string:";
        std::cin.getline(buf, kSizeBuff);

        if (strcmp(buf, "0") == 0)
            break;

        fputs(buf, in);
        fputs("\n", in);
    }
}


void write_file(FILE* in) {

    while (true) {

        std::cout << "Enter symb:";
        char symb;
        std::cin >> symb;

        if (symb == '0')
            break;

        fputc(symb, in);
        fputc('\n', in);
    }
}

void read_file_as_str(FILE* in) {

    const size_t kSizeBuff = 1000;
    char buf[kSizeBuff];

    while (!feof(in)) {
        if (fgets(buf, kSizeBuff, in)) {
            std::cout << "!" << buf;
        }
    }
}


void read_file(FILE* in) {

    /*while (!feof(in)) {
        int symb = fgetc(in);
        if (symb != EOF)
            std::cout << (char)symb;
    }*/

    while (true) {
        int symb = fgetc(in);
        if (symb == EOF)
            break;
        std::cout << (char)symb;
    }

}


void write_point(FILE* in, const Point& p) {
    /*char str[]{ "coordinates of point: " };
    char buf[10];

    fputs(str, in);
    fputc('(', in);

    _itoa_s(p.x, buf, 10);
    fputs(buf, in);
    fputc(',', in);

    _itoa_s(p.y, buf, 10);
    fputs(buf, in);
    fputc(')', in);*/

    fprintf(in, "coordinates of point: (%d,%d)\n", p.x, p.y);
}



Point read_point(FILE* in) {
   /* char buf[100];
    fgets(buf, 10, in);
    char numbrs[100];
    for (int i = 0, j = 0; i < 100; i++)
    {
        if (buf[i] >= '0' || buf[i] <= '9')
        {
            buf[i] = numbrs[j];
            j++;
        }
        if (buf[i] == ',') 
        {
            numbrs[j] = ',';
            j++;
        }
    }
    int x;                  // ran out of time to finish this methode.
    return 0;*/


    Point p{};
    fscanf_s(in, "coordinates of point: (%d,%d)\n", &(p.x), &(p.y));
    return p;
}



int main()
{
    Point p{ 10 , 20 };
    FILE* in = open_file("data.txt", "w");
    if (in) {
        write_point(in, p);
        fclose(in);
    }
    in = open_file("data2.txt", "r");
    if (in) {
        Point p2 = read_point(in);
        fclose(in);
        std::cout << "(" << p2.x << "," << p2.y << ")";
    }
    
}


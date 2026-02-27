#include <iostream>

struct Person{
    static const int LEN = 100;
    char name[LEN];
    int age{};

};

int main()
{
    Person arr[10]{ {"Andray", 65 },
                    {"Paul", 73 },
                    {"Ann", 3 },
                    {"Dmitry", 88 },
                    {"Anastatia", 10 },
                    {"Olga", 25 },
                    {"Vladimir", 34 },
                    {"Eugene", 42 },
                    {"Katya", 8 },
                    {"Eva", 12 } };


    char path[] = "PersonData.txt";
    FILE* db;
    
            //write
    if (fopen_s(&db, path, "wb") != 0) {
        std::cout << "ERROR";
    }
    else {
        fwrite(arr, sizeof(arr[0]), 10, db);
        fclose(db);
    }

            //read
    if (fopen_s(&db, path, "rb") != 0) {
        std::cout << "ERROR";
    }
    else {
        Person buff[10]{};
        fread(buff, sizeof(buff[0]), 10, db);
            for (int i = 0; i < 10; i++)
                std::cout << buff[i].name << " " << buff[i].age << "\n";
        fclose(db);
    }
}


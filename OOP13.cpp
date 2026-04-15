#include <iostream>
#include <fstream>
#include <string>





int main()
{
    std::string buf;
    std::ifstream file("source.txt");
    if (!file.is_open()) {
        std::cerr << "Open erorr" << std::endl;
        return 1;
    }
    std::getline(file, buf);
    file.close();

    for (int i = 0; buf[i] != 0; i++) {
        if (buf[i] == ' ') {
            buf[i] = '_';
        }

    }

    std::ofstream fin("dest.txt");
    if (!fin.is_open()) {
        std::cerr << "open Error" << std::endl;
        return 1;
    }
    fin << buf;
    fin.close();
}


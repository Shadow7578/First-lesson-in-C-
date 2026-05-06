#include <iostream>
#include<ostream>
#include<string>
#include<vector>
#include <algorithm>
#include<chrono>


/*

Дан вектор структур Book с полями

title (строка)

year (целое).

Отсортируйте книги по году издания (по возрастанию). Если годы совпадают – по названию (лексикографически). Выведите отсортированный список.
*/

struct Book {
    std::string title{};
    int year{};

    
};

std::ostream& operator << (std::ostream& o,const Book& b) {
    o << b.title << " of " << b.year;
    return o;
}

int main_1()
{
    std::vector<Book> vec {{"Artemida", 1968}, { "Benington", 2000 }, { "Evangelie", 1 }, { "War", 1945 }, {"Melenia", 2000}};

    for (auto& Book : vec) {
        std::cout << Book<< std::endl;
    }

    std::sort(vec.begin(), vec.end(),
        [](const Book& a, const Book& b) {
            if (a.year != b.year) return a.year < b.year;
            return a.title < b.title;
        });

    std::cout << "\n\n\n";

    for (auto& Book : vec) {
        std::cout << Book << std::endl;
    }

    return 0;
}














/*

Дан вектор строк.
Скопируйте только те строки, длина которых не превышает 3 символа, в новый вектор short_words.
Затем отсортируйте полученный вектор по алфавиту и удалите дубликаты.

*/



int main_2() {

    std::vector<std::string> vec{ "rec", "cor", "record", "abc", "earth", "core", "abc", "raz"};

    std::vector<std::string> short_words;


    /*std::unique_copy(vec.begin(), vec.end(), std::back_inserter(short_words),             //does not worck
        [](std::string& a, std::string& b) {
            return a.size() < 4;
        });*/

   std::copy_if(vec.begin(), vec.end(), std::back_inserter(short_words), 
        [](std::string s) {
            return s.size() < 4;
            });

    for (auto& string : short_words) {
        std::cout << string << std::endl;
    }

    std::sort(short_words.begin(), short_words.end());
    

    std::cout << "\n\n\n";
    for (auto& string : short_words) {
        std::cout << string << std::endl;
    }

    auto last = std::unique(short_words.begin(), short_words.end());
    short_words.erase(last, short_words.end());

    return 0;

}














/*
Дан вектор структур Point с полями x и y.
Создайте новый вектор distances, содержащий расстояния от каждой точки до начала координат (√(x²+y²)). Для вычисления корня используйте std::sqrt
*/

#include<cmath>


using namespace std::chrono;
using namespace std::chrono_literals;


class STimer {
    time_point<steady_clock> start, end;
    duration<float> delt;
public:
    STimer() {
        start = high_resolution_clock::now();
    }

    ~STimer() {
        end = high_resolution_clock::now();
        delt = end - start;
        auto result = duration_cast<milliseconds>(end - start).count();
        std::cout << " Time for programm runing is " << result << std::endl;

    }
};

struct Point {
    int x{};
    int y{};
};

int main() {
    std::vector < Point > vec{ {1,5}, {}, {3,1}, {22,34}, {-2,-5} };
    std::vector <double> distances;
    std::transform(vec.begin(), vec.end(), std::back_inserter(distances),
        [](const Point& a) {
            return std::sqrt((a.x * a.x) + (a.y * a.y)) ;
        });

    for (auto& d : distances) {
        std::cout << d << "\n";
    }
   
};
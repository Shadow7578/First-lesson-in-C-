

#include <iostream>

template <typename T>
using PrintOp = void(*)(const T&); // void name_func (const любой тип данных &)

template <typename T>
using CompareOp = bool(*)(const T&, const T&); // bool name_func (const любой тип данных& ,
//                 const любой тип данных& )

struct Point {
    int x = 0;
    int y = 0;
};

struct Person
{

    char name[100];
    int age{};

};

// ----------- ПРОТОТИПЫ -----------
// печать одного значения (шаблон + перегрузка для Point)
template <typename T>
void print_value(const T& v);

template <>
void print_value(const Point& p);

template <>
void print_value(const Person& p);

// печать массива
template <typename T>
void print_array(const T* arr, std::size_t size, PrintOp<T> printer);

// "нужно ли менять местами?" (шаблон + перегрузка для Point)
template <typename T>
bool compare_greater(const T& a, const T& b);

template <>
bool compare_greater(const Point& a, const Point& b);

template <>
bool compare_greater(const Person& a, const Person& b);

/*

template <typename T>
bool compare_less (const T& a, const T& b);

template <>
bool compare_less (const Point& a, const Point& b);

*/


// сортировка пузырьком
template <typename T>
void bubble_sort(T* arr, std::size_t size, CompareOp<T> need_swap);


//int main() {
//
//    int arr[10]{ 1,2,3,4,5,6,7,9,8,10 };
//    print_array(arr, 10, &print_value<int>);
//
//    double arrD[10]{ 1.67,2.89,3.11,4,5,6,7,8,9,10 };
//    print_array(arrD, 10, &print_value<double>);
//
//    Point points[10]{
//        {100,200}, {3,4}, {5,6}, {7,8}, {9,10},
//        {11,12}, {13,14}, {15,16}, {17,18}, {19,20}
//    };
//
//    print_array(points, 10, &print_value<Point>);
//
//    bubble_sort(arr, 10, &compare_greater<int>);
//    print_array(arr, 10, &print_value<int>);
//
//    bubble_sort(arrD, 10, &compare_greater<double>);
//    print_array(arrD, 10, &print_value<double>);
//
//    bubble_sort(points, 10, &compare_greater<Point>);
//    print_array(points, 10, &print_value<Point>);
//
//
//    Person persons[5]{ {"Ivan", 33},
//                        { "Tola", 13 },
//                        { "Janna", 23 },
//                        { "Petr", 55 },
//                        { "Misha", 99 } };
//
//    print_array(persons, 5, &print_value<Person>);
//    bubble_sort(persons, 5, &compare_greater<Person>);
//    std::cout << "\n\n";
//    print_array(persons, 5, &print_value<Person>);
//
//    return 0;
//}

// ----------- ОПРЕДЕЛЕНИЯ -----------
// печать одного значения
template <typename T>
void print_value(const T& v) {
    std::cout << v << ' ';
}

// перегрузка для Point
template <>
void print_value(const Point& p) {
    std::cout << '(' << p.x << ", " << p.y << ") ";
}

template <>
void print_value(const Person& p) {
    std::cout << p.name << "  age = " << p.age << "\n";
}

// печать массива
template <typename T>
void print_array(const T* arr, std::size_t size, PrintOp<T> printer) {
    for (std::size_t i = 0; i < size; ++i) {
        printer(arr[i]);
    }
    std::cout << '\n';
}

// сравнение: "нужно ли менять местами?"
template <typename T>
bool compare_greater(const T& a, const T& b) {
    return a > b;
}

// перегрузка для Point (сортируем по x)
template <>
bool compare_greater(const Point& a, const Point& b) {
    return a.x > b.x;
}

template <>
bool compare_greater(const Person& a, const Person& b) {
    return a.age > b.age;
}

// пузырьковая сортировка
template <typename T>
void bubble_sort(T* arr, std::size_t size, CompareOp<T> need_swap) {
    for (std::size_t i = 0; i + 1 < size; ++i) {
        bool swapped = false;

        for (std::size_t j = 0; j + 1 < size - i; ++j) {
            if (need_swap(arr[j], arr[j + 1])) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;
    }
}

struct Date {
    int day;
    int munth;
    int year;
};


void Analize_date(const Date& date) {
    switch (date.munth) {
    case 1:
    case 2:
    case 12:
        std::cout << "This person has been born in WINTER ";
        break;
    case 3:
    case 4:
    case 5:
        std::cout << "This person has been born in SPRING ";
        break;
    case 6:
    case 7:
    case 8:
        std::cout << "This person has been born in SUMMER ";
        break;
    case 9:
    case 10:
    case 11:
        std::cout << "This person has been born in AUTUMN ";
        break;
    }

    std::cout << "of the " << (date.year / 100) + (date.year %100 != 0) << "th centuary\n";
}

int main()
{
    Date Stalin{ 9, 12, 1871 };
    Date Andrey{ 11, 11, 1969 };
    Date Anastatia{ 6, 3, 2017 };
    Date The_Dude{ 1,1,1 };
    Date King{ 25,7,1600 };

    Analize_date(Stalin);
    Analize_date(Andrey);
    Analize_date(Anastatia);
    Analize_date(The_Dude);
    Analize_date(King);

    return 0;
}
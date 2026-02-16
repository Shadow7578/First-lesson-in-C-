
#include <iostream>

using Pred = bool (*)(int);

bool is_even(int x) { return ((x % 2) == 0); }
bool is_positive(int x) { return ( x > 0 ); }
bool is_neg(int x)  { return (x < 0); } 

int count_if(const int* a, int n, Pred pred) {
    int count = 0;
    for (int i = 0; i < n; i++)
        if (pred(a[i]))
            count++;

    return count;
}

int* copy_if(const int* a, int n, int& out_n, Pred pred) {
    // TODO
    out_n = 0;
    return nullptr;
}






struct Point_coordinates {
    int x{10};
    int y{20};
};

struct Line {
    Point_coordinates p1{};
    Point_coordinates p2{};
};

struct Circle {
    Point_coordinates c1{};
    int rad{};
};




void print_point(const Point_coordinates& p) {
    std::cout << "(" << p.x << ", " << p.y << ") " << std::endl;
}

void set_coordinates(Point_coordinates& p) {
    std::cout << "input coordinate x \n";
    std::cin >> p.x;
    std::cout << "input coordinate y \n";
    std::cin >> p.y;
}


void print_line(const Line& line) {
    print_point(line.p1);
    print_point(line.p2);
}

void set_line(Line& line) {
    set_coordinates(line.p1);
    set_coordinates(line.p2);
}









struct fraction {
    int numerator{};
    int denominator{};
};

void get_fraction(fraction& f) {
    std::cout << "inmput numerator: ";
    std::cin >> f.numerator;
    std::cout << "inmput denominator: ";
    std::cin >> f.denominator;
    while (f.denominator == 0) {
        std::cout << "Denominator cannot be 0! please try again";
        std::cin >> f.denominator;
    }
}

void print_fraction(const fraction& f) {
    std::cout << f.numerator << "/" << f.denominator;
}


fraction summ_fraction(const fraction f1, const fraction f2) {
    fraction res{};
    res.numerator = (f1.numerator * f2.denominator) + (f2.numerator * f1.denominator);
    res.denominator = f1.denominator * f2.denominator;

    return res;
}

int main()
{
    /*int arr[10]{ 1,2,3,4,5,6,7, -8, -9, -10 };

    std::cout << count_if(arr, 10, is_positive) << "\n";
    std::cout << count_if(arr, 10, is_neg) << "\n";
    std::cout << count_if(arr, 10, is_even) <<"\n";*/

    /*Point_coordinates a;
    std::cout << "(" << a.x << ", " << a.y << ")\n";

    Line line1{ {10, 20}, {30, 40} };
    std::cout << "(" << line1.p1.x << ", " << line1.p1.y << "), (" << line1.p2.x << ", " << line1.p2.y << ")\n";

    Circle circle1{ {10,20}, 30 };
    std::cout << "(" << circle1.c1.x << ", " << circle1.c1.y << "), radius = " << circle1.rad << "\n";*/



    /*Point_coordinates b;
    set_coordinates(b);
    print_point(b);*/

    /*Line line1{};
    set_line(line1);
    print_line(line1);*/


    /*fraction a;
    get_fraction(a);
    fraction b;
    get_fraction(b);*/



    fraction a{};
    fraction b{};
    get_fraction(a);
    get_fraction(b);
    fraction c = summ_fraction(a, b);
    print_fraction(c);


}


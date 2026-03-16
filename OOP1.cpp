#include <iostream>


class Point {

    int x = 0;
    int y = 0;

    int alpha = 1;

public:
    Point(int x, int y);

    void setX(int val) {
        if (val >= 100 && val <= 200)
            //x = val + alpha;
            x = val;
    }

    void setY(int val) {
        //y = val + alpha;
        y = val;
    }

    void setAlpha(int val) {
        //int delt = alpha - val;
        alpha = val;
        //x += delt;
        //y += delt;
    }

    int getAlpha() {
        return alpha;
    }

    int getX() {
        return x + alpha;
    }

    int getY() {
        return y + alpha;
    }

    void print();
    //void len();
    
};

void Point::print() {
    printf("( %d, %d )", x, y);
}


void print(Point& p) {
    printf("( %d, %d )", p.getX(), p.getY());
}

Point::Point(int x, int y) : x{ x }, y{ y } {}



class Person {
public:
    int age;
    char name[100];
    bool sex; //1-women, 0-men
    
    void setAge(int val);
    void setName(const char str[]);
    void setSex(bool s);

    void getInfo(char str[]);

private:
    int getAge();
    const char* getName();
    bool getSex();
};

void Person::setAge(int val) {
    if (val > 0 && val < 110)
        age = val;
};
void Person::setName(const char str[]) {
    /*int SIZE = sizeof str;
    for (int i = 0; i < SIZE; i++)
        name[i] = str[i];*/
    strcpy_s(name,100, str);
};
void Person::setSex(bool s) {
    sex = s;
};

void Person::getInfo(char str[]) {
    char s='m';
    if (sex)
        s = 'f';
    
    scanf_s(str, "%c, %d, %s", s, 1, age, name,100);
   

};


int Person::getAge() {
    return age;
};
const char* Person::getName() {
    return name;
};
bool Person::getSex() {
    return sex;
};







class Line {
    Point p1{ 0,0 };
    Point p2{ 0,0 };

public:
    Line(const Point& v1, const Point& v2) :p1 { v1 }, p2{ v2 }{}
    Line(int x1, int y1, int x2, int y2) : p1{ Point {x1,y1} }, p2{ Point {x2,y2} } {}
    void setLine(Point p1, Point p2, int x1, int y1, int x2, int y2);
    void print();
};

//void Line::setLine(Point p1, Point p2, int x1,int y1,int x2,int y2) {
//    p1.setX(x1);
//    p1.setY(y1);
//    p2.setX(x2);
//    p2.setY(y2);
//}

void Line::print() {
    //printf_s("(%d,%d) (%d,%d)", p1.getX(), p1.getY(), p2.getX(), p2.getY());
    p1.print();
    printf(" - ");
    p2.print();
    printf("\n");
}



int main()
{
    //class Point p { 10, 20 };
    //p.setX(110);
    //p.setY(20);
    //p.print();
    ////p.


    //Person citizen1;
    //citizen1.setAge(30);
    //citizen1.setName("Andrey");
    //citizen1.setSex(0);

    //char card1[100]{};
    //citizen1.getInfo(card1);

    //printf_s("\n%s", card1);




    Point p1 { 10,20 };
    Point p2 { 30,40 };
    
    Line l1 { p1,p2 };
    l1.print();
}
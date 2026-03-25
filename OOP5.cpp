#include <iostream>


class Money {

    friend bool operator == (const Money& m1, const Money& m2);
    friend bool operator != (const Money& m1, const Money& m2);
    friend bool operator < (const Money& m1, const Money& m2);
    friend bool operator > (const Money & m1, const Money & m2);
    friend bool operator <= (const Money& m1, const Money& m2);
    friend bool operator >= (const Money& m1, const Money& m2);
    
    int denormalize() const {
        return r * 100 + c;
    }

    void normalize(int t) {
        c = t % 100;
        r = t / 100;
    }

    int r;
    int c;

public:

    Money(int r, int c) : r{ r }, c{ c } {}

    void setR(int r) {
        this->r = r;
    }

    void setC(int c) {
        this->c = c;
    }

    int getR() const { return r; }
    int getC() const { return c; }

    void sum(const Money& o) {

        int t = denormalize();
        int t2 = o.denormalize();

        normalize(t + t2);
    }


    Money& operator+= (const Money& m) {
        int t = this->denormalize();
        int t2 = m.denormalize();
        normalize(t + t2);

        return *this;

    }

    Money& operator-= (const Money& m) {
        int t = this->denormalize();
        int t2 = m.denormalize();
        normalize(t - t2);

        return *this;

    }


    void sub(const Money& o) {

        int t = denormalize();
        int t2 = o.denormalize();

        normalize(t - t2);
    }

    void print() {
        printf(" %d,%d \n", r, c);
    }

};


Money operator+ (const Money& m1, const Money& m2) {
    Money m = m1;
    m += m2;
    return m;
}

Money operator+ (const Money& m1, const Money& m2) {
    Money m = m1;
    m -= m2;
    return m;
}

bool operator == (const Money& m1, const Money& m2) {
    //return m1.getR() == m2.getR() && m1.getC() == m2.getC();
    return m1.r == m2.r && m1.c == m2.c;
}

bool operator != (const Money & m1, const Money & m2) {
    return !(m1 == m2);
}

bool operator < (const Money& m1, const Money& m2) {
    if (m1.r == m2.r && m1.c < m2.c)
            return true;
    return (m1.r < m2.r);
    }





Money sum(const Money& m1, const Money& m2) {

    Money m = m1;
    m.sum(m2);
    return m;

}

int main()
{
    Money m1{ 1,40 };

    m1.print();

    Money m2{ 3,54 };

    m2.print();

    m2 += m1;
    m2.print();

    Money m3 = m1 + m2;

    m3.print();

    m3 += m2;

    m3.print();

    if (m1 == m2) {

    }

}


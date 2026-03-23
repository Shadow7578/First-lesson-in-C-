#include <iostream>


class Money {
    unsigned int rub;
    unsigned int cent;

public:
    int getRub()const;
    int getCent()const;
    void setRub(unsigned int val);
    void SetCent(unsigned int val);
    void print() const;

    ~Money();
    Money();
    explicit Money(unsigned int val1);
    Money(unsigned int val1, unsigned int val2);
    Money(const Money&);
    Money& operator=(const Money&);
    Money summ(const Money&, const Money&);
    Money sub(const Money&, const Money&);
};

int Money::getRub()const {
    return rub;
}
int Money::getCent()const {
    return cent;
}
void Money::setRub(unsigned int val){
    rub = val;
};
void Money::SetCent(unsigned int val) {
    cent = val;
};
void Money::print() const {
    printf("%d,%d\n", rub, cent);
}

Money::~Money() {
    printf("Destructing %p\n", this);
};
Money::Money() {
    printf("Creating %p\n", this);
};
Money::Money(unsigned int val1) : rub{ val1 }, cent{ 0 } {
    printf("Creating %p whith RUB\n", this);
};
Money::Money(unsigned int val1, unsigned int val2) : rub{ val1 }, cent{ val2 } {
    printf("Creating %p whith RUB and CENTS\n", this);
};
Money::Money(const Money& other) {
    printf("Copying %p from %p\n", this, &other);
    rub = other.rub;
    cent = other.cent;
};
Money& Money::operator=(const Money& other) {
    printf("Operator= %p from %p\n", this, &other);
    rub = other.rub;
    cent = other.cent;
    return *this;
}
Money Money::summ(const Money& m1, const Money& m2) {
    Money summ;
    summ.rub = m1.rub + m2.rub;
    summ.cent = m1.cent + m2.cent;
    return summ;
}

Money Money::sub(const Money& m1, const Money& m2) {
    Money sub;
    sub.rub = m1.rub - m2.rub;
    sub.cent = m1.cent - m2.cent;
    return sub;
}




int main()
{
    std::cout << "Hello World!\n";
}


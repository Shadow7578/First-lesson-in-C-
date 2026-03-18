#include <iostream>
class Counter {
    int value;
    void check();
    static int totalCount;
public:
    Counter(int v);
    Counter();
    int get();
    void set(int newValue);
    void increment();
    void decrement();
    ~Counter();
    static int getTotalCount();
};
int Counter::totalCount = 0;

void Counter::check() {
    if (value < 0)
        value = 0;
}

Counter::Counter() :Counter(0) {};
Counter::Counter(int v) : value{ v } {
    check();
    totalCount++;
};
int Counter::get() { return value; }

void Counter::set(int newValue) {
    value = newValue;
    check();
}

void Counter::increment() {
    value++;
}

void Counter::decrement() {
    value--;
    check();
}

Counter::~Counter() {
    std::cout << "Counter destroyed\n";
    totalCount--;
    std::cout << "total= " << Counter::getTotalCount() << std::endl;
}

int Counter::getTotalCount() { return totalCount; }






int main()
{
    std::cout << "total= " << Counter::getTotalCount() << std::endl;
    Counter c1;
    Counter c2{ 5 };
    std::cout << "total= " << Counter::getTotalCount() << std::endl;
    std::cout << c1.get() << "   " << c2.get() << std::endl << "---------\n";
    ;
    c1.decrement();
    c2.increment();
    std::cout << c1.get() << "   " << c2.get() << std::endl << "---------\n";
   
    c1.set(-10);
    c2.set(20);
    std::cout << c1.get() << "   " << c2.get() << std::endl << "---------\n";
    std::cout << "total= " << Counter::getTotalCount() << std::endl;
}

#include <iostream>

struct Animal { 
    bool flag{};
    virtual ~Animal() {} 
};



struct Dog : Animal { void bark() const { std::cout << "Woof!\n"; } };
struct Cat : Animal { 
    Cat() {
        flag = true;
    }
    void meow() const { std::cout << "Meow!\n"; }
};

void use(Animal* a) {
    if (a->flag==0)
        static_cast<Dog*>(a)->bark();
    else 
        static_cast<Cat*>(a)->meow();
}

void use2(Animal* a) {
    Dog* d = dynamic_cast<Dog*>(a);
    if (d)
        d->bark();
    Cat* c = dynamic_cast<Cat*>(a);
    if (c)
        c->meow();
}


int main()
{
    Dog* d = new Dog;
    Cat* c = new Cat;
   
    use(d);
    use(c);
}


#include <iostream>
#include <memory>
/*Напишите функцию create_large_object(), которая создаёт объект класса Large(конструктор принимает int id и std::string name)
и возвращает std::unique_ptr.Продемонстрируйте передачу этого указателя в другую функцию, которая принимает unique_ptr
по значению(забирает владение), и в функцию, которая только читает данные(используя сырой указатель или ссылку).*/



class Large {
    int id{};
    std::string name;
public:
    Large(int id, std::string name) : id{ id }, name{ name } {
        std::cout << "Large " << id << " " << name << " created\n";
    }

    ~Large() {
        std::cout << id << " " << name << " Destroyed\n";
    }
};

std::unique_ptr<Large> create_large_object(int id, std::string name) {
    std::unique_ptr<Large> u_ptr = std::make_unique<Large> (id, name);
    return u_ptr;
}


std::unique_ptr<Large> owner(std::unique_ptr<Large> old) {
    return old;
}

void print_ptr(std::unique_ptr<Large>& ptr) {
    std::cout << ptr.get() << "\n";
}

int main()
{
    std::unique_ptr<Large> ptr1{ create_large_object(1, "BigONE") };
    print_ptr(ptr1);
    ptr1 = owner(std::move(ptr1));
    
    
    std::cout << "===============================\n";

    std::unique_ptr<Large> ptr2{ create_large_object(2, "BigTWO") };
    std::unique_ptr<Large> ptr3{ create_large_object(3, "BigTHREE") };
    std::unique_ptr<Large> ptr4{ create_large_object(4, "BigFORE") };

}


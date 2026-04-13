
#include <iostream>




class Array {
    int* data;
    size_t size;
public:
    Array(size_t n) : size(n) {

        if (n == 0)
            throw std::invalid_argument("Размер массива должен быть > 0");


        data = new int[n] {};  // может бросить std::bad_alloc
    }
    ~Array() { delete[] data; }


    int& operator[] (unsigned int index) {
        if (index >= size) {
            throw std::out_of_range("Index not valid");
        }
        return data[index];
    }

    const int& operator[]  (unsigned int index) const {
        if (index >= size) {
            throw std::out_of_range("Index not valid");
        }
        return data[index];
    }


    void set_data(int index, int value) {
        if (index >= size) {
            throw std::out_of_range("Index not valid");
        }
        if (value < 100 || value > 200) {
            throw std::out_of_range("Value out of allowed range");
        }

        data[index] = value;
    }



};



int main()
{
    try {
        Array arr(10);
        arr.set_data(0, 100);
        arr.set_data(-1, 110);
        arr.set_data(2, 10);
        arr.set_data(3, 201);
    }
    catch (std::invalid_argument e) {
        std::cout << e.what();
    }
    catch (std::out_of_range e) {
        std::cout << e.what();
    };
}
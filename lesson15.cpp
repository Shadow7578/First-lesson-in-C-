
#include <iostream>


int value_reverse(int value);

void sum(int a, int b, int *s);


int main()
{
    //std::cout << value_reverse(1467);

    int a = 5;
    int b = 6;

    int s = 0;

    sum(a, b, &s);

    std::cout << s;
}



int value_reverse(int value) {

    int v = value % 10;
    if (v == 0)
        return v;
    
   int result = value_reverse(value / 10) * 10 + v;
    
    return result;
}

// i have failed.



void sum(int a, int b, int *s)
{
    *s = a + b;
}
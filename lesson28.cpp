

#include <iostream>
#include <bitset>


bool fridge_state()
{
    const long IS_ON = 0b00000001; //1
    const long IS_OFF = 0b00000010; //2
    const long FREEZ_ON = 0b00000100; //4
    const long FREEZ_OFF = 0b00001000;  //8
    const long ERROR = 0b00010000; //16

    std::cout << "input nuber from 1 to 31 to request fridge state\n";
    int state{};
    std::cin >> state;
    
    if (state <= 0 || state > 31) {
        std::cout << "invalid input, please try again\n";
        return 1;
    }


    if (state & IS_ON)
        printf("Fridge is ON\n");
    if (state & IS_OFF)
        printf("Fridge is OFF\n");
    if (state & FREEZ_ON)
        printf("Freezer is ON\n");
    if (state & FREEZ_OFF)
        printf("Freezer is OFF\n");
    if (state & ERROR)
        printf("ERROR\n");

    if ((state & IS_ON) && (state & IS_OFF))
        printf("ERROR, fridge can not be is ON and OFF state at the same time");
    
    return 0;
}




bool is_pow_of2(unsigned int a) {
    int size = sizeof(a) * 8;
    for (int i = 1; i <= size; i <<= 1)
        if (a == i)
            return true;
    return false;
}


unsigned int set_color() {
    int red{}, green{}, blue{};
    std::cout << "enter RED: \n";
    std::cin >> red;
    std::cout << "enter GREEN: \n";
    std::cin >> green;
    std::cout << "enter BLUE: \n";
    std::cin >> blue;

    unsigned int color = red;
    color <<= 8;
    color |= green;
    color <<= 8;
    color |= blue;


    return color;
}


void decode_color(unsigned int color) {
    unsigned int mask = 0x000000ff;
    unsigned int b = color & mask;
    color >>= 8;
    unsigned int g = color & mask;
    color >>= 8;
    unsigned int r = color & mask;

    printf("red = %d, green = %d, blue = %d", r, g, b);
}

int main()
{
    //basic programm about states of something
    //while (fridge_state());


    /*
     //in max int - make 0 out of bit number a
    int a{};
    std::cout << "enter number bit";
    std::cin >> a; //from 1 to 31;
    if (a < 1 || a > 31) {
        std::cout << "ERROR\n";
        system("pause");
        return 0;
    }
    int b = 0xffffffff;
    //std::cout << b << " " << std::bitset<sizeof(b) * 8>(b) << std::endl;

    int c = 1 << a-1;

    //std::cout << c << " " << std::bitset<sizeof(c) * 8>(c) << std::endl;

    b ^= c;

    std::cout << b << " " << std::bitset<sizeof(b)*8>(b) << std::endl;
    */




    /*
    //check if number is exactly power of 2

    unsigned int a{};  //no saftety for input, im lazy 
    std::cin >> a;
    std::cout << is_pow_of2(a);
    */



    //grate rgb decoding programm
    //std::cout << set_color() << std::endl;

    decode_color(set_color());
}


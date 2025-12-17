// lesson2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    /*
    int a, b;
    std::cout << "Iput A and B one ofter enother: \n";
    std::cin >> a >> b;
    if (a > b) 
    {
        std::cout << a << "A is bigger one";
    }
    else 
    {
        if (b > a)
        {
            std::cout << b << "B is bigger one";
        }
        else
        {
            std::cout << "they are equal";
        }
    }*/





   /* int x, y;
    std::cout << "Iput X and Y one ofter enother: \n";
    std::cin >> x >> y;
    if (x == 0 && y == 0)
    {
        std::cout << "the point is at 0";
    }
    else
    {
        if (x == 0 || y == 0)
        {
            if (x == 0)
            {
                std::cout << "the point is on X axis";
            }
            else
            {
                std::cout << "the point is on Y axis";
            }
        }
        else
        {
            if (x > 0)
            {
                if (y > 0)
                {
                    std::cout << "the point is at I quarter";
                }
                else
                {
                    std::cout << "the point is at IV quarter";
                }
            }
            else
            {
                if (y > 0)
                {
                    std::cout << "the point is at II quarter";
                }
                else
                {
                    std::cout << "the point is at III quarter";
                }
            }
        }
    }*/
    



    const char PLUS {'+'};
    const char MINUS{ '-' };
    const char DEV{ '/' };
    const char MULT{ '*' };
    double a, b, res;
    char action;
    std::cout << "Initialazing calculator...\n" << "Input first value: \n";
    std::cin >> a;
    std::cout << "Input second value: \n";
    std::cin >> b; 
    std::cout << "Choose action to perform ( "<< PLUS <<" "<< MINUS <<" "<< DEV <<" "<< MULT <<" ): \n";
    std::cin >> action;

    if (b == 0 && action == '/')
    {
        std::cout << "\n\tERROR \nDivision by 0 is impossible in this programm\n ";
        return 0;
    }
    else
    {
        switch (action)
        {
        case PLUS:
            res = a + b;
           // std::cout << "A + B = " << a + b;
            break;
        case MINUS:
            res = a - b;
           // std::cout << "A - B = " << a - b;
            break;
        case DEV:
            res = a / b;
           // std::cout << "A / B = " << a / b;
            break;
        case MULT:
            res = a * b;
           // std::cout << "A * B = " << a * b;
            break;
        default:
            std::cout << "\n\tERROR\n Wrong input\n";
            return 0;
        }
        std::cout << a << action << b << "=" << res;
    }








}


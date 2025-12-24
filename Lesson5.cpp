// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    /*const int SIZE = 11;
    char brush;
    std::cout << "enter symbol to paint with: ";
    std::cin >> brush;

    for (int i = 0; i < SIZE; i++)
    {
        
        for (int j = 0; j < SIZE; j++)
        {
            if (i == SIZE / 2 || j == SIZE/2)
                std::cout << brush;
                        else
            std::cout << " ";
        }
        std::cout << std::endl;

    }*/
 








    /*const int SIZE = 11;
    char brush;
    std::cout << "enter symbol to paint with: ";
    std::cin >> brush;

    for (int i = 0; i < SIZE; i++)
    {

        for (int j = 0; j < SIZE; j++)
        {
            if (i == SIZE / 2 || j == SIZE / 2 || i==j || i==(SIZE-1)-j)
                std::cout << brush;
            else
                std::cout << " ";
        }
        std::cout << std::endl;

    }*/








    /*const int SIZE = 11;
    
    for (int i = 0; i < SIZE; i++)
    {

        for (int j = 0; j < SIZE; j++)
        {

            if (i == SIZE / 2 && j == SIZE/2)
            {
                std::cout << "*"; //"+" looks better in center
                continue;
            }
            else if (i == SIZE / 2)
            {
                std::cout << "-";
                continue;
            }
            else if (j == SIZE / 2)
            {
                std::cout << "|";
                continue;
            }
            else if (i == j)
            {
                std::cout << "\\";
                continue;
            }
            else if (i == (SIZE-1)-j)
            {
                std::cout << "/";
                continue;
            }
            else
                std::cout << " ";
        }
        std::cout << std::endl;

    } */







    /*Programm to find averege*/

    double avrg{};
    int i{-1};
    double grade;
    std::cout << "Enter your grades one by one to find averege; Enter 0 to stop.\n";
    
    do {
        std::cin >> grade;
        if (grade < 0 || grade > 5 || (int)grade != grade)
            std::cout << "ERROR: grade can only be 1, 2, 3, 4, 5 or enter 0 to end the programm. Please try againt. \n";        
        else
        {
            avrg += grade;
            i++;
        }

        
    } while (grade != 0);

    std::cout << "Amount of grades: " << i << "\n";
    std::cout << "Averege: " << avrg/i << "\n";



}



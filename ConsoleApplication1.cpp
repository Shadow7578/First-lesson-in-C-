


#include <iostream>

int main()
{
    setlocale(LC_ALL, "RU");
    int grade_1, grade_2, grade_3, grade_4, grade_5;
    std::cout << "Ведите свои оценки последовательно, по одной, после каждой нажимайте Enter:\n";
    std::cout << "\tПервая оценка: ";
    std::cin >> grade_1;
    std::cout << "\tВторая оценка: ";
    std::cin >> grade_2;
    std::cout << "\tТретья оценка: ";
    std::cin >> grade_3;
    std::cout << "\tЧетвертая оценка: ";
    std::cin >> grade_4;
    std::cout << "\tПятая оценка: ";
    std::cin >> grade_5;
    std::cout << "\nВаш средний балл = " << (grade_1 + grade_2 + grade_3 + grade_4 + grade_5) / 5.0 << "\n\n";

    if (((grade_1 + grade_2 + grade_3 + grade_4 + grade_5)/5.0) >= 4.75)
    {
        std::cout << "Повышенная степендия";
    }
    else 
    {
       
        
        if (((grade_1 + grade_2 + grade_3 + grade_4 + grade_5) / 5.0) >= 3.65) 
        {
            std::cout << "степендия";
        }
        else
        {
            std::cout << "Нет степендии";
        }



    }

    /*int v;
    
    std::cout << "Ведите число для првоерки на четность: ";
    std::cin >> v;
    
    if (v%2 == 0)
    {
        std::cout << "Число четное";
    }
    else 
    {
        std::cout << "Число нечетное, проверка на кратность трём:\n";

        if (v % 3 == 0) 
        {
            std::cout << "Число кратно трём";
        }
        else 
        {
            std::cout << "Число не четное и не кратно трём";
        }
    }*/
}


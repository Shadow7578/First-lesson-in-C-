#include <iostream>


double to_the_power(double number, int power);
int summ_step (int, int);
double cyl_volume(double, double);
void gen_array(int arr[], int size, int min, int max);
void print_array(int arr[], int size);
void Bigger_than_K(int arr[], int size, int K);

int main()
{
    /*double number;
    int power;
    std::cout << "Input number to raise to a power: \n";
    std::cin >> number;
    std::cout << "\n Input power to raise number to: \n";
    std::cin >> power;
    std::cout << "\n The result is: " << to_the_power(number, power);*/

    /*int value1;
    int value2;
    std::cout << "Input value1: \n";
    std::cin >> value1;
    std::cout << "Input value2: \n";
    std::cin >> value2;
    std::cout << "\n The result is: " << summ_step(value1, value2);*/




   /* double R;
    double H;
    std::cout << "Input radius: \n";
    std::cin >> R;
    std::cout << "Input hight: \n";
    std::cin >> H;
    std::cout << "\n The cylinder volume is: " << cyl_volume(R, H);*/



    const int N = 10;
    int arr1[N];
    int min;
    int max;

    std::cout << "Input lowest number to randomly generate in the array: \n";
    std::cin >> min;
    std::cout << "Input highest number to randomly generate in the array: \n";
    std::cin >> max;
    gen_array(arr1, N, min, max);
    print_array(arr1, N);

    int K;
    std::cout << "Input lowest barier: \n";
    std::cin >> K;
    Bigger_than_K(arr1, N, K);



}

double to_the_power(double number, int power) {
    double result = 1;
    
    if (power >= 0)
    {
        for (int i = 0; i < power; i++)
            result *= number;
        return result;
    }
    else 
    {
        power = -power;
        for (int i = 0; i < power; i++)
            result *= number;
        return 1/result;
    }
}

int summ_step(int value1, int value2) 
{
    
    int result = 0;
    if (value1 <= value2)
    {
        for (int i = value1; i < value2; i++)
            result += i;            
        return result;
    }
    else
    {
        for (int i = value2; i < value1; i++)
            result += i;
        return result;
    }
}

double cyl_volume(double R, double H)
{
    const double Pi = 3.14159265359;
    double V = Pi * R * R * H;
    return V;
}






void gen_array(int arr[], int size, int min, int max) 
{
    int start_i = min;
    int end_i = max;
    for (int i = 0; i < size; ++i) 
    {
        arr[i] = rand() % (start_i - (end_i + 1)) + start_i;;
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void Bigger_than_K(int arr[], int size, int K) 
{
    for (int i = 0; i < size; ++i) 
    {
        if (arr[i] > K)
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}



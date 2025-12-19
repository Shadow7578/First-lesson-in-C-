// lesson3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
	/*int summ{}, n = 1, count = -1;
	std::cout << "Eneter any amount of regular numbers one by one to add them upp. To end the programm enter 0.\n";
	while (n != 0)
	{
		std::cin >> n;
		summ += n;
		count++;
	}
	std::cout << "you have entered " << count << " numbers\n" << "summ = " << summ;*/





	/*int amount, nomber = 0;
	char symb;

	std::cout << "Enter a symbol to print a line with: \n";
	std::cin >> symb;
	std::cout << "Enter the amount of times to print the symbol \n";
	std::cin >> amount;

	while (amount-- > 0)
	{
		std::cout << ++nomber <<symb << "\n";
	}*/



	int number{}, summ{};
	std::cout << "input a number to summ up it's individual numbers: \n";
	std::cin >> number;

	if (number < 0)
		number *= -1;
	while (number != 0)
	{
		summ += number % 10;
		number /= 10;
	}
	std::cout << "summ = " << summ;
}




#include <iostream>

int main()
{

												//find the product of the arrey

	/*const int SIZE {10};
	int product = 1;
	int m [SIZE];
	std::cout << "Please inpute whole walues for the array to find out there product \n" << "There are " << SIZE << " walues in the array \n";
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << "Inpit whole number " << (i + 1) << ": ";
		std::cin >> m[i];
		std::cout << std::endl;
		product *= m[i];
		if (m[i] == 0)
		{
			std::cout << "Factor " << (i+1) << " = 0; No further data entry required.\n";
				break;
		}
	}
	std::cout << "Product of the array = " << product;*/




								//find the averege grade of 32 students. Grades renge from 2 to 5.

	
	/*const int SIZE{ 32 };
	double avrg = 0;
	int grades[SIZE];

	srand(time(NULL));
	int start_i = 2;
	int end_i = 5;

	for (int i = 0; i < SIZE; i++)
	{
		grades[i] = rand() % (start_i - (end_i + 1)) + start_i;
		avrg += grades[i];
		std::cout << grades[i] << std::endl;
	}

	avrg /= SIZE;
	std::cout << "Average grade is " << avrg;*/





	// create an Array size of 20 with random values from 0 to 100 and show the array in order firs value to last, then last to first. 

	/*const int SIZE{ 20 };
	int m[SIZE];

	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
	{
		m[i] = rand() % 101;
		std::cout << m[i] << " ";
	}
	std::cout << std::endl;

	for (int i = SIZE-1; i >= 0; i--)
	{
		std::cout << m[i] << " ";
	}*/




						//same arrey size and range, finde smallest and biggest values

	/*const int SIZE{ 20 };
	int m[SIZE];
	int min = 100;
	int max = 0;

	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
	{
		m[i] = rand() % 101;
		std::cout << m[i] << " ";
		if (m[i] < min)
			min = m[i];
		if (m[i] > max)
			max = m[i];
	}
	std::cout << std::endl;
	std::cout << "Smalles value is " << min << std::endl;
	std::cout << "Biggest value is " << max << std::endl;*/




	//same arrey size and range, finde smallest and biggest values and thered indexies

	srand(time(NULL));
	const int SIZE = 20;
	int m[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		m[i] = rand() % 101;
		std::cout << m[i] << " ";
	}

	int min = 0;
	int max = 0;


	for (int i = 1; i < SIZE; i++)
	{
		if (m[i] < m[min])
			min = i;
		if (m[i] > m[max])
			max = i;
	}
	std::cout << std::endl;
	std::cout << "Smalles value is " << m[min] << " its index is " << min << std::endl;
	std::cout << "Biggest value is " << m[max] << " its index is " << max << std::endl;





}




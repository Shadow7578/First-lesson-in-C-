

#include <iostream>

int main()
{
	
	/*srand(time(NULL));
	const int SIZE = 15;
	int m[SIZE];
	int start_i = 1;
	int end_i = 10;
	int product = 1;

	for (int i = 0; i < SIZE; i++)
	{
		m[i] = rand() % (start_i - (end_i + 1)) + start_i;;
		std::cout << m[i] << " ";
		if (m[i] % 3 == 0)
			product*=m[i];
	}
	std::cout << "Product = " << product;*/




	/*srand(time(NULL));
	const int SIZE = 10;
	
	int m1[SIZE];
	int m2[SIZE];
	int m3[SIZE];

	int start_i = 10;
	int end_i = 30;

	double avrg = 0;
	int max = 0;
	int min = 30;
	for (int i = 0; i < SIZE; i++)
	{
		m1[i] = rand() % (start_i - (end_i + 1)) + start_i;
		m2[i] = rand() % (start_i - (end_i + 1)) + start_i;
		std::cout << m1[i] << "          " << m2[i] << "         ";
		m3[i] = m1[i] + m2[i];
		std::cout << m3[i] << "\n";
		avrg += m3[i];

		if (m3[i] > max)
			max = m3[i];

		if (m3[i] < min)
			min = m3[i];
	}


	std::cout << "Averege = " << (avrg / SIZE) << "\n";
	std::cout << "Maximum = " << max << "\n";
	std::cout << "Minimum = " << min << "\n";*/


	srand(time(NULL));
	const int SIZE = 6;

	int m1[SIZE];
	int m2[SIZE/2];
	int m3[SIZE/2];

	int start_i = 0;
	int end_i = 100;
	
	for (int i = 0; i < SIZE; i++)
	{
		m1[i] = rand() % (start_i - (end_i + 1)) + start_i;
		std::cout << m1[i] << " ";
	}


	for (int i = 0; i < SIZE; i++)
	{
		if (i < SIZE / 2)
			m2[i] = m1[i];
		else
			m3[i - SIZE / 2] = m1[i];
	}
	
	std::cout << "\n\n ";
	
	for (int i = 0; i < SIZE / 2; i++)
	{
		std::cout << m2[i] << " ";
	}
	
	std::cout << "\n\n ";
	
	for (int i = 0; i < SIZE / 2; i++)
	{
		std::cout << m3[i] << " ";
	}
}


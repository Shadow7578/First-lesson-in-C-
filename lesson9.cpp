

#include <iostream>

int main2()
{
	srand(time(NULL));


	// Making a cinema, selling K tickets in a row if possible. 0 = seat is free, 1 = seat is taken. 
	// 

	/*const int ROWS = 10;
	const int SEATS = 20;
	bool arr[ROWS][SEATS]{};
	int k;


	std::cout << "    ";
	for (int i = 0; i < SEATS; ++i)
		std::cout << i + 1 << " ";

	std::cout << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;

	for (int i = 0; i < ROWS; ++i)
	{
		std::cout << i+1 << "  |";

		for (int j = 0; j < SEATS; ++j)
		{
			arr[i][j] = rand() % 2;
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "Please enter amount of tickets to purchase " << std::endl;
	std::cin >> k;
	std::cout << std::endl;

	if (k <= 0 || k > SEATS)
	{
		std::cout << "Error. Invalid input";
		return 0;
	}


	int free_seat = 0;
	bool flag = 0;


	for (int i = 0; i < ROWS; ++i)
	{
		free_seat = 0;
		for (int j = 0; j < SEATS; ++j)
		{
			if (arr[i][j] == 0)
			{
				free_seat++;
				if (free_seat == k)
				{
					std::cout << "There are available seats at row " << i+1 << " from seat number " << (j + 1 - k) << " to seat number " << j + 1
						<< std::endl;
					free_seat =0;
					flag++;
				}
			}
			else
				free_seat = 0;
		}
	}

	std::cout << std::endl;
	if (flag == 0)
		std::cout << "There are no available seats for " << k << " tickets in a row";*/







		//Main diagoal is 0. Diagonals before and after should be graiter by 1.

	/*const int SIZE = 10;
	int arr[SIZE][SIZE];
	int distance = 0;

	for (int i = 0; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			//distance = i - j;
			distance = SIZE - 1 - i - j;
			if (distance < 0)
				distance = -distance;
			arr[i][j] = distance;
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}*/
	return 0;


}



// learning about functions

int get_biggest_of_2(int value1, int value2)
{
	if (value1 > value2)
		return value1;

	return value2;
}

int get_biggest_of_3(int value1, int value2, int value3)
{
	/*if (value1 > value2 && value1 > value3)
		return value1;
	else if (value2 > value1 && value2 > value3)
		return value2;
	return value3;*/

	return get_biggest_of_2(get_biggest_of_2(value1, value2), value3);
}

void draw_line(int amount, char char1)
{
	for (int i = 0; i < amount; ++i)
		std::cout << char1 << " ";
}

int main()
{
	/*int amnt;
	char sym;
	
	std::cout << "Input symbol to draw a line with: \n";
	std::cin >> sym;

	std::cout << "Input amount of sym to draw in a line: \n";
	std::cin >> amnt;

	draw_line(amnt, sym);*/

	std::cout << get_biggest_of_3(5, 6, 7);

}

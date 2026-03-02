

#include <iostream>

struct ABC
{
	int a{};
	int b{};
	char c{};
};

int main(int argc, char* argv[])
{

	if (argc != 4) {
		std::cout << "EROOR, invalid amount of arguments";
		return 0;
	}

	ABC test;
	test.a = atoi(argv[1]);
    test.b = atoi(argv[3]);
    test.c = *(argv[2]);

	switch (test.c)
	{
	case ('+'):
		std::cout << "\na + b = " << test.a + test.b << "\n";
		break;
	case ('-'):
		std::cout << "\na - b = " << test.a - test.b << "\n";
		break;
	case ('*'):
		std::cout << "\na * b = " << test.a * test.b << "\n";
		break;
	case ('/'):
	case ('\\'):
		if (test.c == 0)
		{
			std::cout << "\na / b = ERROR. b = 0, cannot devide by 0.\n";
			break;
		}
		std::cout << "\na / b = " << test.a / (double)test.b << "\n";
		break;
	case ('%'):
		std::cout << "\na % b = " << test.a % test.b << "\n";
		break;
	default:
		std::cout << "invalid input";
		break;
	}
	
}


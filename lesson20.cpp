#include <iostream>

//int** create_arrey(int rows, int cols) {
//	int** arr = new int* [rows];
//	for (int i = 0; i < rows; ++i) {
//		arr[i] = new int[cols] {};
//	}
//	return arr;
//}
//
//void fill_r_array(int** arr, int rows, int cols) {
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			arr[i][j] = rand()%1000;
//		}
//	}
//
//}
//
//void print_array(int** arr, int rows, int cols) {
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			std::cout << arr[i][j] << " ";
//		}
//		std::cout << "\n";
//	}
//}
//
//void delete_array(int** arr, int rows) {
//	for (int i = 0; i < rows; ++i) {
//		delete[] arr[i];
//	}
//	delete[] arr;
//}




//SAME THING, BUT INCLUDE SIMPLE ARREYS



//void print_array(int* arr, int size);
//void fill_r_array(int* arr, int size);
////void delete_array(int* arr);
//int* create_array(int size);
//
//void print_array(int** arr, int rows, int cols);
//void fill_r_array(int** arr, int rows, int cols);
//void delete_array(int** arr, int rows);
//int** create_array(int rows, int cols);
//
//int* create_array(int size) {
//	return new int[size] {};
//}
//
//void print_array(int* arr, int size) {
//	for (int i = 0; i < size; i++) {
//		std::cout << arr[i] << " ";
//	}
//}
//
//int** create_array(int rows, int cols) {
//	int** arr = new int* [rows];
//	for (int i = 0; i < rows; ++i) {
//		arr[i] = new int[cols] {};
//	}
//	return arr;
//}
//
//void delete_array(int** arr, int rows) {
//	for (int i = 0; i < rows; ++i) {
//		delete[] arr[i];
//	}
//	delete[] arr;
//}
//
//void print_array(int** arr, int rows, int cols) {
//	for (int i = 0; i < rows; i++) {
//		print_array(arr[i], cols);
//		std::cout << "\n";
//	}
//}
//
//void fill_r_array(int** arr, int rows, int cols) {
//	for (int i = 0; i < rows; i++) {
//		gen_array(arr[i], cols);
//	}
//}
//
//void gen_array(int* arr, int size) {
//	for (int j = 0; j < size; j++) {
//		arr[j] = rand() % 101;
//	}
//}






//SAME THING BUT USING TAMPLATES



template <typename T>
void print_array(T* arr, int size);
template <typename T>
void fill_r_array(T* arr, int size);
//void delete_array(int* arr);
template <typename T>
T* create_array(int size);
template <typename T>
void create_array(T*& arr, int size);

template <typename T>
void print_array(T** arr, int rows, int cols);
template <typename T>
void fill_r_array(T** arr, int rows, int cols);
template <typename T>
void delete_array(T** arr, int rows);
template <typename T>
T** create_array(int rows, int cols);


template <typename T>
T** add_rows(T** arr, int rows, int cols, int additive);



template <typename T>
T* create_array(int size) {
	return new T[size]{};
}

template <typename T>
void create_array(T*& arr, int size) {
	arr = new T[size]{};
}


template <typename T>
void print_array(T* arr, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
}

template <typename T>
T** create_array(int rows, int cols) {
	T** arr = new T * [rows];
	for (int i = 0; i < rows; ++i) {
		arr[i] = new T[cols]{};
	}
	return arr;
}

template <typename T>
void delete_array(T** arr, int rows) {
	for (int i = 0; i < rows; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
}

template <typename T>
void print_array(T** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		print_array(arr[i], cols);
		std::cout << "\n";
	}
}

template <typename T>
void fill_r_array(T** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		fill_r_array(arr[i], cols);
	}
}

template <typename T>
void fill_r_array(T* arr, int size) {
	for (int j = 0; j < size; j++) {
		arr[j] = rand() % 101;
	}
}

template <typename T>
T** add_rows(T** arr, int rows, int cols, int additive) {
	T** new_arr = new T * *[rows + additive] {};
	int i = 0;
	for (; i < rows;) {
		new_arr[i] = arr[i];
		i++;
	}
	for (; i < (rows + additive); i++)
		new_arr[i] = new T[cols]{};

	delete[] arr;

	return new_arr;
}


template <typename T>
T** resize_rows(T** arr, int rows, int cols, int additive) {
	if (additive == 0)
		return arr;

	T** new_arr = new T *[rows + additive] {};
	if (additive > 0) {
		int i = 0;
		for (; i < rows; i++) {
			new_arr[i] = arr[i];
		}
		for (; i < (rows + additive); i++)
			new_arr[i] = new T[cols]{};
	}
	else {
		int i = 0;
		for (; i < (rows+additive); i++) {
			new_arr[i] = arr[i];
		}
		for (; i < rows; i++) {
			delete[] arr[i];
		}
	}

	delete[] arr;

	return new_arr;
}


int main()
{
	srand(time(NULL));

	int rows = 10;
	int cols = 10;

	/*int** arr = create_array(rows, cols);

	print_array(arr, rows, cols);
	std::cout << "\n";

	fill_r_array(arr, rows, cols);

	print_array(arr, rows, cols);
	std::cout << "\n";

	delete_array(arr, rows);

	std::cout << "\n\n\n";

	int* m = create_array(10);
	fill_r_array(m, 10);
	print_array(m, 10);*/





	//int** mass = create_array<int>(rows, cols);
	//fill_r_array(mass, rows, cols);
	//print_array(mass, rows, cols);
	//delete_array(mass, rows);

	//std::cout << "\n\n\n";

	//int* m = create_array<int>(10);
	//fill_r_array(m, 10);
	//print_array(m, 10);
	//std::cout << "\n\n\n";

	//int* m1;

	//create_array(m1, 10);
	//fill_r_array(m1, 10);
	//print_array(m1, 10);
	//std::cout << "\n\n\n";


	//char** mass1 = create_array<char>(rows, cols);
	//fill_r_array(mass1, rows, cols);
	//print_array(mass1, rows, cols);
	//delete_array(mass1, rows);
	


	



	int** mass = create_array<int>(rows, cols);
	fill_r_array(mass, rows, cols);
	print_array(mass, rows, cols);

	std::cout << "\n\n";

	/*mass = resize_rows(mass, rows, cols, 0);
	rows += 0;
	print_array(mass, rows, cols);*/

	/*mass = resize_rows(mass, rows, cols, 5);
	rows += 5;
	print_array(mass, rows, cols);*/

	mass = resize_rows(mass, rows, cols, (- 5));
	rows -= 5;
	print_array(mass, rows, cols);

}

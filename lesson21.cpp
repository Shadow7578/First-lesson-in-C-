
#include <iostream>
template <typename T>
void print_array(T* arr, int size);

template <typename T>
void gen_array(T* arr, int size);

template <typename T>
T* create_array(int size);

template <typename T>
void create_array(T*& arr, int size);

template <typename T>
void print_array(T** arr, int rows, int cols);

template <typename T>
void gen_array(T** arr, int rows, int cols);

template <typename T>
void delete_array(T** arr, int rows);

template <typename T>
T** create_array(int rows, int cols);

template <typename T>
void create_array(T**& arr, int rows, int cols);

int** add_rows(int** arr, int rows, int cols, int new_rows);

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
void gen_array(T** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		gen_array(arr[i], cols);
	}
}

template <typename T>
void gen_array(T* arr, int size) {
	for (int j = 0; j < size; j++) {
		arr[j] = rand() % 201 - 100;
	}
}

int** add_rows(int** arr, int rows, int cols, int new_rows) {
	int** new_arr = new int* [new_rows];
	int i = 0;

	for (; i < rows; ++i)
		new_arr[i] = arr[i];

	for (; i < new_rows; ++i)
		new_arr[i] = create_array<int>(cols);

	delete[] arr;

	return  new_arr;
}

int** del_rows(int** arr, int rows, int cols, int new_rows) {
	int** new_arr = new int* [new_rows];
	int i = 0;

	for (; i < new_rows; ++i)
		new_arr[i] = arr[i];

	for (; i < rows; ++i)
		delete[] arr[i];

	delete[] arr;

	return  new_arr;
}

int** resize_rows(int** arr, int rows, int cols, int new_rows) {
	if (rows == new_rows)
		return arr;

	int** new_arr = new int* [new_rows];
	int i = 0;

	for (; i < new_rows && i < rows; ++i)
		new_arr[i] = arr[i];

	if (new_rows < rows) {
		for (; i < rows; ++i)
			delete[] arr[i];
	}
	else {
		for (; i < new_rows; ++i)
			new_arr[i] = create_array<int>(cols);
	}

	delete[] arr;

	return  new_arr;
}

template <typename T>
T* resize_col(T* m, int s, int n_s) {

	T* nm = new T[n_s]{};

	for (int i = 0; i < n_s && i < s; i++)
		nm[i] = m[i];

	delete[]m;
	return nm;
}

template <typename T>
void resize_col(T** m, int s, int col, int new_col) {

	for (int i = 0; i < s; i++)
		m[i] = resize_col(m[i], col, new_col);
}


const char* month_name2(int k) {
	static const char* name[] = {
	"none","January",
	"February","March","April",
	"May","June","July","August",
	"September","October","November",
	"December"
	};
	return (k < 1 || k > 12) ? name[0] : name[k];
}




void add_positive_cols(int** arr, int rows, int cols, int* summ_arr) {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++) {
			if (arr[i][j] > 0)
				summ_arr[j] += arr[i][j];
		}

}


bool count_A_to_Z(char a) {
	return (a >= 'A' && a <= 'Z');
}

bool count_a_to_z(char a) {
	return (a >= 'a' && a <= 'z');
}

bool count_0_to_9(char a) {
	return (a >= '0' && a <= '9');
}


int coutn_symbls_in_string(char* str, bool (*ptr) (char)) {
	int result{};
	
	while (*str != '\0') {
		/*if (ptr(*str))
			result++;*/
		
		result += ptr(*str);
		str++;
	}

	return result;
}

int main()
{
	//int rows;
	//int cols;
	//
    //std::cout << "Input number for rows of the matrix: \n";
	//std::cin >> rows;
	//std::cout << "Input number for colloms of the matrix: \n";
	//std::cin >> cols;
	//std::cout << "\n\n";

	//int** arr = create_array<int>(rows, cols);
	//gen_array(arr, rows, cols);
	//print_array(arr, rows, cols);
	//std::cout << "\n\n";

	////create arrey and add every positive value in each collomns

	//int* summ_arr = create_array<int>(cols);
	//add_positive_cols(arr, rows, cols, summ_arr);
	//print_array(summ_arr, cols);



	char string [] {"aaa AAA 999 000 zzz ZZZ"};

	std::cout << coutn_symbls_in_string(string, count_0_to_9) << std::endl;
	std::cout << coutn_symbls_in_string(string, count_a_to_z) << std::endl;
	std::cout << coutn_symbls_in_string(string, count_A_to_Z) << std::endl;


}


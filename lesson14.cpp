
#include <iostream>

void reverse(int value)
{
    
    if (value == 0)
        return;

    
    std::cout << value % 10 << "\n";
    reverse (value/10);
}

void straight_reverse(int value)
{

    if (value == 0)
        return;

        straight_reverse(value/10);
    std::cout << value % 10 << "\n";
}


bool pow_of_2(int value)
{
    if (value == 1)
        return true;
    if(value %2 == 0)
        return pow_of_2(value / 2);
   
    return false;

}

void print_rev_arrey(int arr[], int ind)
{
    if (ind < 0)
        return;

    std::cout << arr[ind] << "\n";
    print_rev_arrey(arr, ind -1);
}


void print_arrey(int arr[], int ind)
{
    if (ind < 0)
        return;

    
    print_arrey(arr, ind - 1);
    std::cout << arr[ind] << "\n";
}


int main()
{
   //reverse(4571);
   //straight_reverse(4571);

    //std::cout << std::boolalpha << pow_of_2(256);

    int arr[10]{ 1,2,3,4,5,6,7,8,9,10 };
    print_rev_arrey(arr, 9);


    print_arrey(arr, 9);
}



#include <iostream>

int main()
{
    srand(time(NULL));
   /* const int ROWS = 10;
    const int COLS = 10;
    int arr[ROWS][COLS];
    int arr_R_max[ROWS];
    int max = 0;
    

    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            arr[i][j] = rand() % 51;
            std::cout << arr[i][j] << " ";
            if (max < arr[i][j])
                max = arr[i][j];
        }
        std::cout << std::endl;
        arr_R_max[i] = max;
        max = 0;
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout <<"MAX for each row is:" << std::endl;

    for (int i = 0; i < ROWS; ++i)
        std::cout << arr_R_max[i] << " ";
   
    
    std::cout << std::endl;
    std::cout << std::endl;



    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
            std::cout << arr[i][j] << " ";
        
        std::cout << "        max:  " << arr_R_max[i]<< std::endl;
    }*/





    //const int ROWS = 10;
    //const int COLS = 10;
    //int arr[ROWS][COLS];
    //int arr_R_max[ROWS];
    //int arr_C_max[COLS];
    //int max = 0;
    //

    //for (int i = 0; i < ROWS; ++i)
    //{
    //    for (int j = 0; j < COLS; ++j)
    //    {
    //        arr[i][j] = rand() % 51;
    //        std::cout << arr[i][j] << " ";
    //        if (max < arr[i][j])
    //            max = arr[i][j];
    //    }
    //    std::cout << std::endl;
    //    arr_R_max[i] = max;
    //    max = 0;
    //}

    //std::cout << std::endl;
    //std::cout << std::endl;
    //
    //for (int i = 0; i < COLS; ++i)
    //{
    //    for (int j = 0; j < ROWS; ++j)
    //    {
    //        if (max < arr[j][i])
    //            max = arr[j][i];
    //    }
    //    arr_C_max[i] = max;
    //    max = 0;
    //}
    // 
    //
    //std::cout << std::endl;
    //std::cout << std::endl;



    //for (int i = 0; i < ROWS; ++i)
    //{
    //    for (int j = 0; j < COLS; ++j)
    //        std::cout << arr[i][j] << " ";
    //    
    //    std::cout << "        max:  " << arr_R_max[i]<< std::endl;
    //    
    //}
    //std::cout <<"max" << std::endl;
    //for (int i = 0; i < COLS; ++i)
    //    std::cout << arr_C_max[i] << " ";

    //std::cout << std::endl;
    //std::cout << std::endl;





//const int ROWS = 10;
//const int COLS = 10;
//char arr[ROWS][COLS];
//char vowels[]{ 65, 69, 73, 79, 85, 89 };
//int start_i = 65;
//int end_i = 90;
//
//for (int i = 0; i < ROWS; ++i)
//{
//    for (int j = 0; j < COLS; ++j)
//    {
//        arr[i][j] = rand() % (start_i - (end_i + 1)) + start_i;
//        std::cout << arr[i][j] << " ";
//    }
//    std::cout << std::endl;
//}
//
//std::cout << std::endl;
//std::cout << std::endl;
//std::cout << std::endl;
//
//
//for (int i = 0; i < ROWS; ++i)
//{
//    for (int j = 0; j < COLS; ++j)
//    {
//        for (int k = 0; k < sizeof(vowels)/sizeof(vowels[0]); ++k)
//        if (arr[i][j] == vowels[k])
//            arr[i][j] = 46;
//        
//        std::cout << arr[i][j] << " ";
//    }
//    std::cout << std::endl;
//}





const int ROWS = 10;
const int COLS = 10;
int arr[ROWS][COLS];


for (int i = 0; i < ROWS; ++i)
{
    for (int j = 0; j < COLS; ++j)
    {
        //if (i == j || j == (COLS - 1) - i)
            arr[i][j] = (i == j || j == (COLS - 1) - i);
        std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
}

}


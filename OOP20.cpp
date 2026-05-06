#include <iostream>
#include <vector>
#include <functional>
#include <set>

/*
Задача
std::function как фильтр

Напишите функцию std::vector<int> filter(const std::vector<int>& data, std::function<bool(int)> predicate),
которая возвращает новый вектор, содержащий только элементы, удовлетворяющие предикату.
Проверьте с лямбдой, отбирающей чётные числа.

*/


std::vector<int> filter(const std::vector<int>& data, std::function<bool(int)> predicate) {
    std::vector<int> vec;

    for (auto& i : data) {
        if (predicate(i)) {
            vec.push_back(i);
        }
    }
    return vec;
}







int main()
{
   std::vector<int> vec{1,2,3,4,5,6,7,8,9,0,10,11,12,13,14,15,16,17,18,19,20};

    /*int val;
    std::cout << "input val:";
    std::cin >> val;
    std::vector<int> vec2 = filter(vec, [val](int a) {
        return (a % val) == 0;
        });

    for (auto& c : vec2) {
        std::cout << c << " ";
    }

    */

   std::set <int, [](int a, int b) {return a < b; } > s{ vec.begin(), vec.end() };

   std::set<int>s2;

}

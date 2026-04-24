#include <iostream>
#include <list>

void print(std::list<int>& l) {
    for (int& i : l)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main1()
{
    std::list<int> list = { 9, 2, 4, 8, 5, 13, 6, 1, 0, 3, 10, 7, 11, 12 };
    std::list<int> even{};
    std::list<int> odd{};
    std::list<int> list2{};

    print(list);

    for (int& i : list) {
        if (i % 2 == 0) {
            even.push_back(i);
        }
        else {
            odd.push_back(i);
        }
    }

    list2.splice(list2.begin(), even);
    list2.splice(list2.end(), odd);
    std::cout << "===============================\n";
    print(list2);

    return 0;
}


int main()
{
    std::list<int> list = { 9, 2, 4, 8, 5, 13, 6, 1, 0, 3, 10, 7, 11, 12 };
    std::list<int> odd{};
    

    print(list);

    for (int i=0; i < list.size(); i++) {
        std::list<int>::iterator it = list.begin();
        std::advance(it, i);
        if (*it % 2 != 0) {
            odd.push_back(*it);
            list.erase(it);
            i--;
        }
        
    }

    list.splice(list.end(), odd);
    
    std::cout << "===============================\n";
    print(list);


}
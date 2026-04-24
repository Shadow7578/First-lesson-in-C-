#include <iostream>
#include<vector>

class Train {
    int number{};
    std::string dep_time{};
    std::string destination{};
public:

    int get_n() { return number; }
    std::string get_dp() {return dep_time;}
    std::string get_dest() { return destination; }

    Train() {};
    Train(int n, std::string dt, std::string dest) : number{ n }, dep_time{ dt }, destination{ dest } {
        std::cout << n << "Train created\n";
    }
    ~Train() {
        std::cout << number << "Destroying train\n";
    }
};

void add_train(std::vector<Train>& l) {
    //l.resize(l.size() + 1);
    //std::vector<Train>::iterator it = --(l.end());
    
    int n{};
    std::string dt{};
    std::string dest{};

    std::cout << "Input number of new train: ";
    std::cin >> n;

    std::cout << "Input time of departure of new train: ";
    std::cin >> dt;

    std::cout << "Input destination of new train: ";
    std::cin >> dest;

    
    //*it = Train(n, dt, dest);
    l.push_back(Train(n, dt, dest));
}

void print_all(std::vector<Train>& l) {
    for (Train& t : l) {
        std::cout << "Train number: " << t.get_n() << " depart at: " << t.get_dp() << " to: " << t.get_dest() << std::endl;
    }
}



void print_by_key(std::vector<Train>& l, int key){

    auto compare = [key](Train& t) -> bool {
        if (t.get_n() == key)
            return true;
        return false;
        };

    std::vector<Train>::iterator it = std::find_if(l.begin(), l.end(), compare);
    if (it == l.end())
        throw "Train not found\n";

        std::cout << "Train number: " << it->get_n() << " depart at: " << it->get_dp() << " to: " << it->get_dest() << std::endl;
}

int main()
{
    Train t1(1, "12:50", "OP");
    Train t2(2, "13:40", "DZ");
    Train t3(3, "22:22", "EK");

    std::vector<Train> list{ t1,t2,t3 };

    try {
        print_by_key(list, 2);
    }
    catch (...) { std::cout << "!!!!Train not found!!!!!\n"; }

    std::cout << "=======================\n";

    print_all(list);
    std::cout << "=======================\n";

    add_train(list);
    std::cout << "=======================\n";

    print_all(list);
    std::cout << "=======================\n";

}


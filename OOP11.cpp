#include <iostream>
#include <string>


class Employee {
protected:   
    std::string name;
    int experience;

public:
    Employee(std::string s, int exp) : name{ s }, experience{ exp } {
        printf("Epmloyee %s, %d years of experience\n", name.c_str(), experience);
    }
    
    std::string getName() {
        return name;
    }

    virtual std::string getRole() {
        return "Employee";
    }

    virtual double calculateSalary() const {
        return 30000 + (1000 * experience);
    }

    virtual ~Employee() {
        std::cout << name << " has been layed off\n";
    }
};



class Manager : public Employee {
    int teamSize{};
public:
    Manager(std::string s, int exp, int size) : Employee(s, exp), teamSize{ size } {
        printf("Manager %s, %d years of experience, %d man team\n", s.c_str(), exp, size );
    }

    std::string getRole() override {
        return "Manager";
    }

    virtual double calculateSalary() const override {
        return Employee::calculateSalary() + (5000 * teamSize);
    }

    ~Manager() {
        std::cout << "Manager " << name << " has been layed off\n";
    }
};



class Developer : public Employee {
    int extraHours{};

public:
    Developer (std::string s, int exp, int hours) : Employee(s, exp), extraHours{ hours } {
        printf("Developer %s, %d years of experience, %d hrs overtime\n", s.c_str(), exp, hours);
    }

    std::string getRole() override {
        return "Developer";
    }

    virtual double calculateSalary() const override {
        return Employee::calculateSalary() + (1000 * extraHours);
    }
    ~Developer() {
        std::cout << "Developer " << name << " has been layed off\n";
    }
};


class Intern : public Employee {
public:
    explicit Intern(std::string s) : Employee(s, 0) {
        printf("Intern %s\n", s.c_str());
    }

    std::string getRole() override {
        return "Intern";
    }

    virtual double calculateSalary() const override {
        return 15000;
    }
    ~Intern() {
        std::cout << "Intern " << name << " has been layed off\n";
    }


};

class Company {
    
    Employee* employee[8];
public:
    void hire(Employee* emp) {
        static int c = 0;
        employee[c] = emp;
        c++;
    }

    double calculateTotalSalary() const {
        double total = 0;
        for (int i = 0; i < 8; i++)
            total+=employee[i]->calculateSalary();
        return total;
    }

    void printPayroll() {
        printf("== Peyroll for Company == \n");
        for (int i = 0; i < 8; i++)
            printf("%s,  %s       : %f rub\n", employee[i]->getName().c_str(), employee[i]->getRole().c_str(), employee[i]->calculateSalary());

    }

    ~Company() {
        for (int i = 0; i < 8; i++)
            delete employee[i];
    }
};

int main()
{

    Company c;
    c.hire(new Employee ("Emp1", 2));
    c.hire(new Employee("Emp2", 1));
    c.hire(new Developer("Dev1", 4, 10));
    c.hire(new Developer("Dev2", 3, 30));
    c.hire(new Manager("Man1", 6, 8));
    c.hire(new Manager("Man2", 9, 15));
    c.hire(new Intern("Int1"));
    c.hire(new Intern("Int2"));

    c.printPayroll();
}


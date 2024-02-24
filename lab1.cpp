#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    string phone;

public:
    int employeeID;
    string name;
    string address;

    Employee() { // default constructor
        cout << "Default Constructor is called" << endl;
    }

    ~Employee() { // destructor
        cout << "Destructor is called" << endl;
    }
};

int main() {
    Employee emp;
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string phone;
public:
    int id;
    string name;
    string address;

    // Parameterized Constructor
    Person(int i, string n, string p, string a) : id(i), name(n), phone(p), address(a) {}

    // Destructor
    ~Person() {
        cout << "Destructor is called" << endl;
    }

    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Phone: " << phone << endl;
        cout << "Address: " << address << endl;
        cout << "\n";
    }
};

int main() {
    Person P1(101, "John", "0123456789", "New York");
    P1.display();

    return 0;
}

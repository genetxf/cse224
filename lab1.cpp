#include <iostream>

class MyClass {
public:
    // Default constructor
    MyClass() {
        std::cout << "Default constructor called" << std::endl;
    }

};

int main() {
    // Creating an object of MyClass using the default constructor
    MyClass obj;

    return 0;
}

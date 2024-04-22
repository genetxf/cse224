#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }

    virtual void name() {
        cout << "Base Animal class" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Animal Sound: Barks" << endl;
    }
    void name() override {
        cout << "Animal Class Name: Dog" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Animal Sound: Meows" << endl;
    }
    void name() override {
        cout << "Animal Class Name: Cat" << endl;
    }
};

int main() {
    Dog dog;
    Cat cat;

    Animal* animal = &dog;
    animal->name();
    animal->sound();

    cout << "\n";

    animal = &cat;
    animal->name();
    animal->sound();


    return 0;
}

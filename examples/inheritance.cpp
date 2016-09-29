#include <iostream>

using namespace std;

class Base
{
public:
    Base () {cout << "Creating base" << endl;}

};

class Derived : public Base
{
public:
Derived() {cout << "Creating derived" << endl;}
};


int main()
{
    Base b;
    Derived d;
}

#include <iostream>

using namespace std;

class Polygon
{
public:
    string name;
    double surface;
    Polygon(double x)
    {
        surface = x;
        name = "polygon";
    }
};



class Rectangle : public Polygon
{
public:
    Rectangle(double x) : Polygon(x)
    {
        //surface = x;
        name = "rectangle";
    }
};



class Circle
{
public:
    string name;
    double surface;
    Circle(double x)
    {
        surface = x;
        name = "circle";
    }
};



template<class T> void f(T p)
{
    cout << "i am a " << p.name << " with surface " << p.surface << endl;
}



int main()
{
    Polygon p(4);
    f<Polygon>(p);

    Rectangle r(5);
    f<Polygon>(r);

    Circle c(6);
    f<Circle>(c);



}

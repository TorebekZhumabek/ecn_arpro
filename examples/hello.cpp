#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <math.h>

class Mother
{
public:
    virtual int Func() = 0;// {return 1;}
};

class Daughter : public Mother
{public:
    int Func() {return 2;}
};

class OtherDaughter : public Mother
{
public:
    int Func() {return 3;}
};

void print(Mother &m)
{
    std::cout << m.Func() << std::endl;
}

int main()
{
  //  Mother m;
    Daughter d;
 //  print(m);
   print(d);

   OtherDaughter d2;
//  print(m);
  print(d2);



    std::cout << "Hello world!" << std::endl;
    int x = 1, y = 2;
    std::string a="abc", b = "def";

    std::cout << x+y << std::endl;
    std::cout << a+b << std::endl;

    srand(time(NULL));
    std::cout << std::rand() << std::endl;
}

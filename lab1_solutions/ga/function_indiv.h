#include <algorithm>
#include <iostream>
#include <string>
#include <math.h>
#include <ok_galg/indiv.h>

using namespace std;
using namespace ok_galg;

class FunctionIndiv : public ok_galg::Indiv // gives cost and comparison operator
{
public:
    // default constructor
    FunctionIndiv() {}

    // randomize: a individual is (x,y) in [-5,5]
    void Randomize()
    {
        x = -5 + (10.*rand())/RAND_MAX;
        y = -5 + (10.*rand())/RAND_MAX;
        ComputeCost();
    }

    // copy
    void Copy(const FunctionIndiv &_other) {x=_other.x;y=_other.y;cost=_other.cost;}

    void ComputeCost()
    {
        cost = 20 + x*x + y*y - 10*(cos(2*M_PI*x) + cos(2*M_PI*y));
    }

    void CrossAndMutate(FunctionIndiv &_father, FunctionIndiv &_mother)
    {
        // crossing: random mean between father and mother
        double alpha = (1.*rand())/RAND_MAX;

        x = alpha*_father.x + (1-alpha)*_mother.x;
        y = alpha*_father.y + (1-alpha)*_mother.y;

        // mutation: random variation around current point
        x += -0.5 + (1.*rand())/RAND_MAX;
        y += -0.5 + (1.*rand())/RAND_MAX;
        if(fabs(x) > 5)
            x = 5*x/fabs(x);
        if(fabs(y) > 5)
            y = 5*y/fabs(y);

        ComputeCost();
    }

    void Print()
    {
        cout << "f(" << x << ", "<< y << ") = "<< cost << endl;
    }

protected:
    double x, y;
};



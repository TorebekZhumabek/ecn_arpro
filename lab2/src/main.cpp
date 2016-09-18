#include <iostream>
#include <math.h>
#include <cmath>

#include <robot.h>
#include <envir.h>

using namespace std;
using namespace arpro;


int main()
{
    // init environment
    Environment envir;

    // init robot at (0,0,0)
    Robot robot("R2D2", 0,0,0);

    // add this robot to the environment (for plotting)
    envir.addRobot(robot);

    for(unsigned int i=0;i<10000;++i)
    {
        // update target position
        envir.updateTarget();

        // try to follow target
        robot.goTo(envir.target);
    }

    // plot trajectory
    envir.plot();
    
}

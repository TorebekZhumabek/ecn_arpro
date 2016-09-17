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
    Robot robot(0,0,0);
    // set sampling time
    robot.setSamplingTime(.01);

    Robot robot2(0,-1,0);
    // set sampling time
    robot.setSamplingTime(.01);

    // add this robot to the environment (for plotting)
    envir.addRobot(robot);
    envir.addRobot(robot2);




    for(unsigned int i=0;i<10000;++i)
    {
        // update target position
        envir.updateTarget();

        // try to follow target
        robot.goTo(envir.target);
        robot2.goTo(robot.getPosition());
    }

    // plot trajectory
    envir.plot();
    
}

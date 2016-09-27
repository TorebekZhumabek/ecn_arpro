#include <iostream>
#include <math.h>
#include <cmath>

#include <robot.h>
#include <envir.h>
#include <sensor_range.h>
#include <sensor_bearing.h>

using namespace std;
using namespace arpro;



int main()
{
    // default environment with moving target
    Environment envir;
    // sensors gets measurements from this environment
    Sensor::setEnvironment(envir);

    // init robot at (0,0,0)
    Robot robot("R2D2", 0,0,0);    
    envir.addRobot(robot);

    // add range sensors
    RangeSensor sensor1(robot, .1,0,0),
                sensor2(robot, 0,0,-M_PI/2);


    Robot robot2("C3PO", 2,3,-M_PI);
    robot2.initWheels(0.3, 0.05, 10);
    BearingSensor bear(robot2, .1,0,0);
    envir.addRobot(robot2);






    for(unsigned int i=0;i<10000;++i)
    {
        cout << "---------------------" << endl;

        // update target position
        envir.updateTarget();        

        // try to follow target
        robot.goTo(envir.target);

        //robot2.goTo(robot.pose());
        robot2.moveWithSensor(Twist(1,0,0));
    }

    // plot trajectory
    envir.plot();
    
}

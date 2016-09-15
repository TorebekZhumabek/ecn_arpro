#include <iostream>
#include <math.h>
#include <cmath>

#include <robot.h>

using namespace std;
using namespace arpro;


int main()
{
    // init robot at (0,0,0)
    Robot robot(0,0,0);
    // set sampling time
    robot.SetSamplingTime(.01);

    // init environment
    Environment envir = DefaultEnvironment();

    /* move robot with:
    - (vx, vy, omega) (Cartesian)
    - or (v, omega) (local frame)
    - or (omega_left, omega_right) (wheel velocities)
    */
    double vx, vy, v, omega_left, omega_right, omega;
    for(unsigned int i=0;i<10000;++i)
    {
        // update target position
        envir.UpdateTarget();

        // use cartesian setpoint
        robot.GoTo(envir.target.x, envir.target.y);
        //robot.MoveXYT(vx, vy, omega);

        // use robot frame velocity
        //robot.MoveVW(v, omega);

        // use wheels        
        //robot.RotateWheels(omega_left, omega_right);


    }

    // plot trajectory
    robot.PlotTraj(envir);
    
}

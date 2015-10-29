#include <iostream>
#include <math.h>
#include <cmath>

#include <robot.h>

// default environment and motions
#include <defaults.h>

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
        // use cartesian setpoint
        DefaultCartesianSetpoint(i, vx, vy, omega);
        robot.MoveXYT(vx, vy, omega);

        // use robot frame velocity
        DefaultVelocitySetpoint(i, v, omega);
        //robot.MoveVW(v, omega);

        // use wheels
        DefaultWheelSetpoint(i, omega_left, omega_right);
        //robot.RotateWheels(omega_left, omega_right);


    }

    // plot trajectory
    robot.PlotTraj(envir);
    
}

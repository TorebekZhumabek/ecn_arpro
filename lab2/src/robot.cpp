

#include <iostream>
#include <math.h>
#include <robot.h>
#include <sensor.h>

using namespace arpro;
using namespace std;

Environment* Sensor::envir_ = NULL;


Robot::Robot(string _name, double _x, double _y, double _theta)
{    
    pose_.x = _x;
    pose_.y = _y;
    pose_.theta = _theta;

    name_ = _name;

    // init position history
    x_history_.push_back(_x);
    y_history_.push_back(_y);

    // default sampling time: 1/100 s
    dt_ = .01;
}


void Robot::moveXYT(double _vx, double _vy, double _omega)
{
    // update position
    pose_.x += _vx*dt_;
    pose_.y += _vy*dt_;
    pose_.theta += _omega*dt_;

    // store position history
    x_history_.push_back(pose_.x);
    y_history_.push_back(pose_.y);
}



void Robot::rotateWheels(double _left, double _right)
{
    // to fill up after defining an initWheel method
}


// move robot with linear and angular velocities
void Robot::moveVW(double _v, double _omega)
{
    // to fill up

}




// try to go to a given x-y position
void Robot::goTo(const Pose &_p)
{
    // error in robot frame
    Pose error = _p.transformInverse(pose_);

    // try to do a straight line with sensor constraints
    moveWithSensor(Twist(error.x, error.y, 0));
}


void Robot::moveWithSensor(Twist _twist)
{
    // go through all sensors to see if the robot twist is fine with them
    for(auto & sensor: sensors_)
    {
        sensor.sensor->update(sensor.pose.transformDirect(pose_));
        sensor.sensor->checkRobotTwist(_twist, sensor.pose);
    }

    // uses X-Y motion (perfect but impossible in practice)
    moveXYT(_twist.vx, _twist.vy,_twist.w);

    // uses v-omega motion with wheel limits
    //moveVW(_twist.vx,20*_twist.vy + _twist.w);
}


void Robot::printPosition()
{
    cout << "Current position: " << pose_.x << ", " << pose_.y << endl;
}


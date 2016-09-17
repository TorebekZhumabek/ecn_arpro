#include <iostream>
#include <math.h>

#include <robot.h>

using namespace arpro;
using namespace std;

Robot::Robot(const double &_x, const double &_y, const double &_theta)
{
    x_ = _x;
    y_ = _y;
    theta_ = _theta;

    // init position history
    x_history_.push_back(_x);
    y_history_.push_back(_y);

    // default sampling time: 1/100 s
    dt_ = .01;

    // nothing has been initialized
    wheels_init_ = false;
}


void Robot::getPosition(double &_x, double &_y, double &_theta) const
{
    // to fill up

    
}


void Robot::moveXYT(const double &_vx, const double &_vy, const double &_omega)
{
    // update position
    x_ += _vx*dt_;
    y_ += _vy*dt_;
    theta_ += _omega*dt_;

    // store position history
    x_history_.push_back(x_);
    y_history_.push_back(y_);
}


void Robot::initWheel(const double &_radius, const double &_base)
{
    // to fill up
    
    
    wheels_init_ = true;
}


void Robot::rotateWheels(double &_left, double &_right)
{
    // to fill up
}


// move robot with linear and angular velocities
void Robot::moveVW(const double &_v, const double &_omega)
{
    // to fill up
    
    
}


// try to go to a given position
void Robot::goTo(const Point &_p)
{
    // uses X-Y-theta motion (impossible in practice)
    moveXYT(-0.5*(x_-_p.x), -0.5*(y_-_p.y),0);


}


void Robot::printPosition()
{
    cout << "Current position: " << x_<< ", " << y_ << endl;
}


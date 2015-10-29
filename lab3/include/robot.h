#ifndef ROBOT_H
#define ROBOT_H

#include <vector>
#include <matplotlibcpp.h>
#include <envir.h>
#include <envir.h>

namespace arpro
{

class Robot
{
public:
    // initialize robot at (x,y,theta)
    Robot(const double &_x, const double &_y, const double &_theta);

    // change sampling time
    inline void SetSamplingTime(const double &_dt) {dt_ = _dt;}
    
    // get the current position
    void GetPosition(double &_x, double &_y, double &_theta) const;
    
    // move robot with a given (x,y,theta) velocity
    void MoveXYT(const double &_vx, const double &_vy, const double &_omega);

    // move robot with linear and angular velocities
    void MoveVW(const double &_v, const double &_omega);
    
    // initialize the wheel model
    void InitWheel(const double &_radius, const double &_base);
    
    // move robot with given wheel velocity
    void RotateWheels(double &_left, double &_right);
    
    // prints the current position
    void PrintPosition();
    
    // plots the trajectory in the given environment
    void PlotTraj(const Environment &_envir);


protected:
    // position
    double x_, y_, theta_;
    std::vector<double> x_history_, y_history_;

    // sampling time
    double dt_;

    // wheel model
    bool wheels_init_;
};

}

#endif

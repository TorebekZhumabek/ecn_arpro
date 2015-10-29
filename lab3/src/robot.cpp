#include <iostream>
#include <algorithm>
#include <math.h>

#include <robot.h>

using namespace arpro;
using namespace std;

Robot::Robot(const double &_x, const double &_y, const double &_theta)
{
    
    // init position history
    x_history_.push_back(_x);
    y_history_.push_back(_y);

    // default sampling time: 1/100 s
    dt_ = .01;

    // nothing has been initialized
    wheels_init_ = false;
}


void Robot::GetPosition(double &_x, double &_y, double &_theta) const
{
    // to fill up

    
}


void Robot::MoveXYT(const double &_vx, const double &_vy, const double &_omega)
{
    // update position
    x_ += _vx*dt_;
    y_ += _vy*dt_;
    theta_ += _omega*dt_;

    // store position history
    x_history_.push_back(x_);
    y_history_.push_back(y_);
}


void Robot::InitWheel(const double &_radius, const double &_base)
{
    // to fill up
    
    
    wheels_init_ = true;
}


void Robot::RotateWheels(double &_left, double &_right)
{
    // to fill up
}


// move robot with linear and angular velocities
void Robot::MoveVW(const double &_v, const double &_omega)
{
    // to fill up
    
    
}


void Robot::PrintPosition()
{
    cout << "Current position: " << x_<< ", " << y_ << endl;
}

void Robot::PlotTraj(const Environment &_envir)
{
    // plot position history
    matplotlibcpp::plot(x_history_, y_history_, "b");

    // plot start and end position
    vector<double> x(1), y(1);
    x[0] = x_history_[0];
    y[0] = y_history_[0];
    matplotlibcpp::named_plot("Start", x, y, "gD");
    x[0] = *(x_history_.end()-1);
    y[0] = *(y_history_.end()-1);
    matplotlibcpp::named_plot("End", x,y,"rD");
    matplotlibcpp::legend();

    // plot environment
    // walls
    if(_envir.walls.size() > 0)
    {
        x.resize(_envir.walls.size());
        y.resize(_envir.walls.size());
        for(unsigned int i=0;i<_envir.walls.size();++i)
        {
            x[i] = _envir.walls[i].x;
            y[i] = _envir.walls[i].y;
        }

        double  x_min = *(std::min_element(x.begin(), x.end())),
                x_max = *(std::max_element(x.begin(), x.end())),
                y_min = *(std::min_element(y.begin(), y.end())),
                y_max = *(std::max_element(y.begin(), y.end()));

        // invisible plot just for size
        vector<double> x_minmax(2), y_minmax(2);
        x_minmax[0] = x_min - .05*(x_max - x_min);
        x_minmax[1] = x_max + .05*(x_max - x_min);
        y_minmax[0] = y_min - .05*(y_max - y_min);
        y_minmax[1] = y_max + .05*(y_max - y_min);
        matplotlibcpp::plot(x_minmax, y_minmax, "w.");

        x.push_back(x[0]);
        y.push_back(y[0]);
        matplotlibcpp::plot(x, y, "k");
    }

    matplotlibcpp::show();
}

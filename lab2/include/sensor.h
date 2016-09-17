#ifndef SENSOR_H
#define SENSOR_H

#include <envir.h>
#include <string>
#include <matplotlibcpp.h>

namespace arpro
{

class Sensor
{
public:
    // no constructor

    // init attributes
    void init(const double &_x, const double &_y, const double &_theta, const std::string &_name)
    {
        x_ = _x;
        y_ = _y;
        theta_ = _theta;
        name_ = _name;
        s_history_.clear();
    }

    // update from robot and environment
    virtual void update(const Robot &_robot, const Environment &_envir) = 0;

    // print current measurement
    inline void print() {std::cout << name_ << ": " << s_ << std::endl;}

    // plot history
    inline void plot()
    {
        std::vector<double> x(s_history_.size());
        for(unsigned int i=0;i<s_history_.size();++i)
            x[i] = i;
        matplotlibcpp::named_plot(name_, x, s_history_, "b");
        matplotlibcpp::show();
    }

    // read current measurement
    double read() {return s_;}

protected:
    // sensor position in robot frame
    double x_, y_, theta_;
    // sensor name
    std::string name_;
    // current measurement
    double s_;
    // measurement history
    std::vector<double> s_history_;
};

}



#endif // SENSOR_H

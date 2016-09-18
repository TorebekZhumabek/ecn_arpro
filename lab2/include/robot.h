#ifndef ROBOT_H
#define ROBOT_H

#include <vector>

namespace arpro
{

struct Point
{
    double x;
    double y;
    Point(double _x=0, double _y=0) {x = _x;y = _y;}
};

class Robot
{
public:
    // initialize robot at (x,y,theta)
    Robot(const std::string &_name, const double &_x, const double &_y, const double &_theta);

    // change sampling time
    inline void setSamplingTime(const double &_dt) {dt_ = _dt;}
    
    // get the current position in (x,y,theta)
    void getPosition(double &_x, double &_y, double &_theta) const;
    
    // move robot with a given (x,y,theta) velocity
    void moveXYT(const double &_vx, const double &_vy, const double &_omega);

    // move robot with linear and angular velocities
    void moveVW(double _v, double _omega);
        
    // move robot with given wheel velocity
    void rotateWheels(double _left, double _right);

    // try to go to a given (x,y) position
    void goTo(const Point &_p);
    
    // prints the current position
    void printPosition();

    inline void getHistory(std::vector<double> &_x, std::vector<double> &_y)
    {
        _x = x_history_;
        _y = y_history_;
    }

    inline std::string name() {return name_;}

protected:
    // position
    double x_, y_, theta_;
    std::vector<double> x_history_, y_history_;
    std::string name_;

    // sampling time
    double dt_;
};

}

#endif

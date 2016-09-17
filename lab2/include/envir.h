#ifndef ENVIR_H
#define ENVIR_H

#include <vector>
#include <math.h>
#include <robot.h>
#include <matplotlibcpp.h>
#include <sstream>
#include <algorithm>

namespace arpro
{

struct Environment
{
    std::vector<Point> walls;
    Point target;
    std::vector<double> x_hist, y_hist;
    std::vector<Robot*> robots_;

    unsigned int iter;
    Environment()
    {
        iter=0;
        x_hist.clear();
        y_hist.clear();

        walls.resize(4);
        walls[0].x = walls[1].x = walls[1].y = walls[2].y = -10;
        walls[2].x = walls[3].x = walls[0].y = walls[3].y = 10;

        robots_.clear();
    }

    void updateTarget()
    {
        target.x = 1+0.001*iter*cos(0.002*iter);
        target.y = 0.001*iter*sin(0.002*iter);
        x_hist.push_back(target.x);
        y_hist.push_back(target.y);
        iter++;
    }

    void addRobot(Robot &_robot)
    {
        robots_.push_back(&_robot);
    }


    // plots the trajectory in the given environment
    void plot()
    {
        unsigned int i=0;
        std::vector<double> x,y, x_start, y_start, x_end, y_end;
        std::vector<std::string> colors = {"b","g","r","c"};

        for(auto &robot: robots_)
        {
            robot->getHistory(x,y);
            std::stringstream ss;
            ss << "Robot " << ++i;
            matplotlibcpp::named_plot(ss.str(), x, y);

            // start and end positions
            x_start.push_back(x[0]);
            x_end.push_back(x[x.size()-1]);
            y_start.push_back(y[0]);
            y_end.push_back(y[y.size()-1]);
        }

        // plot target motion
        matplotlibcpp::named_plot("Target", x_hist, y_hist, "m");

        matplotlibcpp::named_plot("Start", x_start, y_start, "gD");
        matplotlibcpp::named_plot("End", x_end,y_end,"rD");

        matplotlibcpp::legend();

        // plot environment
        // walls
        if(walls.size() > 0)
        {
            x.resize(walls.size());
            y.resize(walls.size());
            for(unsigned int i=0;i<walls.size();++i)
            {
                x[i] = walls[i].x;
                y[i] = walls[i].y;
            }

            double  x_min = *(std::min_element(x.begin(), x.end())),
                    x_max = *(std::max_element(x.begin(), x.end())),
                    y_min = *(std::min_element(y.begin(), y.end())),
                    y_max = *(std::max_element(y.begin(), y.end()));

            // invisible plot just for size
            std::vector<double> x_minmax(2), y_minmax(2);
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





};

}

#endif // ENVIR_H

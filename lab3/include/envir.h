#ifndef ENVIR_H
#define ENVIR_H

#include <vector>
#include <math.h>

namespace arpro
{

struct Point
{
    double x;
    double y;
};

struct Environment
{
    std::vector<Point> walls;
    Point target;
    std::vector<double> x_hist, y_hist;

    unsigned int iter;
    Environment() {iter=0;x_hist.clear();y_hist.clear();}

    void UpdateTarget()
    {
        target.x = 1+0.001*iter*cos(0.002*iter);
        target.y = 0.001*iter*sin(0.002*iter);
        x_hist.push_back(target.x);
        y_hist.push_back(target.y);
        iter++;
    }
};


// defines the default environment
Environment DefaultEnvironment()
{
    arpro::Environment envir;
    // 4 walls at +- 10 m
    envir.walls.resize(4);
    envir.walls[0].x = envir.walls[1].x = envir.walls[1].y = envir.walls[2].y = -10;
    envir.walls[2].x = envir.walls[3].x = envir.walls[0].y = envir.walls[3].y = 10;

    return envir;
}




}

#endif // ENVIR_H

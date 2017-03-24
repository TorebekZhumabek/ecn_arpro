#include "a_star.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

// what is this position
class Position
{
public:
    // default constructor
    Position(int _x, int _y) : travel(0), parent(0),x(_x), y(_y) {}

    // builds initial grid based on desired start and goal positions
    static void BuildGrid(Position &start, Position &goal, int nb)
    {
        srand(clock());
        grid.resize(n*n, 0);
        std::vector<int> x_occ = {start.x, goal.x};
        std::vector<int> y_occ = {start.y, goal.y};
        for(int i=0;i<nb;++i)
        {
            bool occupied = true;
            int xo, yo;
            while(occupied)
            {
                xo = rand() % n;
                yo = rand() % n;

                occupied = false;
                for(int j=0;j<x_occ.size();++j)
                {
                    if(xo == x_occ[j] && yo == y_occ[j])
                        occupied = true;
                }
            }
            grid[n*xo + yo] = 1;
        }
    }

    Position(Position *_parent, int _x, int _y) : x(_x), y(_y)
    {
        SetParent(_parent);
    }

    void SetParent(Position *_parent)
    {
        parent = _parent;
        travel = parent->travel+1;
    }

    Position* GetParent() {return parent;}


    void Print()
    {
        unsigned int i;
        for(i=0;i<2*n+3;++i)
            std::cout << "-";
        std::cout << std::endl;

        std::vector<int> x_hist;
        std::vector<int> y_hist;
        Position* current = this;
        while(current)
        {
            x_hist.push_back(current->x);
            y_hist.push_back(current->y);
            current = current->parent;
        }

        for(i=0;i<n;++i)
        {
            std::cout << "| ";
            for(unsigned int j=0;j<n;++j)
            {
                bool path = false;
                for(int k=0;k<x_hist.size();++k)
                {
                    if(i == x_hist[k] && j == y_hist[k])
                        path = true;
                }

                if(path)
                    std::cout << "o ";
                else if(grid[n*i+j] == 1)
                    std::cout << ". ";
                else
                    std::cout << "  ";
            }
            std::cout << "|" << std::endl;
        }

        for(i=0;i<2*n+3;++i)
            std::cout << "-";
        std::cout << std::endl;
    }

    bool is(Position * goal_ptr)
    {
        return x == goal_ptr->x && y == goal_ptr->y;
    }

    void Children(vector<Position* > &children)
    {
        children.clear();

        std::vector<int> moves;
        for(int i: {-1,0,1})
        {
            for(int j: {-1,0,1})
            {
                if(i != 0 || j != 0)
                {
                    if(x+i >= 0 && x+i < n && y+j>=0 && y+j < n && !grid[n*(x+i)+y+j])
                    {
                        children.push_back(new Position(this, x+i, y+j));
                    }
                }
            }
        }
    }

    void Compute_h(const Position &goal)
    {
        h = abs(x-goal.x) + abs(y-goal.y);
    }

    double f()
    {
        return travel+h;
    }
    double& g() {return travel;}



protected:
    int x, y;
    Position* parent;
    double h, travel;

    static unsigned int n;
    static std::vector<unsigned int> grid;
};

unsigned int Position::n = 20;
// the grid will be initialized with random objects at the first call
std::vector<unsigned int> Position::grid = std::vector<unsigned int>();

int main()
{
    // initial and goal positions
    Position start(0,0), goal(&start, 19,19);

    // puts some obstacles in the grid
    Position::BuildGrid(start, goal, 200);

    goal.Print();

    Astar(start, goal);


}

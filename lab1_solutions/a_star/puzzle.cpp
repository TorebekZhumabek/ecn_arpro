#include "a_star.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <memory>

using namespace std;

// what is this puzzle
class Puzzle
{
public:
    // default constructor randomizes the puzzle
    Puzzle()
    {
        grid.resize(n*n,0);
        // build the desired configuration
        for(unsigned int i=0;i<n*n-1;++i)
            grid[i] = i+1;

        // where the 0 is
        c0 = n*n-1;

        travel = 0;
    }

    void Randomize()
    {
        // randomize
        srand(clock());
        vector<unsigned int> moves;

        for(int i=0;i<30;++i)
        {
            moves = Moves();
            int idx = rand() % moves.size();
            iter_swap(grid.begin()+c0, grid.begin()+moves[idx]);
            c0 = moves[idx];
        }
    }

    Puzzle(Puzzle *_parent, unsigned int _c0)
    {
        SetParent(_parent);
        grid = parent->grid;
        c0 = _c0;
        iter_swap(grid.begin()+c0, grid.begin()+parent->c0);
    }

    void SetParent(Puzzle *_parent)
    {
        parent.reset(_parent);
        travel = parent->travel+1;
    }

    void Print()
    {
        for(unsigned int i=0;i<n;++i)
        {
            for(unsigned int j=0;j<n;++j)
                cout << grid[n*i+j] << " ";
            cout << endl;
        }
    }

    bool is(std::shared_ptr<Puzzle> goal_ptr)
    {
        for(int i=0;i<n*n-2;++i)
        {
            if(grid[i] != goal_ptr->grid[i])
                return false;
        }
        return true;
    }

    vector<unsigned int> Moves()
    {
        vector<unsigned int> moves;
        if(c0 > n)                  // up-move with c0 - n
            moves.push_back(c0-n);

        if(c0 < n*n-n)              // down move with c0 + n
            moves.push_back(c0+n);

        if(c0 % n != 0)             // left move with c0 -1
            moves.push_back(c0-1);

        if(c0 % n != n-1)           // right move with c0+1
            moves.push_back(c0+1);
        return moves;
    }

    void Children(vector<shared_ptr<Puzzle> > &children)
    {
        children.clear();

        for(auto c: Moves())
            children.push_back(shared_ptr<Puzzle>(new Puzzle(this, c)));
    }

    void Compute_h(const Puzzle &goal)
    {
        // distance to final puzzle
        h = 0;
        int idx, idx_goal, r, c;
        for(unsigned int i=1;i<n*n-1;++i)
        {
            // where this number is in the grid
            idx = std::distance(grid.begin(), std::find(grid.begin(), grid.end(), i));
            // where it is in the goal
            idx_goal = std::distance(goal.grid.begin(), std::find(goal.grid.begin(), goal.grid.end(), i));

            // in terms of row x cols and difference with where it should be
            r = idx / n - idx_goal/n;
            c = idx % n - idx_goal%n;

            h += abs(r) + abs(c);
        }
    }

    double f()
    {
        return travel+h;
    }
    double& g() {return travel;}

    friend bool operator <(Puzzle &o1,Puzzle &o2)
    {
        return o1.f() < o2.f();
    }



protected:
    std::vector<unsigned int> grid;
    shared_ptr<Puzzle> parent;
    static unsigned int n;
    unsigned int c0;
    double h, travel;
};

unsigned int Puzzle::n = 3;


int main()
{
    Puzzle puzzle, goal;
    puzzle.Randomize();

    Astar(puzzle, goal);


}

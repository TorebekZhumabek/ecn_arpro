#include "player.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

// static variables
// 0 = nothing
// 1 = missed
// 2 = minesweeper (length 2)
// 3 = submarine (length 3)
// 4 = destroyer (length 3)
// 5 = cruiser (length 4)
// 6 = aircraft carrier (length 5)
// negative = boat hit
std::vector<std::string> Player::legend = {".", "x", "M", "S", "D", "C", "A"};
std::vector<unsigned int> Player::length = {2,3,3,4,5};

Player::Player(bool _human)
{
    // store if human
    human = _human;

    // we play on a 10x10 grid
    grid.resize(100,0);
    // initialize grid
    srand (time(NULL));
    alive = 0;
    unsigned int dir, r, c;
    for(unsigned int i=0;i<length.size();++i)
    {
        bool occupied = true;
        // try to find a place for this boat
        while(occupied)
        {
            dir = rand() % 2;   // 0 = horizontal, 1 = vertical
            r = rand() % (10*(1-dir) + (10-length[i])*dir);  // starting row
            c = rand() % (10*(dir) + (10-length[i])*(1-dir));  // starting column

            // test if this slot is ok
            occupied = false;
            for(unsigned int j=0;j<length[i];++j)
            {
                if(cell(r + j*dir, c + j*(1-dir)))
                    occupied = true;
            }
        }

        // actually write the boat
        for(unsigned int j=0;j<length[i];++j)
            cell(r + j*dir, c + j*(1-dir)) = i+2;   // boats start at 2
    }

}

// get a given line of the whole grid
std::stringstream Player::PrintLine(unsigned int r)
{
std::stringstream ss;
ss << r;
return ss;



}



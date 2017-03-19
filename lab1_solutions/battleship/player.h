#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <iostream>
#include <string>
#include <sstream>

// a Player class that may be humaon or not

class Player
{
public:
    Player(bool _human = true);

    // the value at a given grid position
    inline int& cell(unsigned int r, unsigned int c)
    {
        if( r > 9 || c > 9)
        {
            std::cout << "Wrong row/column given: "<< r << ", "<< c << std::endl;
            return grid[0];
        }
        return grid[10*r + c];
    }

    // get a given line of the whole grid
    std::stringstream PrintLine(unsigned int r);








protected:
    bool human;
    std::vector<int> grid;
    unsigned int alive;


    // static for legends, lengths, etc.
    static std::vector<std::string> legend;
    static std::vector<unsigned int> length;





};




#endif // PLAYER_H

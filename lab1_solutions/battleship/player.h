#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <iostream>
#include <string>
#include <sstream>

// a Player class that may be human or not

class Player
{
public:
    Player(std::string _name, bool _human = true);

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

    // print this grid and the one of the other player
    void Print(Player &other);

    // shoot at the other
    bool Shoot(Player &other);

    void wins() {std::cout << name << " wins!"<< std::endl;}


protected:
    bool human;
    std::string name;
    std::vector<int> grid;
    unsigned int alive;
    std::vector<unsigned int> alive_b;

    // for computer: history of passed shots
    std::vector<unsigned int> hist;


    // static for legends, lengths, etc.
    static std::vector<std::string> legend;
    static std::vector<unsigned int> length;

    // print a grid line
    std::string PrintLine(unsigned int r);





};




#endif // PLAYER_H

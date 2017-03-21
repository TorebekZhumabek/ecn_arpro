#include <algorithm>
#include <vector>

// This class defines what is a configuration for the Tic Tac Toe game

class TicTacToe
{
public:
    TicTacToe()
    {
        xs.clear();
        os.clear();
        turn = turn_count = 0;
    }








protected:
    std::vector<unsigned int> xs, os;
    unsigned int turn, turn_count;


};

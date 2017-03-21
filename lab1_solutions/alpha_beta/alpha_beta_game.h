#include <algorithm>
#include <vector>
#include "alpha_beta.h"

// This function is a generic alpha-beta game using a given game configuration
// p1 starts.
template <class T> void AlphaBetaGame(bool p1_human = true, bool p2_human = false)
{
    T config;
    std::vector<bool> is_human = {p1_human, p2_human};
    int a, b;
    config.GetAlphaBeta(a,b);

    int player = 1;
    while(!config.Winner() && !config.Over())
    {
        if(is_human[player-1])
        {
            config.Print();
            config.HumanInput(player,true);
        }
        else if (config.MustThink())
            alpha_beta(config, player, player, a, b, true);
        player = 3-player;
    }
    config.Print();

    int win = config.Winner();
    if(win)
        std::cout << "Player " << win << " wins" << std::endl;
    else
        std::cout << "Draw" << std::endl;


}

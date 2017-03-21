#include <algorithm>
#include <vector>


/* This function uses alpha-beta algorithm for a given game configuration
 */

template<class T>
int alpha_beta(T config, unsigned int player, unsigned int computer, int alpha, int beta, bool first_call = false)
{
    if(first_call)
    {
        //std::vector<move type> choices;
        auto choices = config.AvailableMoves();
        choices.clear();
        int val;
        for(auto move: config.AvailableMoves())
        {
            config.MakeMove(move);
            val = alpha_beta(config, 3-player, computer, alpha, beta);
            config.CancelMove(move);
            if(val > alpha)
            {
                alpha = val;
                choices = {move};
            }
            else if(val == alpha)
                choices.push_back(move);
        }
        unsigned int idx = rand() % choices.size();
        config.MakeMove(choices[idx]);
    }
    else
    {
        // check for end of game
        int win = config.Winner();
        if(win == computer)
            return 1;
        else if(win)
            return -1;
        else if(config.Over())
            return 0;

        // build new moves
        int val;
        for(auto move: config.AvailableMoves())
        {
            config.MakeMove(move);
            val = alpha_beta(config, 3-player, computer, alpha, beta);
            config.CancelMove(move);






        }





    }



    return 0;
}

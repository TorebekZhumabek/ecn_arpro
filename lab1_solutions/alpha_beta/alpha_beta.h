#include <algorithm>
#include <vector>


/* This function uses alpha-beta algorithm for a given game configuration
 */

template<class T>
int alpha_beta(T& config, int player, int computer, int alpha, int beta, unsigned int recur, unsigned int max_recur)
{
    if(recur == 0)
    {

        auto choices = config.AvailableMoves();
        choices.clear();
        int val;
        for(auto move: config.AvailableMoves())
        {
            config.MakeMove(move);
            val = -alpha_beta(config, player, computer, alpha, beta, 1, max_recur);
            std::cout << "Move " << move << " -> score = " << val << std::endl;
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
        std::cout << "Making move " << choices[idx] << std::endl;
        config.MakeMove(choices[idx]);
    }
    else
    {
        // check for end of game
        int win = config.Winner();
        if(win)
            return -100+recur;

        // what to return
        if(config.Over() || recur == max_recur)
            return (player == computer)?-recur:recur;

        // build new moves
        int val, best = -5000;

        for(auto move: config.AvailableMoves())
        {
            config.MakeMove(move);
            val = -alpha_beta(config, 3-player, computer, -beta, -alpha, recur+1, max_recur);
            config.CancelMove(move);
            if(val > best)
            {
                best = val;
                if(best > alpha)
                {
                    alpha = best;
                    if(alpha > beta)
                        return best;
                }
            }
        }
        return best;
    }
}

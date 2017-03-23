#include <algorithm>
#include <vector>
#include "four_in_a_row_config.h"
#include "alpha_beta_game.h"

int main()
{
    AlphaBetaGame<FourInARow>(false, false, 3);
}

#include <iostream>
#include <ok_galg/galg.h>
#include <map>
#include <chrono>
#include "function_indiv.h"

using namespace std;
using namespace ok_galg;

int main(int argc, char ** argv)
{
    std::srand(std::time(0));

    FunctionIndiv f;

    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    // single-run solver
    ok_galg::SolveSingleRun(f, YAML::Node(), 1, 1);

    // multi-run in threads
    //ok_galg::SolveMultiThread(f, config, 200, 4, false);

    end = std::chrono::system_clock::now();

    cout << "Final: ";
    f.Print();

    f.Randomize();
    cout << "Random: ";
    f.Print();


    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";



}

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <math.h>

using std::cout;
using std::endl;


int main(int argc, char ** argv)
{
    std::cout << "Hello world!" << std::endl;

    std::cout << "You have " << argc << " arguments:" << endl;
    for(unsigned int i=0;i<argc;++i)
        std::cout << "  - " << argv[i] << endl;

}

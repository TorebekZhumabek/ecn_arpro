#include <iostream>
#include <vector>

using std::vector;

void init(vector<int> &_v)
{
    for(unsigned int i=0;i<_v.size();++i)
        _v[i] = std::rand()%256;

}

void loop_index(vector<int> &_v)
{
    for(unsigned i=0; i < _v.size(); i++)
        _v[i]++;
}

void loop_auto(vector<int> &_v)
{
    for(int x : _v)
        x++;
}

void loop_autoref(vector<int> &_v)
{
    for(int &x : _v)
        x++;
}

void loop_constautoref(vector<int> &_v)
{
    for(const int &x : _v)
        x+1;
}



int main(int argc, char ** argv)
{
    vector<int> v(1000000);
    init(v);

    loop_index(v);
    loop_auto(v);
    loop_autoref(v);
    loop_constautoref(v);

}

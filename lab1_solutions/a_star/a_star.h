#ifndef A_STAR_H
#define A_STAR_H
#include <vector>
#include <algorithm>

// templated version of A* algorithm

template<class T>
void Astar(T start, T goal)
{
    std::vector<T> closedSet, openSet = {start};
    start.Compute_h(goal);
    unsigned int idx;
    while(openSet.size())
    {
        // find best in openSet
        idx = 0;
        for(int i = 1;i<openSet.size();++i)
        {
            if(openSet[i] < openSet[idx])
                idx = i;
        }
        // candidate = openSet[idx]
        if(openSet[idx].is(goal))
            break;

        closedSet.push_back(openSet[idx]);
        openSet.erase(openSet.begin()+idx);

        T* union_elem;
        for(auto neighboor: closedSet.back().Children())
        {
            int union_idx;
            for(union_idx=0;union_idx<openSet.size()+closedSet.size();++union_idx)
            {
                // get element from union
                if(union_idx < openSet.size())
                    union_elem = *(openSet[union_idx]);
                else
                    union_elem = *(closedSet[union_idx-openSet.size()]);
                if(union_elem->is(neighboor))
                {

                }
            }
        }

    }








}


#endif // A_STAR_H

#ifndef A_STAR_H
#define A_STAR_H
#include <vector>
#include <algorithm>
#include <memory>
#include <functional>

// templated version of A* algorithm

template<class T>
void Astar(T start, T goal)
{
    // a shortcut
    typedef std::shared_ptr<T> Tptr;
    Tptr goal_ptr(&goal);

    // the sets we need
    std::vector<Tptr > closedSet, openSet = {Tptr(&start)}, children, unionSet;

    start.Compute_h(goal);
    unsigned int idx;
    while(openSet.size())
    {
        // find best in openSet
        idx = 0;
        for(int i = 1;i<openSet.size();++i)
        {
            if(openSet[i]->f() < openSet[idx]->f())
                idx = i;
        }
        // candidate = openSet[idx]
        if(openSet[idx]->is(goal_ptr))
            break;

        closedSet.push_back(openSet[idx]);
        openSet.erase(openSet.begin()+idx);

        closedSet.back()->Children(children);

        for(auto child: children)
        {
            // build union set
            unionSet.clear();
            for(auto &elem : openSet)
                unionSet.push_back(elem);
            for(auto &elem : closedSet)
                unionSet.push_back(elem);

            // look for children in union set
            auto twin = std::find_if(unionSet.begin(), unionSet.end(),
                                        [child](Tptr elem){return elem->is(child);} );





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

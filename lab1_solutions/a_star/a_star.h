#ifndef A_STAR_H
#define A_STAR_H
#include <vector>
#include <algorithm>
#include <iostream>

// templated version of A* algorithm

template<class T>
void Astar(T start, T goal)
{
    // a shortcut
    T* goal_ptr(&goal);

    // the sets we need
    std::vector<T*> closedSet, openSet = {&start}, children, unionSet;

    int evaluated = 0, created = 0, shortcut = 0;

    start.Compute_h(goal);
    evaluated++;
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
        if(openSet[idx]->is(goal_ptr))
            break;

        closedSet.push_back(openSet[idx]);
        openSet.erase(openSet.begin()+idx);

        // candidate = closedSet.back()
        closedSet.back()->Children(children);
        created += children.size();

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
                                        [child](T* elem){return elem->is(child);} );

            if(twin != unionSet.end())
            {   // child is is union
                if((*twin)->g() > child->g())
                {   // we found a better way to come to this element -> update parent
                    shortcut++;
                    openSet.push_back(*twin);
                    openSet.back()->SetParent(closedSet.back());
                }
            }
            else
            {   // child not in union, add it
                child->Compute_h(goal);
                evaluated++;
                openSet.push_back(child);
            }
        }

    }

    // we may exit the loop because openSet is empty (no solution) or not (solution = openSet[idx])
    if(openSet.size())
    {
        T* current = openSet[idx];
        std::vector<T*> summary = {current};
        // build list from end to start
        while(current->GetParent())
        {
            current = current->GetParent();
            summary.push_back(current);
        }
        // print list form start to end
        std::reverse(summary.begin(),summary.end());
        for(auto &elem: summary)
        {
            elem->Print();
            std::cout << std::endl;
        }
        std::cout << "solved in " << summary.size()-1 << " steps" << std::endl;
    }
    else
    {
        std::cout << "No solutions " << std::endl;
    }
    std::cout << created << " nodes created, " << evaluated << " evaluated, " << shortcut << " shortcuts found" << std::endl;
}


#endif // A_STAR_H

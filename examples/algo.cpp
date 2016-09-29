#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


class MyObj
{
public:
    MyObj() {value_ = rand()%100;}
    int value() {return value_;}

protected:
    int value_;

};




int main()
{






    // random vector of int's
    vector<int> whatever(10);

    for(auto &i: whatever)
        i = rand() % 100;

  //  for_each(whatever.begin(),whatever.end(),[](int &i){i = rand()%100;});

    for(auto &i: whatever)
        cout << i << " ";
    cout << endl;

    // sort with classical < comparison
    sort(whatever.begin(),whatever.end());

    for(auto &i: whatever)
        cout << i << " ";
    cout << endl;

/*
    // random vector of MyObj
    vector<MyObj> v_obj(10);
    for(auto &o: v_obj)
        cout << o.value() << " ";
    cout << endl;

    // sort with external function
    sort(v_obj.begin(),v_obj.end(),[](MyObj &_o1, MyObj &_o2){return _o1.value() < _o2.value();});

    // sort with operator<
    sort(v_obj.begin(),v_obj.end(),[](MyObj &_o1, MyObj &_o2){return _o1.value() < _o2.value();});

    // sort with lambda function
    sort(v_obj.begin(),v_obj.end(),[](MyObj &_o1, MyObj &_o2){return _o1.value() < _o2.value();});

    for(auto &o: v_obj)
        cout << o.value() << " ";
    cout << endl;

*/






}

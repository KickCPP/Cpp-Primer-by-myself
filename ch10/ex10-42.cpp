#include <list>
#include <iostream>

using std::list;
using std::cout; using std::endl;

void elimDups(list<int> &lst)
{
    lst.sort();
    lst.unique();
}

int main()
{
    list<int> lst{1,2,3,3,4,4,5,1,5,6,7,1,7};
    elimDups(lst);
    for (auto i: lst)
        cout << i << " ";
    cout << endl;
    return 0;
}

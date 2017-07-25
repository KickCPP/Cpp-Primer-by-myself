#include <list>
#include <vector>
#include <algorithm>
#include <iostream>

using std::list; using std::vector;
using std::cout; using std::endl;

int main()
{
    vector<int> v{1,2,3,4,5,6,7,8,9,10};
    list<int> lst;
    std::copy(v.cbegin()+3, v.cbegin()+8, std::front_inserter(lst));
    for (auto i: lst)
        cout << i << " ";
    cout << endl;
    return 0;
}

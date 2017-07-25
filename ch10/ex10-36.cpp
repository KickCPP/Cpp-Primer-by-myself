#include <list>
#include <algorithm>
#include <iostream>

using std::list;
using std::cout;

int main()
{
    list<int> lst{1,0,0,1,1,1,0,1};
    auto ri = std::find(lst.crbegin(), lst.crend(), 0);
    cout << "Find last 0 at position: " << std::distance(ri, lst.crend())<< std::endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using std::vector; using std::list;

int main()
{
    vector<int> v{
        1,1,2,2,3,4,4,5,6,7,7
    };
    list<int> lst;
    std::unique_copy(v.begin(), v.end(), inserter(lst, lst.begin()));
    for (auto i: lst)
        std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}

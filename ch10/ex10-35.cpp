#include <vector>
#include <iostream>

using std::vector;
using std::cout;

int main()
{
    vector<int> v{1,2,3,4,5,6};
    for (auto ri = v.cend() - 1; ri != v.cbegin()-1; ri--)
        cout << *ri << " ";
    cout << std::endl;
    return 0;
}


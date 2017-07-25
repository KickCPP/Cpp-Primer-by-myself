#include <vector>
#include <iostream>

using std::vector;
using std::cout;

int main()
{
    vector<int> v{1,2,3,4,5,6};
    for (auto ri = v.crbegin(); ri != v.crend(); ri++)
        cout << *ri << " ";
    cout << std::endl;
    return 0;
}

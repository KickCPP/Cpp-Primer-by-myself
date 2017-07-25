#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std::placeholders;
using std::vector; using std::string;

bool check_size(int n, string::size_type sz)
{
    return n > sz;
}

int main()
{
    string s = "test";
    vector<int> v{1,2,3,3,5,4,2};
    auto it = find_if(v.begin(), v.end(), bind(check_size, _1, s.size()));
    if (it != v.end())
        std::cout << *it << std::endl;
    else
        std::cout << "Not found" << std::endl;
    return 0;
}

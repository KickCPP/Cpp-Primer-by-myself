#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::vector;

void print(vector<int> &v)
{
    for (auto i: v)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main()
{
    vector<int> v{
        1,2,3,4,5,6,7
    };
    vector<int> iv, biv, fiv;
    //std::copy(v.begin(), v.end(), front_inserter(fiv)); // fail to compile, because vector doesn't have push_front
    std::copy(v.begin(), v.end(), inserter(iv, iv.begin())); // the order same as v
    std::copy(v.begin(), v.end(), back_inserter(biv)); // the order same as v
    //print(fiv);
    print(iv);
    print(biv);
    return 0;
}

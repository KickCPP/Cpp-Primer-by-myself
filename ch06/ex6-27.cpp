#include <iostream>
#include <initializer_list>

using std::initializer_list;
using std::cout; using std::endl;

int sum(initializer_list<int> ls)
{
    int sum = 0;
    for(const auto &i: ls)
        sum += i;
    return sum;
}

int main()
{
    auto l = {1,2,3,4,5,6,7,8,9};
    cout << sum(l) << endl;
    return 0;
}

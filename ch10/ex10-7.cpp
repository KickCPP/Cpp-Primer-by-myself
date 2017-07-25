#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
#include <iterator>
#include <list>

using namespace std;

int main()
{
    vector<int> vec;
    list<int> lst;
    int i;
    while (cin >> i)
        lst.push_back(i);
    copy(lst.cbegin(), lst.cend(),back_inserter(vec));
    for (auto i: vec)
        cout << i << " ";
    cout << endl;

    vector<int> v;
    v.reserve(10);
    fill_n(back_inserter(v), 10, 0);
    for (auto i: v)
        cout << i << " ";
    cout << endl;
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec{1,2,2,4,4,3,3,3,5,6,7};
    sort(ivec.begin(), ivec.end());
    auto end_unique = unique(ivec.begin(), ivec.end());
    ivec.erase(end_unique, ivec.end());
    for (auto i: ivec)
        cout << i << " ";
    cout << endl;
    return 0;
}

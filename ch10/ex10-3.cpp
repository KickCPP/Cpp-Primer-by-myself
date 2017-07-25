#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    vector<int> v{1,2,3,4,5,6,7,8,9};
    int sum = accumulate(v.cbegin(), v.cend(), 0);
    cout << sum << endl;
    return 0;
}

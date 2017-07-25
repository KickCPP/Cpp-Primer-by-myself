#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> v{1,1,8,8,7,1,1,1,3};
    cout << "1 appears: " << count(v.begin(), v.end(), 1) << " times" << endl;
    return 0;
}

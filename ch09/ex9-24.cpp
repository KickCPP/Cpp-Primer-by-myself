#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> v;
    cout << v[0] << endl;
    cout << v.at(0) << endl;
    cout << v.front() << endl;
    cout << v.back() << endl;
    return 0;
}

#include <vector>
#include <iostream>

using namespace std;

bool compareVector(vector<int> &v1, vector<int> &v2)
{
    if (v1 == v2) {
        cout << "They are equal\n";
        return true;
    }
    else {
        cout << "They are not equal\n";
        return false;
    }
}

int main()
{
    vector<int> v1 = {1,2,3};
    vector<int> v2(v1);
    vector<int> v3(v1.begin(), v1.begin()+1);
    compareVector(v1,v2);
    compareVector(v1,v3);
    return 0;
}

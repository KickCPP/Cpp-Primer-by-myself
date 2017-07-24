#include <list>
#include <iostream>

using namespace std;

bool compareList(list<int> &v1, list<int> &v2)
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
    list<int> l1 = {1,2,3};
    list<int> l2(l1);
    list<int> l3 = {1};
    compareList(l1,l2);
    compareList(l1,l3);
    return 0;
}

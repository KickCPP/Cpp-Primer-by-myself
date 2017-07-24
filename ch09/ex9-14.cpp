#include <vector>
#include <list>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    list<const char *> l = {"hello", "world", "www", "com"};
    vector<string> v;
    v.assign(l.begin(), l.end());
    cout << *v.begin() << endl;
    return 0;
}

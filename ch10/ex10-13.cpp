#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

inline bool
len(string &s)
{
    if (s.size() >= 5)
        return true;
    return false;
}

int main()
{
    vector<string> svec{
        "a", "as", "aasss", "aaaaassaa", "aaaaaabba", "aaa"
    };
    auto pivot = partition(svec.begin(), svec.end(), len);
    svec.erase(pivot, svec.end());
    for (auto s: svec)
        cout << s << " ";
    cout << endl;
    return 0;
}

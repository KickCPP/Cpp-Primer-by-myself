#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void elimDups(vector<string>& svec)
{
    sort(svec.begin(), svec.end());
    auto end_unique = unique(svec.begin(), svec.end());
    svec.erase(end_unique, svec.end());
}

inline bool
is_shorter(string s1, string s2)
{
    if (s1.size() < s2.size())
        return true;
    return false;
}

int main()
{
    vector<string> svec{
        "1234", "1234", "1234", "Hi", "alan", "wang"
    };
    elimDups(svec);
    stable_sort(svec.begin(), svec.end(), is_shorter);
    for (auto s: svec)
        cout << s << " ";
    cout << endl;
    return 0;
}

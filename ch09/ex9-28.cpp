#include <iostream>
#include <forward_list>
#include <string>

using namespace std;

void findAndInsert(forward_list<string>&flst, string s1, string s2)
{
    auto it = flst.begin();
    for (; it != flst.end(); it++)
        if (*it == s1)
            break;
    flst.insert_after(it, s2);
}

int main()
{
     forward_list<string> flst = {"a","b","c","d"};
     findAndInsert(flst, "b", "test");
     for (auto it: flst)
        cout << it << " ";
     cout << endl;
     return 0;
}

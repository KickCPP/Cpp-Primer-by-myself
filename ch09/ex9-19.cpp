#include <list>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word;
    list<string> l;
    while (cin >> word)
        l.push_back(word);
    auto it = l.begin();
    while (it != l.end()) {
        cout << *it << "\n";
        it++;
    }
    return 0;
}

#include <iostream>
#include <deque>

using namespace std;

int main()
{
    string word;
    deque<string> dq;
    while (cin >> word)
        dq.push_back(word);
    auto it = dq.begin();
    while (it != dq.end()) {
        cout << *it << "\n";
        it++;
    }
    return 0;
}

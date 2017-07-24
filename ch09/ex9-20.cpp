#include <iostream>
#include <deque>
#include <list>

using namespace std;

int main()
{
    list<int> l = {1,2,3,4};
    deque<int> oddDq;
    deque<int> evenDq;
    auto it = l.begin();
    while (it != l.end()) {
        if (*it % 2)
            oddDq.push_back(*it++);
        else
            evenDq.push_back(*it++);
    }
    for (auto it=oddDq.begin(); it != oddDq.end(); it++)
        cout << *it << " ";
    cout << endl;
    for (auto it=evenDq.begin(); it != evenDq.end(); it++)
        cout << *it << " ";
    return 0;
}

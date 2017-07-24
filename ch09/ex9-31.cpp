#include <iostream>
#include <forward_list>
#include <list>

using namespace std;

void delete_even_copy_odd(list<int> &lst)
{
    auto it = lst.begin();
    while (it != lst.end()) {
        if (*it % 2) {
            it = lst.insert(it, *it);
            ++it;
            ++it;
        }
        else
            it = lst.erase(it);
    }
}

void delete_even_copy_odd(forward_list<int> &flst)
{
    auto prev = flst.before_begin();
    auto cur = flst.begin();
    while (cur != flst.end()) {
        if (*cur % 2) {
            cur = flst.insert_after(cur, *cur);
            prev = cur;
            ++cur;
        }
        else {
            cur = flst.erase_after(prev);
        }
    }
}

int main()
{
    list<int> lst{0,1,2,3,4,5,6,7,8,9};
    forward_list<int> flst(lst.begin(), lst.end());

    delete_even_copy_odd(lst);
    delete_even_copy_odd(flst);
    for (auto it: lst)
        cout << it << " ";
    cout << endl;
    for (auto it: flst)
        cout << it << " ";
    cout << endl;
    return 0;
}

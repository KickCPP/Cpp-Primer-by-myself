#include <vector>
#include <list>
#include <iostream>

using namespace std;

int main()
{
    int ia[] = {0,1,2,3,5,8,13,21,55,89};
    vector<int> v(ia,end(ia));
    list<int> l(v.begin(),v.end());
    auto vit = v.begin();
    auto lit = l.begin();
    while(vit != v.end()) {
        if ((*vit % 2) == 0)
            vit = v.erase(vit);
        else
            vit++;
    }
    while (lit != l.end()) {
        if (*lit % 2)
            lit = l.erase(lit);
        else
            lit++;
    }
    for (vit = v.begin(); vit != v.end(); vit++)
        cout << *vit << " ";
    cout << endl;
    for (lit = l.begin(); lit != l.end(); lit++)
        cout << *lit << " ";
    return 0;
}

#include <memory>
#include <iostream>

using namespace std;



int main()
{
    auto p = make_shared<int>(1);
    auto q = p;
    auto f = make_shared<int>(10);
    q = f;
    cout << "f shared pointer with " << f.use_count() << " pointers, point to " << *f <<endl;
    cout << "p shared pointer with " << p.use_count() << " pointers, point to " << *p <<endl;
    cout << "q shared pointer with " << q.use_count() << " pointers, point to " << *q <<endl;
    return 0;
}

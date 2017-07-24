#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    cout << "size: " << v.size() << " " << "capacity: " << v.capacity() << endl;
    for (int i=0; i<5; i++) {
        v.push_back(i);
        cout << "size: " << v.size() << " " << "capacity: " << v.capacity() << endl;
    }
    v.resize(20);
    cout << "size: " << v.size() << " " << "capacity: " << v.capacity() << endl;
    v.reserve(50);
    cout << "size: " << v.size() << " " << "capacity: " << v.capacity() << endl;
    v.shrink_to_fit();
    cout << "size: " << v.size() << " " << "capacity: " << v.capacity() << endl;
    return 0;
}

#include <iostream>

using namespace std;

istream& rw(istream& is)
{
    char c;
    while(is >> c)
        cout << c;
    is.clear();
    return is;
}

int main()
{
    rw(cin);
    return 0;
}

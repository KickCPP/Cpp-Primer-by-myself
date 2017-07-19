#include "ex7-49.h"
#include <iostream>

using namespace std;

int main()
{
    Sales_data i("test",10,10);
    string s = "test";
    print(cout, i.combine(s)) << endl;
    return 0;
}

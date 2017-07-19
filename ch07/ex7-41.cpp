#include "ex7-41.h"
#include <iostream>

using namespace std;

int main()
{
    Sales_data s1;
    cout << "******s1*********\n";
    Sales_data s2("hello");
    cout << "******s2*********\n";
    Sales_data s3(cin);
    cout << "******s3*********\n";
    Sales_data s4("hello",1,1);
    cout << "******s4*********\n";
    return 0;
}

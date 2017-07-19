#include "ex7-11.h"
#include <iostream>

using namespace std;

int main(){
    Sales_data s1;
    Sales_data s2(cin);
    Sales_data s3("We", 10, 5.5);
    Sales_data s4("Zero");

    print(cout, s1);
    cout << endl;
    print(cout, s2);
    cout << endl;
    print(cout, s3);
    cout << endl;
    print(cout, s4);
    cout << endl;
    return 0;
}

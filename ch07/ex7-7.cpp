#include "ex7-6.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
    Sales_data total;

    if(read(cin, total)) {
        Sales_data trans;
        while (read(cin, trans)) {
            if (trans.isbn() == total.isbn())
                total.combine(trans);
            else {
                print(cout, total);
                cout << endl;
                total = trans;
            }
        }
        print(cout, total);
        cout << endl;
    } else {
        cerr << "NO data?!" << endl;
        return -1;
    }
    return 0;
}

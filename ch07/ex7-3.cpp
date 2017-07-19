#include "ex7-2.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
    Sales_data total;

    if(cin >> total.bookNO >> total.units_sold >> total.revenue) {
        Sales_data trans;
        while (cin >> trans.bookNO >> trans.units_sold >> trans.revenue) {
            if (trans.isbn() == total.isbn())
                total.combine(trans);
            else {
                cout << total.bookNO << " " << total.units_sold << " " << total.revenue << endl;
                total = trans;
            }
        }
        cout << total.bookNO << " " << total.units_sold << " " << total.revenue << endl;
    } else {
        cerr << "NO data?!" << endl;
        return -1;
    }
    return 0;
}

#include "ex7-12.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
    Sales_data total(cin);

    if(!total.isbn().empty()) {
        std::istream& is = std::cin;

        while (is) {
            Sales_data trans(is);
            if (trans.isbn() == total.isbn())
                total.combine(trans);
            else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    } else {
        cerr << "NO data?!" << endl;
        return -1;
    }
    return 0;
}


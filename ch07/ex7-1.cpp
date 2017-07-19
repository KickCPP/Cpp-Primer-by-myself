#include <iostream>
#include <string>

using namespace std;

struct Sales_data {
    string bookNO;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main() {
    Sales_data total;

    if(cin >> total.bookNO >> total.units_sold >> total.revenue) {
        Sales_data trans;
        while (cin >> trans.bookNO >> trans.units_sold >> trans.revenue) {
            if (trans.bookNO == total.bookNO) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            }
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

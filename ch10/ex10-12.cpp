#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../ch07/ex7-25.h"     // Sales_data class.

using namespace std;

inline bool
compareIsbn(Sales_data &s1, Sales_data &s2)
{
    if (s1.isbn() < s2.isbn())
        return true;
    return false;
}

int main()
{
     Sales_data d1("aa"), d2("aaaa"), d3("aaa"), d4("z"), d5("aaaaz");
     vector<Sales_data> v{ d1, d2, d3, d4, d5 };

     sort(v.begin(), v.end(), compareIsbn);
     for(const auto &element : v)
        cout << element.isbn() << " ";
     cout << endl;

    return 0;
}

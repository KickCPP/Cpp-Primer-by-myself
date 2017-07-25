#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std::placeholders;
using std::vector; using std::string;

bool checkLen(const string &s, string::size_type t)
{
    return s.size() <= t;
}

int main()
{
    vector<string> svec{
    "1234567","12","123","123456","12345678"
    };
    std::cout << count_if(svec.begin(), svec.end(), bind(checkLen, _1, 6)) << std::endl;
    return 0;
}

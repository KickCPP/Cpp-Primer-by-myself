#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

int main()
{
    vector<string> v{
        "123456","123456","1234567","1234","123"
    };
    std::cout << std::count_if(v.begin(), v.end(), [](const string &s) {return s.size() > 6;}) << std::endl;
    return 0;
}

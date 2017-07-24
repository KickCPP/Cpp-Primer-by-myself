#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    vector<char> cv{'h','e','l','l','o'};
    string s(cv.cbegin(), cv.cend());
    cout << "string: " << s << endl;
    return 0;
}

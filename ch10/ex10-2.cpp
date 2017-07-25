#include <algorithm>
#include <list>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    list<string> slst{"aa","bb","aa","cc","aa","ww"};
    cout << "aa appears: " << count(slst.begin(), slst.end(), "aa") << " times" << endl;
    return 0;
}

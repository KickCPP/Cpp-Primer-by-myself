#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include <fstream>

using std::string; using std::vector; using std::istream_iterator;

int main()
{
    std::ifstream fin("10-29");
    istream_iterator<string> in(fin), eof;
    vector<string> svec(in, eof);
    for (auto s: svec)
        std::cout << s << " ";
    return 0;
}

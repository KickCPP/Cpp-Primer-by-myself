#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>

using std::cin; using std::cout;
using std::istream_iterator; using std::ostream_iterator;
using std::vector;

int main()
{
    istream_iterator<int> in(cin), eof;
    ostream_iterator<int> out(cout, "\n");
    vector<int> v(in, eof);
    std::sort(v.begin(), v.end());
    std::copy(v.begin(), v.end(), out);
    return 0;
}

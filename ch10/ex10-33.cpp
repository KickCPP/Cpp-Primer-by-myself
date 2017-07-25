#include <iterator>
#include <algorithm>
#include <fstream>

using std::istream_iterator; using std::ostream_iterator;

int main()
{
    std::ifstream fin("10-33");
    std::ofstream evenFout("even"), oddFout("odd");
    ostream_iterator<int> evenOut(evenFout, "\n");
    ostream_iterator<int> oddOut(oddFout, " ");
    istream_iterator<int> in(fin), eof;
    std::for_each(in, eof, [&evenOut, &oddOut](const int v)
                  {*(v & 0x1 ? oddOut : evenOut) = v;});
    return 0;
}


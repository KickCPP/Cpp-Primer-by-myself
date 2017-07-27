#include "ex12-19.h"
#include <fstream>
#include <iostream>

int main()
{
    std::ifstream ifs("12-20.txt");
    StrBlob blob;
    for (std::string s; std::getline(ifs, s); )
        blob.push_back(s);
    for (StrBlobPtr blobptr=blob.begin(); blobptr != blob.end(); blobptr.incr())
        std::cout << blobptr.deref() << "\n";
    return 0;
}

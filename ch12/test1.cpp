#include "ex12-19.h"
#include <fstream>
#include <iostream>

int main()
{
    std::ifstream ifs("12-20.txt");
    const StrBlob blob{"test","test1"};
    for (StrBlobPtr blobptr=blob.begin(); blobptr != blob.end(); blobptr.incr())
        std::cout << blobptr.deref() << "\n";
    StrBlobPtr blobptr=blob.begin();
    blobptr.deref() = "hello";
    std::cout << blobptr.deref() << "\n";
    return 0;
}

#include "ex12-22.h"
#include <iostream>

int main()
{
    const StrBlob blob{"hello", "world"};
    for (ConstStrBlobPtr blobptr=blob.begin(); blobptr != blob.end(); blobptr.incr())
        std::cout << blobptr.deref() << "\n";
    /*»á±¨´í
    ConstStrBlobPtr blobptr=blob.begin();
    blobptr.deref() = "test";
    */
    return 0;
}

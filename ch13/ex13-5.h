#ifndef 13_5_H
#define 13_5_H

#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr& h):
        ps(new std::string(*h.ps)), i(h.i) {}
private:
    std::string *ps;
    int i;
};
#endif // 13_5_H

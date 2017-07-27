#ifndef EX12_19_H
#define EX12_19_H

#include <string>
#include <vector>
#include <memory>
#include <exception>
#include "ex12-2.h"

class StrBlobPtr
{
public:
    StrBlobPtr(): cur(0) {}
    StrBlobPtr(StrBlob &a, std::size_t sz=0):
        wptr(a.data), cur(sz) {}
    std::string& deref() const;
    StrBlobPtr& incr();
    bool operator!=(const StrBlobPtr& p) {return cur != p.cur;}
private:
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t cur;
};

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string& msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("Unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

std::string& StrBlobPtr::deref() const
{
    auto ret = check(cur, "dereference pass end");
    return (*ret)[cur];
}

StrBlobPtr& StrBlobPtr::incr()
{
    auto ret = check(cur, "increment pass end of StrBlobPtr");
    ++cur;
    return *this;
}

StrBlobPtr StrBlob::begin() {return StrBlobPtr(*this);}
StrBlobPtr StrBlob::end() {return StrBlobPtr(*this, this->size());}
#endif // EX12_19_H

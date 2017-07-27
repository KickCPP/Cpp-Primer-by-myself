#ifndef EX12_22_H
#define EX12_22_H

#include <string>
#include <vector>
#include <memory>
#include <exception>
#include "ex12-2.h"

class ConstStrBlobPtr
{
public:
    ConstStrBlobPtr(): cur(0) {}
    ConstStrBlobPtr(const StrBlob &a, std::size_t sz=0):
        wptr(a.data), cur(sz) {}
    const std::string& deref() const;
    ConstStrBlobPtr& incr();
    bool operator!=(const ConstStrBlobPtr& p) {return cur != p.cur;}
private:
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t cur;
};

std::shared_ptr<std::vector<std::string>>
ConstStrBlobPtr::check(std::size_t i, const std::string& msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("Unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

const std::string& ConstStrBlobPtr::deref() const
{
    auto ret = check(cur, "dereference pass end");
    return (*ret)[cur];
}

ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
    auto ret = check(cur, "increment pass end of StrBlobPtr");
    ++cur;
    return *this;
}

ConstStrBlobPtr StrBlob::begin() const {return ConstStrBlobPtr(*this);} //应该加const，表示const StrBlob 调用 begin()会得到ConstStrBlobPtr
ConstStrBlobPtr StrBlob::end() const {return ConstStrBlobPtr(*this, this->size());}
#endif // EX12_22_H


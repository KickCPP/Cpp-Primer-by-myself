#ifndef EX_12_2_H
#define EX_12_2_H

#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <exception>

class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob {
friend class StrBlobPtr;
friend class ConstStrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob(): data(std::make_shared<std::vector<std::string>>()) {}
    StrBlob(std::initializer_list<std::string> ls):
        data(std::make_shared<std::vector<std::string>>(ls)) {}
    size_t size() const {return data->size();}
    bool empty() const {return data->empty();}
    void push_back(const std::string &s) {data->push_back(s);}
    void pop_back();
    std::string& front();
    const std::string& front() const;
    std::string& back();
    const std::string& back() const;
    ConstStrBlobPtr begin() const;
    ConstStrBlobPtr end() const;
    StrBlobPtr begin();
    StrBlobPtr end();
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

void StrBlob::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

std::string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

const std::string& StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

const std::string& StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}
#endif // EX_12_2_H

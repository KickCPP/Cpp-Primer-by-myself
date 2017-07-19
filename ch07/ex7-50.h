#ifndef EX_7_50_H
#define EX_7_50_H
#include <string>
#include <iostream>

class Person {
    friend std::istream &read(std::istream &is, Person &person);
    friend std::ostream& print(std::ostream&, const Person&);
public:
    Person() = default;
    Person(std::string name, std::string addr): name(name), addr(addr) {}
    explicit Person(std::istream &is) {read(is, *this);}
    std::string getName() const { return name; };
    std::string getAddr() const { return addr; };

private:
    std::string name = "";
    std::string addr = "";
};

std::ostream& print(std::ostream& os, const Person& p) {
    os << p.getName() << " " << p.getAddr();
    return os;
}

std::istream &read(std::istream &is, Person &person)
{
    is >> person.name >> person.addr;
    return is;
}
#endif // EX_7_50_H

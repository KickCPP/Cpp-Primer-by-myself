#ifndef EX_7_22_H
#define EX_7_22_H
#include <string>

class Person {
    friend std::ostream& print(std::ostream&, const Person&);
public:
    Person() = default;
    Person(std::string name, std::string addr): name(name), addr(addr) {}
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
#endif // EX_7_22_H

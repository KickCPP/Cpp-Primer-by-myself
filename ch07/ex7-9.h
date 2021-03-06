#ifndef EX_7_9_H
#define EX_7_9_H
#include <string>

struct Person {
    std::string getName() const { return name; };
    std::string getAddr() const { return addr; };
    std::string name;
    std::string addr;
};

std::ostream& print(std::ostream& os, const Person& p) {
    os << p.getName() << " " << p.getAddr();
    return os;
}
#endif // EX_7_9_H

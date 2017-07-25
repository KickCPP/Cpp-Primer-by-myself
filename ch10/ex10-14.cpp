#include <iostream>

int main()
{
    auto f = [](int a1, int a2) {return a1+a2;};
    std::cout << f(1,3) << std::endl;
    return 0;
}

#include <vector>
#include <iostream>

using ptr = std::vector<int>*;

ptr make_ptr()
{
    return new std::vector<int>;
}

ptr populate(ptr vec)
{
    for (int i; std::cout <<"Please Enter\n", std::cin >> i; vec->push_back(i));
    return vec;
}

int main()
{
    auto vec = make_ptr();
    vec = populate(vec);
    for (auto i: *vec)
        std::cout << i << " ";
    std::cout << std::endl;
    delete vec;
    return 0;
}

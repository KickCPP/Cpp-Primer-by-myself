#include <vector>
#include <iostream>
#include <memory>

using ptr = std::shared_ptr<std::vector<int>>;

ptr make_ptr()
{
    return std::make_shared<std::vector<int>>();
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
    return 0;
}

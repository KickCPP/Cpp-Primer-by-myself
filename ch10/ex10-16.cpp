#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void elimDups(std::vector<std::string>& words)
{
    std::sort(words.begin(), words.end());
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies(std::vector<std::string> &words,
             std::vector<std::string>::size_type sz)
{
    elimDups(words);
    std::stable_sort(words.begin(), words.end(),
                     [](std::string const &s1,std::string const &s2) {return s1.size() < s2.size();});
    auto f = [sz](const std::string &s) {return s.size() >= sz;};
    auto wc = std::find_if(words.begin(), words.end(), f);
    auto count = words.end() - wc;
    std::cout << count << " " << (count > 1 ? "words " : "word ")
    << "of length " << sz << " or longer" << std::endl;
    std::for_each(wc, words.end(),
                  [](const std::string &s) {std::cout << s << " ";});
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> v
    {
        "1234","1234","1234","hi~", "alan", "alan", "cp"
    };
    biggies(v, 3);
    return 0;
}

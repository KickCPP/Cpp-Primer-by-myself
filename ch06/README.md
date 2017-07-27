## [6.27](ex6-27.cpp)
## 6.28
`elem`的类型是`const std::string &`类型
## 6.29
不一定，这个取决于`initializer_list`的元素类型，如果元素类型是[POD type](http://en.cppreference.com/w/cpp/concept/PODType),常量引用不是必要的，因为拷贝POD类型的开销很小（如int)。否则的话，使用常量引用更加合适。
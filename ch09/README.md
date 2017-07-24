## 9.1
* `list`容器更适合，因为会存在大量的中间位置插入操作
* `deque`容器更合适，因为插入/删除操作在头部尾部进行
* `vecto`r容器，插入之后调用`sort()`排序即可

## 9.2
```cpp
list<deque<int>> a;
```
## 9.3
构成迭代器范围的两个迭代器构成了一个左闭合的区间。
## 9.4
```cpp
bool find(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int n)
{
    while(begin != end && *begin != n)
        begin++;
    if (begin != end)
        return true;
    return false; 
}
```
## 9.5
```cpp
std::vector<int>::const_iterator
find(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end, int n)
{
    while(begin != end && *begin != n)
        begin++;
    return begin;
}
```
## 9.6
`list`容器中的迭代器不支持比较操作，只支持判等操作，因此：
```cpp
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
while (iter1 != iter2)
```
## 9.7
```cpp
vector<int>::size_type
```
## 9.8
```cpp
list<string>::const_iterator
list<string>::iterator
```
## 9.9
`begin`返回iterator迭代器类型，而`cbegin`返回const_iterator迭代器类型。
## 9.10
it1 is `vector<int>::iterator`  
it2, it3 and it4 are `vector<int>::const_iterator`

## 9.11
```cpp
vector<int> v = {1,2,3}; //列表初始化，v包含{1,2,3}
vector<int> v1(v); //拷贝初始化，v1包含{1,2,3}
vector<int> v2 = v; //拷贝初始化，v2包含{1,2,3}
vector<int> v3{1,2,3}; //列表初始化，v3包含{1,2,3}
vector<int> v4(v.begin(), v.end()); //迭代器指定的范围拷贝初始化，v4包含{1,2,3}
vector<int> v5(10); //v5包含10个元素，每个元素都为0
vector<int> v6(10, 1); //v6包含10个元素，每个元素都为1
```

## 9.12
接受一个容器的拷贝构造函数要求两个容器具有相同的容器类型，并且保存的元素具有相同的元素类型。  
接受两个迭代器的创建构造拷贝函数并不要求两个容器具有相同的容器类型，对于保存的元素仅要求元素类型能相容。

## 9.13
```cpp
list<int> l{1,2,3};
vector<double> v(l.beigin(), l.end());
vector<int> v1(1,2,3);
vector<double> v2(v1.begin(), v1.end());
```

## [9.14](ex9-14.cpp)
## [9.15](ex9-15.cpp)
## [9.16](ex9-16.cpp)
## 9.17
两个容器的容器类型必须相同，容器中的元素类型必须相同，而且容器中的元素支持`<`操作。
## [9.18](ex9-18.cpp)
## [9.19](ex9-19.cpp)
## [9.20](ex9-20.cpp)
## 9.21
都是在头部循环插入新的元素
## [9.22](ex9-22.cpp)
## 9.23
`val1`,`val2`,`val3`,`val4`的值都是相等的。
## [9.24](ex9-24.cpp)
## 9.25
`elem1`与`elem2`相等是不会删除任何元素，仅仅返回`elem1`；会删除迭代器`elem1`到容器中最后一个元素，最后返回尾后迭代器。
## [9.26](ex9-26.cpp)
## [9.27](ex9-27.cpp)
## [9.28](ex9-28.cpp)
## 9.29
`vec.resize(100);`会在`vec`尾部新增75个元素；  
`vec.resize(10);`会删除`vec`尾部的90个元素
## 9.30
元素类型如果不是默认类型，则该类型必须具有默认构造函数
## [9.31](ex9-31.cpp)
`list`容器的迭代器不支持`+=`操作，`forward_list`仅支持`insert_after`操作以及`erase_after`
## 9.32
不合法，`insert`函数的第一个参数`iter`迭代器是不确定的。
## [9.33](ex9-33.cpp)
`insert`语句执行之后，原来的`begin`迭代器已经失效
## [9.34](ex9-34.cpp)
一旦遇到奇数元素，就会死循环不断插入该奇数元素
## 9.35
vector的capacity指的是容器在不扩张内存的情况下，能容纳多少元素  
size指的是容器中已经保存的元素数目
## 9.36
一个容器的capacity是不可能小于它的size的，一旦size超过当前capacity，容器会分配新的内存空间以容纳元素。
## 9.37
因为`list`的存储空间并不像`string`,`vector`这样是连续的存储空间，其存储空间并不连续，新增一个链表节点只需和之前的节点用指针连接   
`array`的内存空间是固定的，所以没有`capacity`成员函数
## [9.38](ex9-38.cpp)
## 9.39
为容器`svec`预留1024个元素的内存空间，`while`循环不断向容器中添加元素。如果容器中元素的数目的1.5倍不大于当前容器的容量，则`resize`操作将当前容器的元素数目增加到现在的1.5倍。否则`resize`操作将容器的元素数目变为当前的1.5倍以及容量会扩展容纳这些元素
## [9.40](ex9-40.cpp)
如果读入了256个单词，`resize`之后的capacity仍为1024；如果读入了512个单词`resize`之后的capacity仍为1024；如果读入了1000个单词，`resize`之后的capacity为1500；如果读入了1048个单词，`resize`之后的capacity为1572。实际上用g++编译运行：
| read | size | capacity |
------ | ---- | -------- |
256 | 384 | 1024 |
512 | 768 | 1024 |
1000 | 1500 | 2000 |
1048 | 1572 | 2048 |
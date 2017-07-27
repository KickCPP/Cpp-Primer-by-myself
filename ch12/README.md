## 12.1
`b1`包含4个元素；`b2`在离开作用域之后被销毁。
## 12.2 [Header](ex12-2.h) | [Test](ex12-2.cpp)
## 12.3
语法上是可以的，因为`push_back`和`pop_back`并不会修改`StrBlob`的成员，它的成员只有一个智能指针`data`，这两个操作是不会修改`data`的。但是从逻辑上讲，这样的操作不合适。
## 12.4
因为`i`的类型是`std::vector<std::string>::size_type`，这是一个`unsigned`类型，即使`i`为负数，也会转换为正数。因此不需要检查`i`是否大于0.
## 12.5
## [12.6](ex12-6.cpp)
## [12.7](ex12-7.cpp)
## 12.8
```cpp
bool b() {
    int* p = new int;
    // ...
    return p;
}
```
有误，指向动态内存的指针被转换为bool类型，因此无法释放动态内存
## 12.9
```cpp
int *q = new int(42), *r = new int(100);
r = q;
auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2;
```
* 指针`r`原来指向的内存不会释放了，内存泄露。`r`和`q`共同指向`q`原来指向的内存
* 智能指针`r2`原来指向的内存释放了。`r2`和`q2`共同指向`q2`原来指向的内存
## [12.10](ex12-10.cpp)
正确
## [12.11](ex12-11.cpp)
`std::shared_ptr<int>(p.get())`创建一个独立的`std::shared_ptr`，但与`p`绑定相同的指针，因此在`process`结束之后，新创建的独立的智能指针被销毁，指向的对象也被释放。因此再使用智能指针解引用`*p`会访问到未定义的内存空间。
## 12.12
```cpp
auto p = new int();
auto sp = std::make_shared<int>();
process(sp); //合法，会拷贝智能指针sp
process(new int()); //不合法，process接收的参数是智能指针，普通指针无法自动转换为智能指针
process(p);  //不合法，process接收的参数是智能指针，普通指针无法自动转换为智能指针
process(std::shared_ptr<int>(p)); //合法，std::shared_ptr<int>(p)创建临时的智能指针作为process的参数
```
## [12.13](ex12-13.cpp)
## [12.14](ex12-14.cpp)
## [12.15](ex12-15.cpp)
## [12.16](ex12-16.cpp)
## 12.18
```cpp
int ix = 1024, *pi = &ix, *pi2 = new int(2048);
typedef std::unique_ptr<int> IntP;
IntP p0(ix); //不合法，不能用整型构造unique_ptr
IntP p1(pi); //不合法，可以编译，构造unique_ptr的指针不是指向动态内存的指针，unique_ptr被销毁时会调用delete删除该指针
IntP p2(pi2); //不合法，可以编译，但是p2销毁之后，会导致空悬指针pi2
IntP p3(&ix); //不合法，可以编译，构造unique_ptr的指针不是指向动态内存的指针，unique_ptr被销毁时会调用delete删除该指针
IntP p4(new int(2048)); //合法
IntP p5(p2.get()); //不合法，两个不同的unique_ptr使用同一指针
```
## 12.18
因为`shared_ptr`不需要像`unique_ptr`一样转移指针的控制权，所有的智能指针都是共享底层指针，不存在放弃所有权一说。  
参考[Link](https://stackoverflow.com/questions/1525764/how-to-release-pointer-from-boostshared-ptr)

## [12.19](ex12-19.h)
## [12.20](ex12-20.h)
## 12.21
```cpp
std::string& deref() const
{ return (*check(curr, "dereference past end"))[curr]; }
```
原来的版本更好，原来的版本先检查当前索引`cur`所在的范围是否越界，如果越界则抛出异常，没有越界，就使用返回的智能指针索引相应的值。这个改版的操作将检查越界和索引值一起写，可读性差。
## [12.22](ex12-22.h)
一般的`StrBlobPtr`类型的解引用是可以修改`StrBlob`底层`vector`中存储的`string`类型的。所以直接在`StrBlobPtr`类型的构造函数上修改，使其参数支持`const StrBlob`，得到的`StrBlobPtr`类型将会可以直接修改`const StrBlob`底层`vector`中存储的`string`类型，这样并不符合逻辑。但是普通的`StrBlobPtr`类型的解引用应该具有可以修改`StrBlob`底层`vector`中存储的`string`类型的能力，所以需要重新定义一个`ConstStrBlobPtr`类型。
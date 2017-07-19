## [7.1](ex7-1.cpp)
## [7.2](ex7-2.h)
## [7.3](ex7-3.cpp)
## [7.4](ex7-4.h)
## [7.5](ex7-5.h)
## [7.6](ex7-6.h)
## [7.7](ex7-7.cpp)
## [7.9](ex7-9.h)

## 7.10
先读取第一个数据到变量data1，再读取第二个数据到data2

## 7.11[Header](ex7-11.h) | [Source](ex7-11.cpp)
## 7.12
## 7.13
## 7.14
```cpp
Sales_data() : bookNo(""), units_sold(0) , revenue(0){ }
```

## 7.16
对于访问说明符出现的位置和次数没有限定，接口成员函数和构造函数应该在public说明符之后，实现部分的函数应该在private说明符之后。

## 7.17
class默认的访问说明符是private，struct默认的访问说明符是public

## 7.18
封装实现了类的接口和实现的分离。封装隐藏了类具体实现的细节。
## 7.19
将`name`和`addr`成员声明为private，将`getName()`和`getAddr()`以及构造函数声明为public。因为这样就封装了Person类实现的细节，防止用户直接操作类的成员，强制用户只能使用类的接口。

## 7.20
友元允许其他函数或者类访问类的非公成员，友元提供了很大的权限和灵活性，但滥用友元会让其他的类和函数破坏对象的状态。

## [7.21](ex7-21.h)
## [7.22](ex7-22.h)
## [7.23](ex7-23.h)
## [7.24](ex7-24.h)
## 7.25
能够安全地依赖默认的拷贝和赋值操作的默认版本，因为Screen的成员都能正确地执行拷贝和赋值操作。

## 7.27 [Header](ex7-27.h) | [Source](ex7-27.cpp)
## 7.28
第一显示含有'#'，第二次显示的内容中不含'#'。
## 7.29
检查正确
## 7.30
显示地使用this指针会使语义更加清晰，同时也可使用类的函数成员；缺点就是显得多余。
## 7.31
```cpp
class Y;
class X {
    Y* py;
}
class Y{
    X a;
}
```
## [7.32](ex7-32.h)
## [7.33](ex7-33.h)
## 7.34
成员函数`dummy_fcn`的参数类型`pos`是未定义的
## 7.35
```cpp
typedef string Type;
Type initVal(); // use `string`
class Exercise {
public:
    typedef double Type;
    Type setVal(Type); // use `double`
    Type initVal(); // use `double`
private:
    int val;
};

Type Exercise::setVal(Type parm) {  // first is `string`, second is `double`
    val = parm + initVal();     // Exercise::initVal()
    return val;
}
```
**fixed**

changed
```cpp
Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}
```
to
```cpp
Exercise::Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}
```
and `Exercise::initVal()`should be defined.

## 7.36
构造函数会先初始rem，之后才初始化base。这个构造函数会尝试使用未初始化的base初始化rem。修改为：
```cpp
struct X{
    X (int i, int j):rem(i%j), base(i) {}
    int rem, base;
}
```
## 7.37
```cpp
Sales_data first_item(cin);   // use Sales_data(std::istream &is) ; its value are up to your input.

int main() {
  Sales_data next;  // use Sales_data(std::string s = ""); bookNo = "", cnt = 0, revenue = 0.0
  Sales_data last("9-999-99999-9"); // use Sales_data(std::string s = ""); bookNo = "9-999-99999-9", cnt = 0, revenue = 0.0
}
```

## 7.38
```cpp
Sales_data(std::istream &is = std::cin) { read(is, *this); }
```
## 7.39
不合法，因为默认构造函数使用的时候，不知道使用其中哪一个默认实参的构造函数
## 7.40
## 7.41 [Header](ex7-41.h) | [Source](ex7-41.cpp)
## 7.42 
## 7.43
```cpp
class NoDefault {
public:
    NoDefault(int i) { }
};

class C {
public:
    C(): member(0) {}
private: 
    NoDeafault member;
}
```
## 7.44
不合法，`vec`中的元素将执行默认初始化，但是`NoDefault`没有默认构造函数
## 7.45
合法，`C`定义了默认构造函数
## 7.46
* 不对，就算类不提供构造函数，编译器会生成合成的默认构造函数
*  不对，有可能是构造函数的参数列表均有默认值
>A default constructor is a constructor which can be called with no arguments (either defined with an empty parameter list, or with default arguments provided for every parameter). 
*  不对，应该提供默认构造函数
* 不对，如果类定义了其他的构造函数，编译器是不会生成合成的默认构造函数
## 7.47
## 7.48
`Sales_data`的构造函数不是explicit的时候，`item1`，`item2`的构造函数执行成功。  
`Sales_data`的构造函数是explicit的时候，`item1`，`item2`的构造函数执行成功。
## 7.49
```cpp
a) Sales_data& combine(Sales_data); //right
b) Sales_data& combine(Sales_data&); //error: invalid initialization of non-const reference of type 'Sales_data&' from an rvalue of type 'Sales_data'  
c) Sales_data& combine(const Sales_data&); //right
```
临时对象是个左值，只能用作第一种情况或者const引用，不能用作一般引用。

## 7.50
## 7.51
vector的单参数是整数，如果直接用整数做参数，压根不知道将其转换为啥，不明显；而string的隐式转换是从const char *转换为string，两者接近，很容易理解。
## 7.52
将Sales_data修改为聚合类：
```cpp
struct Sales_data {
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};
```
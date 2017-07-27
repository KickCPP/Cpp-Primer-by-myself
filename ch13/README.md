## 13.1
如果一个构造函数的第一个参数是自身类类型的引用，且任何额外的参数都是默认值，则此构造函数就是拷贝构造函数。   
拷贝构造函数的使用场景：
* 用等号定义变量
* 将一个对象作为实参传递给一个非引用类型的形参
* 从一个返回类型为非引用类型的函数返回一个对象
* 用花括号列表初始化一个数组中的元素或者聚合类中的元素
* 标准库容器的添加元素的成员函数`insert`,`push`；相比之下`emplace`就是直接初始化

## 13.2
```cpp
Sales_data::Sales_data(Sales_data rhs);
```
如果将`Sales_data`的构造函数这样定义，那么在调用构造函数`Sales_data(Sales_data rhs)`时，是向构造函数传递一个非引用的形参，因此会调用`Sales_data`的拷贝构造函数。如果是将拷贝构造函数错误定义成这样，拷贝构造函数定义失败。

## 13.4
```cpp
Point global;
Point foo_bar(Point arg) // Point对象作为实参传递给foo_bar函数会使用拷贝构造函数
{
    Point local = arg, *heap = new Point(global); // local变量初始化，new Point也会用到拷贝构造函数
    *heap = local;
    Point pa[ 4 ] = { local, *heap }; // 初始化pa数组中的变量会用到拷贝构造函数
    return *heap; // 从foo_bar函数返回会使用拷贝构造函数
}
```

## [13-5](ex13-5.h)
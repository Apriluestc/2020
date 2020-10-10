# const 关键字

const 修饰一个变量为可读，意味着该变量里的数据只能被访问，而不能被修改，const 离谁近意味着谁就不能被修改

### const 作用

[const 详解](https://blog.csdn.net/Eric_Jo/article/details/4138548)

- const 可以用来定义常量，修饰函数参数、修饰函数返回值、且被 const 修饰的东西，都受到强制保护，可以预防其他代码无意识的进行修改，从而
提高了程序的健壮性
- 是编译器保护那些不希望被修改的参数，防止无意识的修改，减少 Bug
- 提高程序可读性，声明一个参数，是为了告诉用户这个参数的应用目的
- const 修饰的函数只能调用 const 修饰的成员函数，被 const 修饰的成员函数不能修改对象的数据成员且不能调用非 const 函数
- 修饰指针，指向的内容不可更改或者指针本身的指向不能修改
- 修饰引用，引用的对象不可修改
- 修饰类，只能调用该类的const成员函数，不能修改该类的任何成员
- 修饰成员函数，不能修改该类的任何成员，只能调用该类的const成员函数

### 举个栗子

```cpp
const int *p;        修饰 int 即 *p 所指向的内容无法改变
int const *p;        修饰 int 即 *p 所指向的内容无法改变
int *const p;        修饰 int* 即 *p 不能改变指向
const int *const p;  修饰 int 和 int* 指向和所指向的内容都不能改变

class A {
public:
    const void func(const int m_value) const;
};
```

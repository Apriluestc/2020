# struct 和 class 区别

### 默认的访问权限

- class 中默认的访问权限是 private 的，而 struct 中则是 public 的

### 默认的继承权限

- 默认继承权限。如果不明确指定，来自class的继承按照private继承处理，来自struct的继承按照public继承处理

### 大括号初始化问题

- 在 C 语言中，我们知道 struct 是一种数据类型，只能定义数据成员，不能定义函数，这是因为 C 是面向过程，面向过程认为
数据和操作是分开的，所以 C 语言中可以看到这样的情况

```cpp
struct test {
    int a;
    int b;
};

test A = {1, 2}; // 完全可以
```

- 在 C++ 中 struct 的功能进行了扩展，struct 可以被继承，可以包含成员函数，也可以实现多态，用大括号初始化
时需注意
  - 当 struct 和 class 中都定义了构造函数就不能使用大括号进行初始化
  - 若没有定义构造函数，struct 可以用 {} 进行初始化，而只有当 class 的所有数据成员集函数为 public 时才可以使用 {} 初始化

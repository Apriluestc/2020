# vector 详解

- vector 维护的是一段连续线性空间，所以不论其元素类型为何，普通指针都可作为 vector 的迭代器而满足所有必要条件
- 增加新元素，如果超出当前容量，则容量会扩充至两倍

### vector 上常见的操作复杂度

- 随机访问、尾插、尾删 O(1)
- 插入或者移除元素 O(n)

### vector 的迭代器类型

- vector 的迭代器涵盖了原生指针的算术能力，同时 vector 支持随机存取，所以 vector 提供的是随机访问迭代器
- 迭代器函数
  - begin()：获取首元素位置，起始位置
  - end()：返回最后一个元素的下一个位置，vector 实现遵循区间左开右闭原则

### vector 的扩容原理，动态扩容

- 所谓动态扩容，并不是在原空间之后接后续的新空间，而是另外配置一块大空间，然后将原内容拷贝过来，接着就是在原内容之后构造新元素，并释放原来空间，因此
vector 的空间一旦重新配置，指向原 vector 的所有迭代器均会失效
  - 配置一块更大的空间
  - 将原内容拷贝过去
  - 释放原空间

### vector 的数据结构

```cpp
template<class T, class Alloc = alloc>
class vector {
public:
    typedef T value_type;
    typedef value_typr* iterator;
protected:
    iterator start; // 表示目前使用空间的头
    iterator finish;// 表示目前使用空间的尾
    iterator end_of_storage; // 表示目前可用空间的尾
}；
```

### 与 capicaty、size 有关的函数

- resize()
  - resize 可以改变有效空间的大小
  - resize 可以改变默认值，但其改变的范围是有限制的，这个范围是当前设定的 size_tmp 范围
  - 当新设定的 size_tmp 大于之前的 size 时，默认参数只作用于多开辟的那些空间
  - 当 resize 的 size 改变时，capacity 也会随着改变，但是当 reserve 改变 capacity 的大小后，size 的大小并不会随之改变，他仍然是原来有效元素的个数
- reserve()：直接区别就是 reserve 只有一个参数
  - reserve 中的参数 n 改变的是总空间的大小，它开辟出来的 n 个空间并不代表的都是有效空间只有 object,size() 才表示有效空间
- push_back()
  - push_back 作用是尾插，他可能引起 vector 扩容

### vector 的基本操作

- push_back：尾部插入元素
- pop_back：尾部删除元素
- erase：清除 [first，last] 元素，或删除某个位置上的元素
- insert：从某个位置插入 n 个元素，元素初值 x
- clear：清除所有元素

### STL 迭代器失效

- 增加新元素到容器后
- 从容器删除元素

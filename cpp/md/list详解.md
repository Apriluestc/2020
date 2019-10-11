# list 详解

- STL list 是一个双向链表，迭代器必须具备前移、后移的能力，环状双向链表，对于任何位置的元素插入删除永远是常数时间
- 只要刻意在环状链表的尾端加上一个空白节点，便符合 STL 规范之前闭后开的原则

### list 结点结构

```cpp
struct _List_node_base {
    _List_node_base* _M_next;
    _List_node_base* _M_prev;
};

template <class _Tp>
struct _List_node : public _List_node_base {
    _Tp _M_data;
};
```

### list 的基本操作

- push_front：插入一个节点，作为头节点
- push_back：将新元素插入到 list 尾端
- pop_front：移除头节点
- pop_back：移除尾部结点
- insert：插入是指插入之前，插入完成后，新节点将位于标识出插入所指结点的前方

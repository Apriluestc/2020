# EVENTFD

## 什么是 eventfd

eventfd 是 Linux 的一个系统调用，创建一个文件描述符用于事件通知

```cpp
#include <sys/eventfd.h>
int eventfd(unsigned int initval, int flags);
eventfd() 用于创建一个 eventfd 对象，可以由用户空间应用程序实现事件等
待/通知机制，或由内核通知该用户应用程序事件

该对象包含了由内核维护的无符号 64 位数整数计数器 count，使用参数 initval 初始化
计数器

struct eventfd_ctx {
    struct kref kref;
    wait_queue_head_t wqh;
    /*
     * Every time that a write(2) is performed on an eventfd, the
     * value of the __u64 being written is added to "count" and a
     * wakeup is performed on "wqh". A read(2) will return the "count"
     * value to userspace, and will reset "count" to zero. The kernel
     * side eventfd_signal() also, adds to the "count" counter and
     * issue a wakeup.
     */
    __u64 count;
    unsigned int flags;
};
```
**上述 flags 可以是以下值的 OR 结果，用以改变 eventfd 行为**

- EFD_CLOEXEC：文件被设置为 O_CLOEXEC，创建子进程(fork)时不继承父进程的文件描述符
- EFD_NONBLOCK：文件被设置为 O_NONBLOCK，执行 read/write 时，不会阻塞
- EFD_SEMAPHORE：提供类似信号量语义的 read 操作，简单说就是计数值 count 递减 1

## 操作方法

一切皆文件时 Linux 内核设计的一种高度抽象，eventfd 的实现也不例外，我们可以用操作文件的方法操作 eventfd

- read(): 读取 count 值后置 0，如果设置 EFD_SEMAPHORE，读到的值为 1，同时 count 值递减 1
- write(): 其实是执行 add 操作，累加 count 值
- epoll()/poll()/select(): 支持 IO 多路复用操作
- close(): 关闭文件描述符，eventfd 对象引用计数减 1，若减为 0，则释放 eventfd 对象资源

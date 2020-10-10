# 项目

### 建立连接

- 连接的建立比较简单，server端通过socket()，bind()，listen()，并使用 epoll ET 模式监听 listenfd 的
读请求，当 TCP 连接完成 3 次握手后，会触发 listenfd 的读事件，应用程序调用 accept()，会检查已完
成的连接队列，如果队列里有连接，就返回这个连接，出错或连接为空时返回 -1。此时，已经可以进行正
常的读写操作了。 当然，因为是 ET 模式，accept() 要一直循环到就绪连接为空

### 处理请求

- 服务启动，服务器连接建立完成后，开启一个主线程、多个工作线程，主线程负责响应 client 的连接请求，并建立
连接，在连接建立完成后使用特定的方式将 fd 分配给某个工作线程
- 当主线程把新连接分配给了某个特定的 subreactor 之后，该线程可能正阻塞在多路选择器当中，
- 如何得知新连接的到来呢，这里使用了 eventfd 进行异步唤醒，线程会从 epoll_wait 中醒来，从 epoll 的就绪队列中拿到活跃事件进行处理
- 在 epoll 触发模式上使用了 ET，它与 LT 在 IO 处理上有着很大的区别，ET 模式要比 LT 模式复杂许多，它对用户提出更高的要求，即
每次读，必须读到不能再读，每次写，写到不能再写的时候
- [ET 和 LT 的区别](https://blog.csdn.net/YMY_mine/article/details/81212731)

### 其他

- [webd](https://github.com/Apriluestc/2020/blob/master/%E9%A1%B9%E7%9B%AE/web.md)
- [对象内存分布](https://github.com/Apriluestc/2020/blob/master/cpp/md/C%2B%2B%E5%AF%B9%E8%B1%A1%E5%86%85%E5%AD%98%E5%88%86%E5%B8%83.md)
- [const](https://github.com/Apriluestc/2020/blob/master/cpp/md/const%E5%85%B3%E9%94%AE%E5%AD%97.md)
- [static](https://github.com/Apriluestc/2020/blob/master/cpp/md/static%E5%85%B3%E9%94%AE%E5%AD%97.md)
- [map & set](https://github.com/Apriluestc/2020/blob/master/cpp/md/map%E5%92%8Cset%E8%AF%A6%E8%A7%A3.md)
- [struct & class](https://github.com/Apriluestc/2020/blob/master/cpp/md/struct%E5%92%8Cclass.md)
- [智能指针](https://github.com/Apriluestc/2020/blob/master/cpp/md/%E6%99%BA%E8%83%BD%E6%8C%87%E9%92%88.md)
- [菱形继承](https://github.com/Apriluestc/2020/blob/master/cpp/md/%E8%8F%B1%E5%BD%A2%E7%BB%A7%E6%89%BF.md)
- [虚函数实现原理](https://github.com/Apriluestc/2020/blob/master/cpp/md/%E8%99%9A%E5%87%BD%E6%95%B0%E5%AE%9E%E7%8E%B0%E5%8E%9F%E7%90%86.md)
- [面向对象三大特性七大原则](https://github.com/Apriluestc/2020/blob/master/cpp/md/%E9%9D%A2%E5%90%91%E5%AF%B9%E8%B1%A1%E4%B8%89%E5%A4%A7%E7%89%B9%E6%80%A7%E4%B8%83%E5%A4%A7%E5%8E%9F%E5%88%99.md)
- [vector](https://github.com/Apriluestc/2020/blob/master/cpp/md/vector%E8%AF%A6%E8%A7%A3.md)
- [shared_ptr](https://github.com/Apriluestc/2020/blob/master/cpp/md/SharedPtr.h)
- [string](https://github.com/Apriluestc/2020/blob/master/cpp/md/String.h)
- [list](https://github.com/Apriluestc/2020/blob/master/cpp/md/list%E8%AF%A6%E8%A7%A3.md)

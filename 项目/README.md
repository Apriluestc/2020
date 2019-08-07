---
title: Apriluestc's projects
---

### 基于 UDP socket 的聊天室

URL：https://github.com/Apriluestc/web.d

本项目为 C++ 编写的多人聊天室，使用 UDP socket 进行通信，支持多人聊天、支持语音聊天

**技术特点**

- C++ STL
- 生产者消费者模型
- 多线程技术，多线程同步原语同步与互斥
- UDP socket 编程

### Web 服务器

URL：https://github.com/Apriluestc/web.d

【测试页】[Apriluestc's pub](http://39.107.70.253:20000/)

本项目为 C++ 11 编写的高性能 Web 服务器，使用状态机解析了 GET、POST 请求，可静态处理资源，支
持 HTTP 长连接、支持管线化请求，并实现了异步日志，实时记录服务器运行状态

**技术特点**

- 使用 Epoll 边沿触发、非阻塞 IO、Reactor 模式
- 使用多线程技术充分发挥多核 CPU 性能
- 定时器定时关闭超时请求和剔除不活跃连接
- 使用状态机解析了 GET 和 POST 请求
- 主线程负责 accept 请求，并随机分配给其他 IO 线程，这样一来锁竞争只会出现在主线程和某一特定线程(如：IO 线程、计算县城、工作线程)
- 使用 eventfd 跨线程异步唤醒
- TCP 接收发送环形缓冲区
- 使用智能指针、RAII 机制规避程序中出现内存泄漏的可能
- 异步日志实时记录服务器运行状态(便于 Debug)
- webd 服务以 dameon 进程运行

# 项目

### 【基于 UDP socket 的聊天室】

URL：https://github.com/Apriluestc/web.d

- 开发了一个基于 C/S 架构的聊天室，支持群聊，该项目使用 UDP socket 进行通信
- 服务端维护在线客户列表以及环形消息队列，达到准确发送和异步通信的效果
- 使用 json 对消息进行序列化和反序列化，使用 ncurses 库绘制图形化客户端界面

### 【Web 服务器】

URL：https://github.com/Apriluestc/web.d

[测试页](http://39.107.70.253:20000/)

本项目为 C++ 11 编写的高性能 Web 服务器，使用状态机解析了 GET、POST 请求，可静态处理资源，支
持 HTTP 长连接、支持管线化请求，并实现了异步日志，实时记录服务器运行状态

#ifndef INCLUDE_SHARED_PTR_H
#define INCLUDE_SHARED_PTR_H

#include <iostream>
#include <map>

class SharedPtr {
public:
    // 构造函数
    SharedPtr(int* ptr) {
        _ptr = ptr;
        g_map.insert(std::pair<int*, int>(_ptr, 1));
    }

    // 拷贝构造函数
    SharedPtr(const SharedPtr& rhx) {
        _ptr = rhx._ptr;
        g_map[_ptr]++;
    }

    // 赋值运算符重载
    SharedPtr& operator=(const SharedPtr& rhx) {
        // 赋值运算符重载
        // 如果参数传进来是当前对象
        // 直接返回 *this
        if (_ptr == rhx._ptr) {
            return *this;
        }

        // 如果传进来的不是当前对象
        // 这里要格外注意
        if (g_map[_ptr] <= 0 && _ptr != nullptr) {
            delete _ptr;
            _ptr = nullptr;
            g_map.erase(_ptr);
        }
        _ptr = rhx._ptr;
        g_map[_ptr]++;
        return *this;
    }

    // 解引用重载
    int& operator*() {
        return *_ptr;
    }

    // 指针运算符重载
    int* operator->() {
        return this->_ptr;
    }

    // 析构函数
    ~SharedPtr() {
        // 什么时候析构
        // 在引用计数为 0 时，并且指针不为空才可以进行 delete
        if (g_map[_ptr] <= 0 && _ptr != nullptr) {
            delete _ptr;
            _ptr = nullptr;
            g_map.erase(_ptr);
        }
    }
    static std::map<int*, int> g_map;
private:
    int* _ptr;
};

// 静态成员初始化
std::map<int*, int> SharedPtr::g_map;

#endif

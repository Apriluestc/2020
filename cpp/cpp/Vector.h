#ifndef INCLUDE_VECTOR_H
#define INCLUDE_VECTOR_H

#include <cstddef>

template<class T>
class Vector {
public:
    Vector()
        :start_(nullptr),
        finish_(nullptr),
        endOfStorage_(nullptr)
    {}
    Vector(T* array, size_t size)
        :start_(new T[size])
    {
        for (size_t i = 0; i < size; ++i) {
            start_[i] = array[i];
        }
        finish_ = start_ + size;
        endOfStorage_ = start_ + size;
    }
    Vector(const Vector<T>& rhx) {
        int size = rhx.Size();
        for (int i = 0; i < size; ++i) {
            start_[i] = rhx.start_[i];
        }
        finish_ = rhx.finish_;
        endOfStorage_ = rhx.endOfStorage_;
    }
    Vector<T>& operator=(const Vector<T>& rhx) {
        int size = rhx.Size();
        if (&rhx != this) {
            for (int i = 0; i < size; ++i) {
                start_[i] = rhx.start_[i];
            }
            finish_ = rhx.finish_;
            endOfStorage_ = rhx.endOfStorage_;
        }
    }
    ~Vector() {
        if (start_) {
            delete start_;
            start_ = finish_ = endOfStorage_ = nullptr;
        }
    }
    void PushBack(const T& val) {
        (*finish_) = val;
        ++finish_;
    }
    void PopBack() {
        --finish_;
    }
    void Insert(size_t index, const T& val) {
        assert(index < Size());
        for (size_t i = Size(); i >= index; --i) {
            start_[i] = start_[i-1];
        }
        start_[index] = val;
        ++finish_;
    }
    void Erase(size_t index) {
        assert(index < Size());
        for (size_t i = index + 1; i < Size(); ++i) {
            start_[i-1] = start_[i];
        }
        --finish_;
    }
    size_t Size() const {
        return finish_ - start_;
    }
    size_t Capacity() const {
        return endOfStorage_ - start_;
    }
    bool Empty() {
        return start_ == finish_;
    }
    T& operator[](size_t index) {
        assert(index < Size());
        return start_[index];
    }
    T& Back() {
        return start_[Size()-1];
    }
    T& Front() {
        return start_[0];
    }
private:
    // 指向空间的起始地址
    T* start_;
    // 指向空间最后一个元素的后面
    T* finish_;
    // 标记空间的容量，指向空间尾
    T* endOfStorage_;
};

#endif

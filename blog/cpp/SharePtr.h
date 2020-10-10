#include <map>

class SharedPtr {
public:
    SharedPtr(int* ptr) {
        ptr_ = ptr;
        map_.insert(std::make_pair(ptr_, 1));
    }
    SharedPtr(const SharedPtr& rhx) {
        ptr_ = rhx.ptr_;
        map_[ptr_]++;
    }
    SharedPtr& operator=(const SharedPtr& rhx) {
        if (ptr_ == rhx.ptr_) {
            return *this;
        }
        if (--map_[ptr_] <= 0 && ptr_ != nullptr) {
            delete ptr_;
            ptr_ = nullptr;
            map_.erase(ptr_);
        }
        ptr_ = rhx.ptr_;
        map_[ptr_]++;
        return *this;
    }
    int& operator*() {
        return *ptr_;
    }
    int* operator->() {
        return ptr_;
    }
    ~SharedPtr() {
        if (--map_[ptr_] <= 0 && ptr_ != nullptr) {
            delete ptr_;
            ptr_ = nullptr;
            map_.erase(ptr_);
        }
    }
    static std::map<int*, int> map_;
private:
    int* ptr_;
};

std::map<int*, int> SharedPtr::map_;

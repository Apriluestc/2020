#include <mutex>
#include <boost/noncopyable.hpp>

class SingletonLz {
public:
    static SingletonLz& getInstance() {
        if (Singleton_ == nullptr) {
            Singleton_ = new SingletonLz();
        }
        return *Singleton_;
    }
private:
    SingletonLz();
    ~SingletonLz();
    static SingletonLz* Singleton_;
};

SingletonLz* SingletonLz::Singleton_ = nullptr;

class SingletonDCL {
public:
    static SingletonDCL& getInstance() {
        if (singleton_ == nullptr) {
            mutex_.lock();
            if (singleton_ == nullptr) {
                singleton_ = new SingletonDCL();
            }
        }
        return *singleton_;
    }
private:
    SingletonDCL();
    ~SingletonDCL();
    static SingletonDCL* singleton_;
    static std::mutex mutex_;
};

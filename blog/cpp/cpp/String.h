#ifndef INCLUDE_STRING_H
#define INCLUDE_STRING_H

#include <cstddef>
#include <cstring>

template<class T>
class String {
public:
    String(char* rhx = nullptr) {
        if (rhx == nullptr) {
            str_ = new char [1];
            *str_ = '\0';
        } else {
            int len = strlen(rhx);
            str_ = new char [len+1];
            strcpy(str_, rhx);
        }
    }
    String(const String& rhx) {
        int len = strlen(rhx.str_);
        str_ = new char [len+1];
        strcpy(str_, rhx.str_);
    }
    String<T>& operator=(const String<T>& rhx) {
        if (this != &rhx) {
            delete [] str_;
            int len = strlen(rhx.str_);
            str_ = new char [len+1];
            strcpy(str_, rhx.str_);
        }
        return *this;
    }
    String<T>& operator+=(const String<T>& rhx) {
        int len = strlen(rhx.str_);
        char* tmp = new char [len+1];
        strcpy(tmp, rhx.str_);
        strcat(tmp, rhx.str_);
        delete [] str_;
        str_ = nullptr;
        str_ = tmp;
        return *this;
    }
    ~String() {
        if (str_) {
            delete [] str_;
        }
    }
    size_t Size() const;
private:
    char* str_;
};

#endif

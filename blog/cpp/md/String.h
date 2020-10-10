#ifndef INCLUDE_STRING_H
#define INCLUDE_STRING_H

#include <cstring>

class String {
public:
    String(char* rhx = nullptr) {
        if (rhx == nullptr) {
            _str = new char [1];
            *_str = '\0';
        } else {
            int len = strlen(rhx);
            _str = new char [len + 1];
            strcpy(_str, rhx);
        }
    }
    String(const String& rhx) {
        int len = strlen(rhx._str);
        _str = new char [len + 1];
        strcpy(_str, rhx._str);
    }
    String& operator=(const String& rhx) {
        if (_str == rhx._str) {
            return *this;
        } else {
            delete [] _str;
            int len = strlen(rhx._str);
            _str = new char [len + 1];
            strcpy(_str, rhx._str);
            return *this;
        }
    }
    ~String() {
        if (_str != nullptr) {
            delete [] _str;
            _str = nullptr;
        }
    }
private:
    char* _str;
};

#endif

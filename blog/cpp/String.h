#include <string.h>

class String {
public:
    String(char* rhx = nullptr) {
        if (rhx == nullptr) {
            c_ = new char[1];
            *c_ = '\0';
        } else {
            int len = strlen(rhx);
            c_ = new char[len + 1];
            strcpy(c_, rhx);
        }
        ++count_;
    }
    String(const String& rhx) {
        int len = strlen(rhx.c_);
        c_ = new char[len + 1];
        strcpy(c_, rhx.c_);
        ++count_;
    }
    String& operator=(const String& rhx) {
        if (this != &rhx) {
            delete [] c_;
            int len = strlen(rhx.c_);
            c_ = new char[len + 1];
            strcpy(c_, rhx.c_);
        }
        return *this;
    }
    ~String() {
        if (c_) {
            delete [] c_;
        }
    }
    static int count_;
private:
    char* c_;
};

int String::count_;

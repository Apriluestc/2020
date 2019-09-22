#include <iostream>
#include "String.h"
#include "SharePtr.h"

using namespace std;

int main()
{
    String str1;
    String str2(str1);
    String str3 = str1;
    str2 = str3;
    cout << String::count_ << endl;
    cout << "-----------------" << endl;
    SharedPtr ptr1(nullptr);
    SharedPtr ptr2(ptr1);
    SharedPtr ptr3 = ptr1;
    return 0;
}

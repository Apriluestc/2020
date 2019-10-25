#include <iostream>
#include <stack>

using namespace std;

template<class T>
class Solution {
public:
    void Push(const T& val) {
        s1.push(val);
    }
    T Pop() {
        if (s2.empty()) {
            while (s1.size() > 0) {
                int data = s1.top();
                s1.pop();
                s2.push(data);
            }
        }
        int pop_element = s2.top();
        s2.pop();
        return pop_element;
    }
private:
    stack<T> s1;
    stack<T> s2;
};

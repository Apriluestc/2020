#include <iostream>
#include <queue>

using namespace std;

template<class T>
class Solution {
public:
    void Push(const T& val) {
        if (q1.empty() && q2.empty()) {
            q1.push(val);
        } else if (q1.empty()) {
            q2.push(val);
        } else {
            q1.push(val);
        }
    }
    T Pop() {
        if (q1.empty()) {
            if (q2.empty()) {
                throw "stack is empty";
            } else {
                if (q2.size() == 1) {
                    T result = q2.front();
                    q2.pop();
                    return result;
                } else {
                    while (q2.size() != 1) {
                        q1.push(q2.front());
                        q2.pop();
                    }
                    T result = q2.front();
                    q2.pop();
                    return result;
                }
            }
        } else {
            if (q1.size() == 1) {
                T result = q1.front();
                q1.pop();
                return result;
            } else {
                while (q1.size() != 1) {
                    q2.push(q1.front());
                    q1.pop();
                }
                T result = q1.front();
                q1.pop();
                return result;
            }
        }
    }
private:
    queue<T> q1;
    queue<T> q2;
};

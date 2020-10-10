#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    while (cin >> str) {
        bool flag = false;
        stack<int> s;
        for (size_t i = 0; i < str.size(); ++i) {
            if (str[i] == '[' || str[i] == '(') {
                s.push(str[i]);
            }
            if (str[i] == ']') {
                if (s.empty()) {
                    flag = false;
                    break;
                } else {
                    char c = s.top();
                    s.pop();
                    if (c == '[') {
                        flag = true;
                    } else {
                        flag = false;
                        break;
                    }
                }
            }
            if (str[i] == ')') {
                if (s.empty()) {
                    flag = false;
                    break;
                } else {
                    char c = s.top();
                    s.pop();
                    if (c == '(') {
                        flag = true;
                    } else {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if (!s.empty()) {
            flag = false;
        }
        if (flag) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}

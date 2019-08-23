#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x) {
    if (x < 2) {
        return false;
    }
    for (int i = 2; i < sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int reversePalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return 0;
    }
    int ans;
    while (x > 0) {
        ans = 10 * ans + (x % 10);
        x /= 10;
    }
    return x == ans || x == ans / 10;
}

int main()
{
    int N = 20;
    vector<int> v;
    for (int i = 1; i <= N; i++) {
        if (isPrime(i) && reversePalindrome(i)) {
            v.push_back(i);
        }
    }
    for (size_t i = 0; i < v.size(); i++) {
        cout << "[" << endl;
        cout << v[i] << ",";
    }
    cout << "]" << endl;
    return 0;
}

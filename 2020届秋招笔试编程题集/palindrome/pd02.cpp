#include <bits/stdc++.h>

using namespace std;

/*
 * 回文素数
 * 遍历所有数字，检查是不是回文串，如果是检查是不是素数，如果
 * 当前数字长度为 8，可以跳过检查，因为不存在长度为 8 的素数
 * 暴力破解，时间复杂度 O(n)
 * */

bool isPrime(int x) {
    if (x < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int reversePalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x!= 0)) {
        return 0;
    }
    int ans = 1;
    while (x > 0) {
        ans = 10 * ans + (x % 10);
        x /= 10;
    }
    return x == ans || x == ans / 10;
}

int primePalindrome(int x) {
    while (true) {
        if (reversePalindrome(x) && isPrime(x)) {
            return x;
        }
        x++;
    }
}

/*
 * 方案二
 * */

int main()
{
    int N;
    while (cin >> N) {
        cout << primePalindrome(N) << endl;
    }
    return 0;
}

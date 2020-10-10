#include <bits/stdc++.h>

using namespace std;

/*
 * 方案一：将整数转换为字符串，判断其是否为一个回文串
 * 方案二：
 * 回文数，判断一个整数是不是回文
 * 1221
 * 1 == 1
 * 2 == 2
 * 1221 / 1000 -> 1 && 1221 % 10 -> 1 true
 * 方案三：取出整数后半段数字进行翻转
 * */

bool isPalindromeOne(int x) {
    if (x < 0) {
        return false;
    }
    // 相当于统计 x 有几位数
    int div = 1;
    while (x / div >= 10) {
        div *= 10;
    }
    while (x > 0) {
        // 拿到第一位
        int left = x / div;
        // 拿到最后一位
        int right = x % 10;
        if (left != right) {
            return false;
        }
        x = (x % div) / 10;
        // 由于依次少两位，所以除以 100
        div /= 100;
    }
    return true;
}

/*
 * 每次进行取余操作 （ %10），取出最低的数字：y = x % 10
 * 将最低的数字加到取出数的末尾：revertNum = revertNum * 10 + y
 * 每取一个最低位数字，x 都要自除以 10
 * 判断 x 是不是小于 revertNum ，当它小于的时候，说明数字已经对半或者过半了
 * 最后，判断奇偶数情况：如果是偶数的话，revertNum 和 x 相等；如果是奇数的话，最中间的数字就在revertNum 的最低位上，将它除以 10 以后应该和 x 相等。
 * */

bool isPalindromeTwo(int x) {
    // 整数末尾为 0 直接返回
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }
    int ans = 0;
    while (x > ans) {
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return x == ans || x == ans / 10;
}

int main()
{
    int x;
    while (cin >> x) {
        cout << isPalindromeOne(x) << endl;
    }
    return 0;
}

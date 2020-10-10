#include <bits/stdc++.h>

using namespace std;

/*
 * 输入一个正整数n,求n!(即阶乘)末尾有多少个0？ 比如: n = 10; n! = 3628800,所
 * 以答案为2
 * */

int main()
{
    int N;
    int count = 0;
    while (cin >> N) {
        while (N /= 5)
        {
            count += N;
        }
        cout << count << endl;
    }
    return 0;
}


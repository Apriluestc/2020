#include <bits/stdc++.h>

using namespace std;

/*
 *
 * 【最长公共子串】给出两个字符串，找到最长公共子串，并返回长度
 * dp[i][j] 表示以 A[i-1] B[j-1] 为结尾的最长公共子串的长度
 *
 * count 表示全局最长长度，至于为什么，我不清楚
 * */

int main()
{
    string A, B;
    while (cin >> A >> B) {
        int M = A.size();
        int N = B.size();
        vector<vector<int> > dp(M + 1, vector<int>(N + 1, 0));
        int count = 0;
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (A[i-1] == B[i-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    count = max(dp[i][j], count);
                } else {
                    // 与最长公共子序列不同的是，当 A[i-1] != B[j-1] 此时 dp[i][j] = 0;
                    // 而子序列问题 dp[i][j] = max(dp[i-1][j], dp[i][j-1])
                    dp[i][j] = 0;
                }
            }
        }
        cout << count << endl;
    }
    return 0;

    // 空间优化
}

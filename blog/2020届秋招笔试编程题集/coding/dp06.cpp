#include <bits/stdc++.h>

using namespace std;

/*
 * 【最长公共子序列】给出两个字符户，找出最长公共子序列，返回 dp 长度
 *
 * 最长公共子序列问题是在一组序列中找出最长公共子序列(可以不连续)
 * 
 * ABCD
 * EDCA
 *
 * 给定 A[] B[]
 *
 * 1
 *
 * dp A 或者 D 或者 C
 *
 * dp[i][j] 表示以字符串 A[i] 结尾，以 B[j] 结尾产生的最长子序列
 *
 * */

int main()
{
    string A, B;
    while (cin >> A >> B) {
        int M = A.size();
        int N = B.size();
        vector<vector<int> > dp(M + 1, vector<int>(N + 1, 0));
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (A[i-1] == B[i-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        cout << dp[M][N] << endl;
    }
    return 0;

/*
 * 空间优化方案
 * 操作方案：
 * 因为我们每次都会将新的结果覆盖到之前的一维数组之上，所以说，我们在进行计
 * 算当前的 dp[i] 的时候，必须提前将我们的 dp[i-1](dp[i] 的对角线的元素)记录下来（slave）
 * 我们最后要计算的就是这么几个情况：
 * 1.当前匹配：dp[i] = slave + 1;
 * 2.当前不匹配：dp[i-1]（刚计算完的）和 dp[i]取最大值即可
 * 所以说，我们这里的最核心的要点就是保存 slave 变量
 * */
   
    /*
    * // 空间优化
    * int M = A.size();
    * int N = B.size();
    * vector<int> dp(N + 1, 0);
    * int slave;
    * for (int i = 1; i <= M; i++) {
    *     slave = dp[0];
    *     for (int j = 1; j <= N; j++) {
    *         // 提取当前值
    *         int tmp = dp[j];
    *         if (A[i-1] == B[j-1]) {
    *             dp[j] = slave + 1;
    *         } else {
    *             dp[j] = max(dp[j-1], dp[j]);
    *         }
    *         // slave 记录
    *         slave = tmp;
    *     }
    * }
    * cout << dp[N] << endl;
    * */
}

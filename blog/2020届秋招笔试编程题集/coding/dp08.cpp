#include <bits/stdc++.h>

using namespace std;

/*
 * 【编辑距离】给出两个字符串 A，B，要求将 A 转换为 B 的最少操作次数
 *
 * 操作方法有：插入、删除、替换
 *
 * horse
 * ros
 * 
 * horse->rorse 替换 h 为 r
 * rorse->rose  删除 r
 * rose->ros    删除 e
 * 
 * intention
 * execytion
 *
 * intention->inention  删除 t
 * inention->enention   替换 i 为 e
 * enention->exention   替换 n 为 x
 * exention->exection   替换 n 为 c
 * exection->execution  插入 u
 *
 * dp[i][j] 表示 A[i] B[j] 的最小编辑距离
 * 要求 dp[i+1][j+1] 就先看 A[i+1] == B[j+1] ?
 * 如果相等说明这个字符不需要操作，只需取前面的最优解 dp[i][j]
 * 不等则 dp[i][j]、dp[i+1][j]、dp[i][j+1] 中取最优值
 * */

int main()
{
    string A, B;
    while (cin >> A >> B) {
        int M = A.size();
        int N = B.size();
        vector<vector<int> > dp(M + 1, vector<int>(N + 1, 0));
    }
    return 0;
}

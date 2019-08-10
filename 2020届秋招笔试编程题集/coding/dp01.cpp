#include <bits/stdc++.h>

using namespace std;

/*
 * 给定 N 种物品
 * 一个容量为 C 的背包
 * 物品 i 的重量或者体积是 W[i]
 * 价值是 V[i]
 *
 * 【有价值问题】问：从给定的 N 件物品中，如何选择装入背包的物品
 * 使得装入背包物品的总价值最大
 *  示例：
 * N = 6
 * C = 12
 * W[] = {4, 6, 2, 2, 5, 1};
 * V[] = {8, 10, 6, 3, 7, 2};
 *
 * 24
 *
 * dp[i][j] 表示放入第 i 件物品在背包容量是 j 的情况下产生的最佳价值
 * */

int main()
{
    
    // N 物品种类
    // C 背包容量
    int N, C;
    while (cin >> N >> C) {
        
        // W 对应第 i 种物品的重量或体积
        // V 对应第 i 种物品的价值
        vector<int> W(N + 1, 0);
        vector<int> V(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            cin >> W[i];
        }
        for (int i = 1; i <= N; i++) {
            cin >> V[i];
        }

        // dp[i][j] 表示放入前 i 种物品之后产生的最大价值
        vector<int> dp(C + 1, 0);
        for (int i = 1; i <= N; i++) {
            // 逆序
            for (int j = C; j >= W[i]; j--) {
                dp[j] = max(dp[j], dp[j-W[i]] + V[i]);
            }
        }
        cout << dp[C] << endl;
    }
    return 0;
}

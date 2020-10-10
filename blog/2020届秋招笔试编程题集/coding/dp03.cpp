#include <bits/stdc++.h>

using namespace std;

/*
 * 物品种类 N
 * 背包容量 C
 * 对应第 i 种物品的体积或者重量或者花费是 W[i]
 * 对应第 i 种物品的价值为 V[i]
 * 【完全背包】每种物品对应的数量是无限的，即每种物品可以无限件取
 * 求解将哪些物品放入背包可使得这些物品的总体积不超过背包容量且总价值最大
 * */

int main()
{
    // 物品种类数目 N
    // 背包容量 C
    int N, C;
    while (cin >> N >> C) {

        // W 对应第 i 件物品的重量或者体积
        // V 对应第 i 件物品的价值
        vector<int> W(N + 1, 0);
        vector<int> V(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            cin >> W[i];
        }
        for (int i = 1; i <= N; i++) {
            cin >> V[i];
        }
        vector<int> dp(C + 1, 0);
        for (int i = 1; i <= N; i++) {
            // 与 01 背包不同，这里为顺序，01 背包为逆序
            // 空间优化为一维数组
            for (int j = W[i]; j <= C; j++) {
                dp[j] = max(dp[j], dp[j-W[i]] + V[i]);
            }
        }
        cout << dp[C] << endl;
    }
    return 0;
}

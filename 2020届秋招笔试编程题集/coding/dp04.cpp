#include <bits/stdc++.h>

using namespace std;

/*
 * 物品种类 N
 * 背包容量 C
 * nums 对应第 i 种物品的最大数量
 * W 对应第 i 种物品的体积或者重量
 * V 对应第 i 种物品的价值
 * 【多重背包问题】*/

int main()
{
    int N, C;
    while (cin >> N >> C) {
        vector<int> W(N + 1, 0);
        vector<int> V(N + 1, 0);
        vector<int> nums(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            cin >> W[i];
        }
        for (int i = 1; i <= N; i++) {
            cin >> V[i];
        }
        for (int i = 1; i <= N; i++) {
            cin >> nums[i];
        }
        vector<int> dp(C + 1, 0);
        for (int i = 1; i <= N; i++) {
            // 把每种物品展开，调用 nums[i] 次 01 背包代码
            for (int k = 1; k <= nums[i]; k++) {
                // 正常的 01 背包代码，注意是逆序保证每种物品只取了一个
                for (int j = C; j > W[i]; j--) {
                    dp[j] = max(dp[j], dp[j-W[i]] + V[i]);
                }
            }
        }
        cout << dp[C] << endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    // N 物品种类
    // C 背包容量
    // W[i] 对应第 i 种物品的体积或者重量
    int N, C;
    while (cin >> N >> C) {
        vector<int> W(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            cin >> W[i];
        }
        vector<int> dp(C + 1, 1);
        for (int i = 1; i <= N; i++) {
            // 完全背包的总方案问题
            for (int j = W[i]; j <= C; j++) {
                dp[j] = dp[j] + dp[j-W[i]];
            }
        }
        cout << dp[C] << endl;
    }
    return 0;
}

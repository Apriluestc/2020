#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    while (cin >> N) {
        vector<int> nums(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            cin >> nums[i];
        }
        
        // 全局最优值
        int global = INT_MIN;
        
        // dp 数组，dp[i] 表示以 nums[i] 结尾产生的连续最大和
        vector<int> dp(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            
            // 要么是上一个状态产生的最大值加上当前值，要么是当前值
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            
            // 保存全局最优值
            global = max(global, dp[i]);
        }
        cout << global << endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

/*
 * 【LCS 问题】最长上升子序列
 * 给定一个无序数组，找到其中最长的上升子序列
 * */

int main()
{
    int N;
    while (cin >> N) {
        vector<int> nums(N, 0);
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
        }
        vector<int> dp(N, 1);
        int global;
        if (nums.size() == 0) {
            global = 0;
        } else {
            global = 1;
        }
        // dp[i] 表示以 nums[i] 结尾的最长上升子序列
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    global = max(global, dp[i]);
                }
            }
        }
        cout << global << endl;
    }
    
    return 0;
}

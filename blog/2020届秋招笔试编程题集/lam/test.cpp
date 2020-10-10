#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    while (cin >> N) {
        vector<int> nums(N + 1, 0);
        // 1, 2, 3, 5, 7, 9
        for (int i = 1; i <= N; i++) {
            cin >> nums[i];
        }
        vector<int> dp(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            dp[i] = max(dp[i], dp[i-1] + nums[i]);
        }
        cout << dp[N] << endl;
    }
    return 0;
}

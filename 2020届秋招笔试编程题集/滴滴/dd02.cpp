#include <bits/stdc++.h>

using namespace std;

long long dp[1024] = {1};

/*
 * 01 背包方案数问题
 * */

int main()
{
    int N, M;
    while (cin >> N >> M) {
        vector<int> A(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
        }
        for (int i = 1; i <= N; i++) {
            for (int j = M; j >= A[i]; j--) {
                dp[j] = dp[j] + dp[j-A[i]];
            }
        }
        cout << dp[M] << endl;
    }
    return 0;
}

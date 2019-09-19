#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    while (cin >> N) {
        int time = 0, max_sum = 0;;
        vector<pair<int, int>> v;
        for (int i = 0; i < N; i++) {
            int X, Y;
            cin >> X >> Y;
            v.push_back(make_pair(X, Y));
        }
        // 3
        // 1 1
        // 2 1
        // 3 1
        // 4 1
        for (int i = 0; i < N; i++) {
            max_sum += v[i].second;
        }
        max_sum = max_sum - v[N-1].second - (N - 1) + v[N-1].second;
        time = N + max_sum;
        cout << time << " " << max_sum << endl;
    }
    return 0;
}

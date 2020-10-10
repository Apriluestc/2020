#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    while (cin >> N) {
        vector<int> nums(N, 0);
        vector<int> res(N, 0);
        int count = 0;
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
            while (nums[i]) {
                if ((nums[i] & 1) == 1) {
                    res[i]++;
                }
                nums[i] >>= 1;
            }
        }
        for (int j = 0; j < N; j++) {
            if (res[j] != res[j+1]) {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}

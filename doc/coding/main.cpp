#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    int target;
    while (cin >> N) {
        vector<int> nums(N, 0);
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
        }
        cin >> target;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if ((target = nums[i]) > 0) break;
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[l] + nums[r] + target < 0) ++l;
                else if (nums[l] + nums[r] + target > 0) --r;
                else {
                    ans.push_back({target, nums[l], nums[r]});
                    ++l, --r;
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                    while (l < r && nums[r] == nums[r + 1]) --r;
                }
            }
        }
        cout << ans.size() << endl;
        // cout << s.threeSum(nums, target, count) << endl;;
    }
    return 0;
}

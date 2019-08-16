#include <bits/stdc++.h>

using namespace std;

/*
 * 三数之和
 *
 * 给定一个包含 N 个整数的 nums，判断 nums 中是否存在
 * 三个元素 a, b, c 使得 a + b + c = 0，找出所有序列
 *
 * 给定 nums = {-1, 0, 1, 2, -1, -4}
 *
 * [
 *      [-1, 0, 1]
 *      [-1, -1, 2]
 * ]
 * */

/*
 * 题解
 *
 * 一个新的周末，你再次去现在参加了一个，额，这次不是相亲会，是参加一个街篮比赛
 * ，赛前当然要组队啦，现在要想一个方法找到队友。组队还有一个要求，就是队伍的平
 * 均实力要符合要求，比如菜鸟抱两个大腿，或者有王者带两个弱鸡
 *
 * 当然，类似于两数之和，我们让每个数都相加，看会不会与我们的 target 相等
 *
 * */

class Solution {
public:
    vector<vector<int> > threeSumOne(vector<int>& nums, int target) {
        vector<vector<int> > res;
        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = i + 1; j < nums.size(); j++) {
                for (size_t k = j + 1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] + nums[k] == target) {
                        res.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        return vector<vector<int> > ();
    }

    /*
     * 受到两数之和的启发，在凑齐两人之后，我们可以找主持人登记第三个人，而不必在茫茫人海中找，这样时间复杂
     * 度为 n^2
     * */

    /*
     * 再优化
     *
     * 可以先对给定序列进行排序，时间复杂度 nlogn
     * 我后我们选择一个人做 C 位，既然是 C 位，那么我们就需要左右各有一个人
     *
     * 先选择队伍最左边和队伍最右边两个人加上 C 位，算一下总和，如果大于 target 说明
     * 实力强，那么就把右边的人 right-- 一下，重新计算实例值
     *
     * 如果某边选到紧挨着你时，结束
     * */
};

int main()
{
    return 0;
}

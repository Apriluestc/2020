#include <bits/stdc++.h>

using namespace std;

/*
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组
 * 中找出和为目标值的那 两个 整数，并返回他们的数组下标
 * */

/*
 * 题解
 *
 * 最简单的想法就是把每两个数都拿出来相加，看看结果是不是我们想要的值
 * 但是这样的时间复杂度为 n^2
 * */

class Solution {
public:
    vector<int> twoSumOne(vector<int>& nums, int target) {
        for (size_t i = 0; i < nums.size(); i++) {
            for (size_t j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return vector<int>{nums[i], nums[j]};
                }
            }
        }
        return vector<int>{};
    }

    /*
     * 比如这个周末你要参加线下相亲会，全场只有两个人才是真爱，于是我们每个人都要去
     * 找其他所有聊天，但是这样的时间复杂度为 n^2
     *
     * 这时候引入哈希表，其实就是一个登记册子，写上你的名字和你的要求
     * 如果每个人都去登记一下，然后大家依次报出自己的名字，主持人就能够识别它
     * 
     *
     * 两边哈希表
     * */

    vector<int> twoSumTwo(vector<int>& nums, int target) {
        // 注册表
        unordered_map<int, int> hash;

        // 开始登记
        for (size_t i = 0; i < nums.size(); i++) {
            hash[target - nums[i]] = nums[i];
        }

        // 每个人再次报数的时候，主持人看一下名单里面有没有他
        for (size_t j = 0; j < nums.size(); j++) {
            if (hash.count(nums[j])) {
                return vector<int>{nums[j], hash[nums[j]]};
            }
        }
        return vector<int>{};
    }

    /*
     * 再优化，一遍哈希表
     *
     * 在上述情况之下，就是每个人都来问一下主持人，自己要找的人是否来登记过
     * 如果有就返回，没有就登记
     * */

    vector<int> twoSumThree(vector<int>& nums, int target) {
        // 注册表
        unordered_map<int, int> hash;
        for (size_t i = 0; i < nums.size(); i++) {
            // 如果要找的人被登记，直接返回
            if (hash.count(nums[i])) {
                return vector<int>{nums[i], hash[nums[i]]};
            } else {
                // 否则登记
                hash[target - nums[i]] = nums[i];
            }
        }
        return vector<int>{};
    }
};

int main()
{
    return 0;
}

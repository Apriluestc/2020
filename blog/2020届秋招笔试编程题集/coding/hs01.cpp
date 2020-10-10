#include <bits/stdc++.h>

using namespace std;

/*
 * 【DFS、BFS 问题】
 * 给定一个数组，找出所有该数组的递增子序列
 *
 * [4, 6, 7, 7]
 *
 * [4, 6]
 * [4, 7]
 * [4, 6, 7]
 * [4, 6, 7, 7]
 * [6, 7]
 * [6, 7, 7]
 * [7, 7]
 * [4, 7, 7]
 * 
 *
 * 因为要查找所有有可能的序列，所以需要深度搜索或者广度搜索算法
 * 有一个注意的点就是如何处理重复问题
 * 我们可以使用 set 容器对元素进行唯一性处理
 * */

void DFS(set<vector<int> >& res, vector<int>& nums, vector<int>& tempRes, int lastNum, int beginIndex);

vector<vector<int> > findSubsequences(vector<int>& nums) {
    vector<int> tempRes;
    set<vector<int> > res;
    DFS(res, nums, tempRes, -100, 0);
    return vector<vector<int> >(res.begin(), res.end());
}

void DFS(set<vector<int> >& res, vector<int>& nums, vector<int>& tempRes, int lastNum, int beginIndex) {
    int numsSize = nums.size();

    // 搜索到了尾端
    if (beginIndex == numsSize) {

        // 判断这个结果是否符合要求
        if (tempRes.size() > 1) {
            // 插入到队列中
            res.insert(tempRes);
        }
    } else {
        // 跳过这个元素
        DFS(res, nums, tempRes, lastNum, beginIndex + 1);

        // 或者当这个元素符合放入条件(递增)
        if (lastNum <= nums[beginIndex]) {
            tempRes.push_back(nums[beginIndex]);
            DFS(res, nums, tempRes, nums[beginIndex], beginIndex + 1);
            tempRes.pop_back();
        }
    }
    return;
}

int main()
{
    int N;
    while (cin >> N) {
        vector<int> nums(N, 0);
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
        }
        vector<vector<int> > tmp = findSubsequences(nums);
        for (size_t i = 0; i < tmp[0].size(); i++) {
            for (size_t j = 0; j < tmp[0].size(); j++) {
                cout << tmp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

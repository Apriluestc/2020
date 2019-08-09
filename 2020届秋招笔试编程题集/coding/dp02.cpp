#include <bits/stdc++.h>

using namespace std;

/*
 * 给定 N 种物品
 * 一个容量为 C 的背包
 * 物品 i 的重量或者体积是 W[i]
 * 价值是 V[i]
 * 
 * 【无价值问题】问：从给定的 N 件物品中，如何选择若干件物品恰好能装入背包
 * 找出满足条件的所有解
 *  示例：
 * N = 6
 * C = 10
 * W[] = {1, 8, 4, 3, 5, 2};
 * 
 * [1, 4, 3, 2]
 * [1, 4, 5]
 * [8, 2]
 * [3, 5, 2]
 *
 * vector<vector<int> >;
 *
 * */


int main()
{
    int N, C;
    while (cin >> N >> C) {
        vector<int> W(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            cin >> W[i];
        }
    }
    return 0;
}

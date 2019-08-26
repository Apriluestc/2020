#include <bits/stdc++.h>

using namespace std;

/*
 * 某餐馆有n张桌子，每张桌子有一个参数：a 可容纳的最大人数； 有 m 批
 * 客人，每批客人有两个参数:b人数，c预计消费金额。 在不允许拼桌的
 * 情况下，请实现一个算法选择其中一部分客人，使得总预计消费金额最大
 * */

int main()
{
    // N 张桌子
    // M 批客人
    int N, M;
    while (cin >> N >> M) {
        // table 对应每张左子的容量
        vector<int> table(N, 0);
        for (int i = 0; i < N; i++) {
            cin >> table[i];
        }
        sort(table.begin(), table.end());
        reverse(table.begin(), table.end());
        vector<pair<int, int>> guest(M, make_pair(0, 0));
        for (int i = 0; i < M; i++) {
            cin >> guest[i].second >> guest[i].first;
        }
        sort(guest.begin(), guest.end());
        reverse(guest.begin(), guest.end());
        long long res = 0;
        for (size_t i = 0; i < guest.size(); i++) {
            if (table.size() == 0) {
                break;
            }
            int money = guest[i].first;
            int people = guest[i].second;
            if (table[0] < people) {
                continue;
            }
            size_t j = 0;
            while (j < table.size() && table[j] >= people) {
                j++;
            }
            res +=  money;
            table.erase(table.begin() + j - 1);
        }
        cout << res << endl;
    }
    return 0;
}

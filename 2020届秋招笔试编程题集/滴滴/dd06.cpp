#include <bits/stdc++.h>

using namespace std;

/*
 * 迷宫可以看成是有向图，向上的边权值为 3，向下的边权值为 0，等等
 * 不相邻的边或者一端有障碍物的边，权值是无穷大，本质上就是求这个有向
 * 图从 (0,0) 到 (0,m-1) 的最短路径
 * 可利用 Dijkstra 算法
 * */

int main()
{
    // N 行
    // M 列
    // P 体力值
    int N, M, P;
    while (cin >> N >> M >> P) {
        // board 迷宫矩阵
        vector<vector<int>> board(N, vector<int>(M, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> board[i][j];
            }
        }
        // 构建有向图
       vector<vector<int>> graph(N * M, vector<int>(N * M, INT_MAX));
       for (int i = 0; i < N; i++) {
           for (int j = 0; j < M; j++) {
               if (i > 0 && board[i-1][j]) {
                   graph[i*M+j][(i-1)*M+j] = 3;
               }
               if (i < N - 1 && board[i+1][j]) {
                   graph[i*M+j][(i+1)*M+j] = 0;
               }
               if (j > 0 && board[i][j-1]) {
                   graph[i*M+j][i*M+j-1] = 1;
               }
               if (j < M - 1 && board[i][j+1]) {
                   graph[i*M+j][i*M+j+1] = 1;
               }
           }
       }
       // Dijkstra 算法求解最短路
       vector<int> pre(N * M, 0);
       vector<int> mindist(N * M, 0);
       vector<bool> found(N * M, false);
       for (int i = 0; i < N * M; i++) {
           mindist[i] = graph[0][i];
       }
       found[0] = true;
       for (int i = 1; i < N * M; i++) {
           int near;
           int min = INT_MAX;
           for (int j = 0; j< N * M; j++) {
               if (!found[j] && mindist[j] < min) {
                   min = mindist[j];
                   near = j;
               }
           }
           if (min == INT_MAX) {
               break;
           }
           found[near] = true;
           for (int k = 0; k < N * M; k++) {
               if (!found[k] && min != INT_MAX && graph[near][k] != INT_MAX && (min + graph[near][k] < mindist[k])) {
                   pre[k] = near;
                   mindist[k] = min + graph[near][k];
               }
           }
       }
       if (mindist[M-1] > P) {
           cout << "Can not escape!" << endl;
       } else {
           stack<pair<int, int>> path;
           for (int i = M - 1; i != 0; i = pre[i]) {
               path.push({i / M, i % M});
           }
           cout << "[0,0]";
           while (!path.empty()) {
               const auto& p = path.top();
               cout << ",[" << p.first << ',' << p.second << ']';
               path.pop();
           }
           cout << endl;
       }
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <vector>

using namespace std;

struct Graph {
    vector<char> vexs;
    vector<vector<int> > arcs;
    int v, e;
};

int locateVex(Graph& g, int v) {
    int res = 0;
    for (int i  = 0; i < g.v; i++) {
        if (g.vexs[i] == v) {
            res = i;
            break;
        }
    }
    return res;
}

void createGraph(Graph& g) {
    cout << "请输入图的顶点和边" << endl;
    cin >> g.v >> g.e;
    cout << "请输入图的顶点" << endl;
    for (int i = 0; i < g.v; i++) {
        cin >> g.vexs[i];
    }
    cout << "请输入两顶点之间边的权值" << endl;
    for (int k = 0; k < g.e; k++) {
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        g.arcs[locateVex(g, v1)][locateVex(g, v2)] = weight;
    }
    for (int i = 0; i < g.v; i++) {
        for (int j = 0; j < g.v; j++) {
            g.arcs[i][j] = 0;
        }
    }
}

int main()
{
    Graph g;
    createGraph(g);
    return 0;
}

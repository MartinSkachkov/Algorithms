#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> color;
// 1 -blue
// 0 -red
// -1 -not colored

unsigned n, m;

void dfs(int s, int col, bool &ans) {
    color[s] = col;
    visited[s] = true;

    for (int v : graph[s]) {
        if (visited[v] == false) {
            dfs(v, !col, ans);
        }

        if (color[v] == color[s]) {
            ans = false;
        }
    }
}

bool isBipartite() {
    bool ans = true;
    for (size_t i = 1; i <= n; i++) {
        if (visited[i] == false) {
            dfs(i, 0, ans);
        }
    }

    return ans;
}

int main() {
    cin >> n >> m;

    graph.resize(n + 1);
    visited.resize(n + 1, false);
    color.resize(n, -1);

    unsigned u, v;
    for (size_t i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << isBipartite();

    return 0;
}
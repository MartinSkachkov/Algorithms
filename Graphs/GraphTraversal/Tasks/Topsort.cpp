#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> ordering;
unsigned n, m, pos;

void dfs(int s) {
    visited[s] = true;

    for (int v : graph[s]) {
        if (visited[v] == false) {
            dfs(v);
        }
    }

    ordering[pos] = s;
    pos--;
}

void toposort() {
    for (size_t i = 1; i <= n; i++) {
        if (visited[i] == false) {
            dfs(i);
        }
    }
}

int main() {
    cin >> n >> m;
    pos = n;

    graph.resize(n + 1);
    visited.resize(n + 1, false);
    ordering.resize(n + 1);

    unsigned u, v;
    for (size_t i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
    }

    toposort();
    for (size_t i = 1; i <= n; i++) {
        cout << ordering[i];
    }

    return 0;
}

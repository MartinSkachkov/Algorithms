#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
unsigned n, m;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (visited[v] == false) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int components() {
    int components = 0;

    for (size_t i = 1; i <= n; i++) {
        if (visited[i] == false) {
            bfs(i);
            components++;
        }
    }

    return components;
}

int main() {
    cin >> n >> m;

    graph.resize(n + 1);
    visited.resize(n + 1, false);

    unsigned u, v;
    for (size_t i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << components();

    return 0;
}
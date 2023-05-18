#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> dist;
unsigned n, m;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    dist[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (visited[v] == false) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

void update() {
    for (size_t i = 1; i <= n; i++) {
        if (visited[i] == false) {
            bfs(i);
        }
    }
}

int main() {
    cin >> n >> m;

    graph.resize(n + 1);
    visited.resize(n + 1);
    dist.resize(n + 1, INT_MIN);

    unsigned u, v;
    for (size_t i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    update();

    for (size_t i = 1; i <= n; i++) {
        cout << dist[i];
    }

    return 0;
}
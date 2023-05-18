#include <iostream>
#include <queue>
#include <vector>
using namespace std;

unsigned n, m;
vector<bool> visited;

int midStarGraph(const vector<vector<int>>& graph, int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    int mid;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (visited[v] == false) {
                visited[v] = true;
                mid = v;
            }
        }

        for (size_t i = 1; i <= n; i++) {
            if (visited[i] == false) {
                return mid;
            }
        }

        return u;
    }
}

int main() {
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    visited.resize(n + 1, false);
    unsigned u, v;

    for (size_t i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int s;
    cin >> s;
    cout << midStarGraph(graph, s);

    return 0;
}
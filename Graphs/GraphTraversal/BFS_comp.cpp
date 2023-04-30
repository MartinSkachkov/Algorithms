#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
unsigned n, m;

void BFS(const vector<vector<int>> &graph, int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

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

int components(const vector<vector<int>> &graph, int n) {
    int count = 0;

    for (size_t i = 1; i <= n; i++) {
        if (visited[i] == false) {
            BFS(graph, i);
            count++;
        }
    }

    return count;
}

int main() {
    cout << "# of vertecies: ";
    cin >> n;

    cout << "# of edges: ";
    cin >> m;

    graph.resize(n + 1);
    visited.resize(n + 1, false);
    int u, v;

    for (size_t i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << components(graph, n);

    return 0;
}
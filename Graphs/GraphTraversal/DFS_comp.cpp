#include <iostream>
#include <vector>
using namespace std;

unsigned n, m;
vector<bool> visited;

void DFS(const vector<vector<int>> &graph, int s) {
    if (visited[s] == true) {
        return;
    }

    visited[s] = true;

    for (int v : graph[s]) {
        DFS(graph, v);
    }
}

int components(const vector<vector<int>> &graph) {
    int count = 0;

    for (size_t i = 1; i <= n; i++) {
        if (visited[i] == false) {
            DFS(graph, i);
            count++;
        }
    }

    return count;
}

int main() {
    cout << "# of vertices: ";
    cin >> n;

    cout << "# of edges: ";
    cin >> m;

    vector<vector<int>> graph(n + 1);
    visited.resize(n + 1, false);
    unsigned u, v;

    for (size_t i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << components(graph);

    return 0;
}
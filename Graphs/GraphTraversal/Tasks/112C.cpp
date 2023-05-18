#include <iostream>
#include <queue>
#include <vector>
using namespace std;

unsigned n, m, q;
vector<vector<int>> graph;
vector<int> component;
vector<bool> visited;

void bfs(int s, int compMark) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    component[s] = compMark;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (visited[v] == false) {
                visited[v] = true;
                component[v] = compMark;
                q.push(v);
            }
        }
    }
}

void BFS() {
    int componentMark = 1;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == false) {
            bfs(i, componentMark);
            componentMark++;
        }
    }
}

int main() {
    cin >> n >> m;

    graph.resize(n + 1);
    component.resize(n + 1, 0);
    visited.resize(n + 1, false);

    unsigned from, to;
    for (size_t i = 0; i < m; i++) {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    BFS(); // will fill the components array

    cin >> q;
    vector<int> solution;
    for (size_t i = 0; i < q; i++) {
        cin >> from >> to;
        if (component[from] == component[to]) {
            solution.push_back(1);
        } else {
            solution.push_back(0);
        }
    }

    for (size_t i = 0; i < solution.size(); i++) {
        cout << solution[i];
    }

    return 0;
}
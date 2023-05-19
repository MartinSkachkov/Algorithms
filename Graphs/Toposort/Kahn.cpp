#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> in_degree;
vector<int> ordering;
unsigned n, m;

void Kahn() {
    ordering.resize(n + 1);
    in_degree.resize(n + 1, 0);

    // 1. get all vertices' indegrees
    for (size_t u = 1; u <= n; u++) {
        for (int v : graph[u]) {
            in_degree[v]++;
        }
    }

    // 2. push the 0 ones to the queue
    queue<int> q;
    for (size_t u = 1; u <= n; u++) {
        if (in_degree[u] == 0) {
            q.push(u);
        }
    }

    int index = 0;
    // 3. update the ordering, in_degree, queue
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ordering[index++] = u;

        for (int v : graph[u]) {
            in_degree[v]--;

            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (index != n) {
        cout << "contains a cycle!\n";
        return;
    }
}

int main() {
    cin >> n >> m;

    graph.resize(n + 1);

    unsigned from, to;
    for (size_t i = 0; i < m; i++) {
        cin >> from >> to;
        graph[from].push_back(to);
    }

    Kahn();

    for (size_t i = 0; i < n; i++) {
        cout << ordering[i] << ' ';
    }

    return 0;
}
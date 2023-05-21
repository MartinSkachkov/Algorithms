#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<vector<pair<int, int>>> graph;
vector<bool> visited;
vector<pair<int, int>> mstEdges;
unsigned n, m;
int mstCost = 0;

void addEdges(int s) {
    visited[s] = true;

    for (pair<int, int> v : graph[s]) {
        if (visited[v.first] == false) {
            pq.push({v.second, v.first});
        }
    }
}

void Prim(int s) {
    int m = n - 1; // num of edges in the mst
    int edgeCount = 0;

    addEdges(s);

    while (!pq.empty() && edgeCount != m) {
        pair<int, int> u = pq.top();
        pq.pop();

        if (visited[u.second] == true) {
            continue;
        }

        int weight = u.first;
        int v = u.second;

        mstEdges[++edgeCount] = {v, weight};
        mstCost += u.first;

        addEdges(u.second);
    }

    if (edgeCount != m) {
        cout << "No mst exists!\n";
        return;
    }

    return;
}

int main() {
    cin >> n >> m;

    graph.resize(n + 1);
    int from, to, w;
    for (size_t i = 0; i < m; i++) {
        cin >> from >> to >> w;
        graph[from].push_back({to, w});
        graph[to].push_back({from, w});
    }

    visited.resize(n + 1, false);
    mstEdges.resize(n + 1);

    Prim(1);

    cout << "Mst cost: " << mstCost;
    for (size_t i = 1; i <= n; i++) {
        cout << "from: " << i << " to: " << mstEdges[i].first << " cost: " << mstEdges[i].second << '\n';
    }

    return 0;
}
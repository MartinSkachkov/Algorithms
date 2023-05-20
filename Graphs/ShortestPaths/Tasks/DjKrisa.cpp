#include <iostream>
#include <queue>
#include <vector>
using namespace std;

unsigned n, m, k;
vector<vector<vector<int>>> graph;
vector<bool> visited;
vector<int> dist;

int dijkstra(int s, int e, int price_constraint) {
    dist[s] = 0;
    priority_queue<vector<int, int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({s, 0, 0});

    while (!pq.empty()) {
        vector<int> u = pq.top();
        pq.pop();
        visited[u[0]] = true;

        for (vector<int> v : graph[u[0]]) {
            if (visited[v[0]] == false && v[1] <= price_constraint && dist[u[0]] + v[2] < dist[v[0]]) { // the price constraint is IMPORTANT here
                dist[v[0]] = dist[u[0]] + v[2];
                pq.push({v[0], v[1], dist[v[0]]});
            }
        }
    }

    return dist[e];
}

int main() {
    cin >> n >> m >> k;

    graph.resize(n + 1);
    visited.resize(n + 1, false);
    dist.resize(n + 1, INT_MAX);

    int from, to, price, time;
    for (size_t i = 0; i < m; i++) {
        cin >> from >> to >> price >> time;
        graph[from].push_back({to, price, time});
    }

    int l = 0, r = 100, mid, opt = -1;

    while (l <= r) {
        mid = (l + r) / 2;

        fill(dist.begin(), dist.end(), INT_MAX);
        fill(visited.begin(), visited.end(), false);

        if (dijkstra(1, n, mid) <= k) {
            opt = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << opt;

    return 0;
}
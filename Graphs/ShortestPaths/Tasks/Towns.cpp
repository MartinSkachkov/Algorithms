#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int crossNum, s, e;
vector<vector<pair<int, int>>> graph;
vector<bool> visited;
vector<int> dist;

void dijkstra(int s) {
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({s, 0});

    while (!pq.empty()) {
        pair<int, int> u = pq.top();
        pq.pop();
        visited[u.first] = true;

        if (dist[u.first] < u.second) {
            continue;
        }

        for (pair<int, int> v : graph[u.first]) {
            if (visited[v.first] == false && dist[u.first] + v.second < dist[v.first]) {
                dist[v.first] = dist[u.first] + v.second;
                pq.push({v.first, dist[v.first]});
            }
        }
    }
}

int main() {
    cin >> crossNum >> s >> e;

    graph.resize(crossNum + 1);
    visited.resize(crossNum + 1, false);
    dist.resize(crossNum + 1, INT_MAX);

    unsigned from, to;
    while (cin >> from >> to) {
        graph[from].push_back({to, 0}); // we don't care about the legal ones so they will be zero weight
        graph[to].push_back({from, 1}); // this is how we will count the illegal moves
    }

    dijkstra(s);

    if (dist[e] == INT_MAX) {
        cout << 'X';
    } else {
        cout << dist[e];
    }

    return 0;
}
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<bool> visited;
vector<int> dist;
vector<int> places;
unsigned n, m, k, q;

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
    cin >> n >> m;

    graph.resize(n);

    unsigned x, y, t;
    for (size_t i = 0; i < m; i++) {
        cin >> x >> y >> t;
        graph[x].push_back({y, t});
        graph[y].push_back({x, t});
    }

    cin >> k;
    unsigned impPlace;
    for (size_t i = 0; i < k; i++) {
        cin >> impPlace;
        places.push_back(impPlace);
    }

    visited.resize(n);
    dist.resize(n);

    vector<int> res;
    cin >> q;
    unsigned hotel;
    for (size_t i = 0; i < q; i++) {
        cin >> hotel;
        fill(visited.begin(), visited.end(), false);
        fill(dist.begin(), dist.end(), INT_MAX);

        dijkstra(hotel);

        int min = INT_MAX;
        for (size_t j = 0; j < places.size(); j++) {
            if (dist[places[j]] < min) {
                min = dist[places[j]];
            }
        }
        res.push_back(min);
    }

    for (int v : res) {
        cout << v << '\n';
    }
    return 0;
}

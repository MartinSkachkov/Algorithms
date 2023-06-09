#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#define INF INT_MAX
using namespace std;

unsigned n, m;
vector<int> dist;
vector<string> par;

void print_dist() {
    for (size_t i = 1; i <= n; i++) {
        cout << "shortest dist to " << i << " is: " << dist[i] << '\n';
    }
    cout << '\n';
}

void print_par() {
    for (size_t i = 1; i <= n; i++) {
        cout << "the parent of vertex " << i << " is: " << par[i] << '\n';
    }
    cout << '\n';
}

void print_path(int from, int to) {
    vector<int> path;
    path.push_back(to);

    while (from != to) {
        path.push_back(stoi(par[to]));
        to = stoi(par[to]);
    }

    reverse(path.begin(), path.end());

    for (int v : path) {
        cout << v << ' ';
    }
    cout << '\n';
}

void Dijkstra(const vector<vector<pair<int, int>>> &graph, int s) {
    dist[s] = 0;
    vector<bool> visited(n + 1, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({s, 0});

    while (!pq.empty()) {
        pair<int, int> u = pq.top();
        pq.pop();
        visited[u.first] = true;

        if (dist[u.first] < u.second)
            continue;                                                                    // if the distance in the array is better than the dist in the priority queue just continue, nothing to change
        for (pair<int, int> v : graph[u.first]) {                                        // for each adjacent vertex v of u
            if (visited[v.first] == false && dist[u.first] + v.second < dist[v.first]) { // if v is not visited and the dist from u to v is better than the one saved in the array for v
                dist[v.first] = dist[u.first] + v.second;                                // update it to the shorter one
                par[v.first] = to_string(u.first);                                       // save the parent of v to be u
                pq.push({v.first, dist[v.first]});                                       // go with the next smallest one
            }
        }
    }
}

void reset() {
    dist.clear();
    dist.resize(n + 1, INF);
    par.clear();
    par.resize(n + 1, "nil");
}

int main() {
    cout << "# of vertices: ";
    cin >> n;

    cout << "# of edges: ";
    cin >> m;

    vector<vector<pair<int, int>>> graph(n + 1);
    dist.resize(n + 1, INF);
    par.resize(n + 1, "nil");
    unsigned u, v, w;

    for (size_t i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    unsigned q;
    cin >> q;
    for (size_t i = 0; i < q; i++) {
        cout << "strat vertex: ";
        unsigned s;
        cin >> s;

        cout << "end vertex: ";
        unsigned e;
        cin >> e;

        reset();
        Dijkstra(graph, s);

        if (dist[e] == INF) {
            cout << -1;
        } else {
            cout << dist[e] << '\n';
        }
    }

    return 0;
}
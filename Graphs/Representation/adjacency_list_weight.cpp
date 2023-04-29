#include <iostream>
#include <vector>
using namespace std;

void print_neighbours(const vector<vector<pair<int, int>>> &graph) {
    for (size_t u = 0; u < graph.size(); u++) {
        if (!graph[u].empty()) {
            cout << "neightbours of vertex " << u << " : ";
            for (pair<int, int> p : graph[u]) {
                cout << '{' << p.first << ", " << p.second << '}';
            }

            cout << '\n';
        }
    }
}

int main() {
    unsigned n, m;
    cout << "# of vertices: ";
    cin >> n;

    cout << "# of edges: ";
    cin >> m;

    cout << "---Create Graph---\n";
    vector<vector<pair<int, int>>> graph(n + 1);
    int u, v, w;

    // directed wighted graph
    for (size_t i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    print_neighbours(graph);

    // for undirected
    // for (size_t i = 0; i < m; i++) {
    //     cin >> u >> v >> w;
    //     graph[u].push_back({v, w});
    //     graph[v].push_back({u, w});
    // }
    return 0;
}
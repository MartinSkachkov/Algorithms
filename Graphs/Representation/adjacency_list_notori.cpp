#include <iostream>
#include <vector>
using namespace std;

void print_neighbours(const vector<vector<int>> &graph) {
    for (size_t u = 0; u < graph.size(); u++) {
        if (!graph[u].empty()) {
            cout << "neightbours of vertex " << u << " : ";
            for (int v : graph[u]) {
                cout << v << ' ';
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
    vector<vector<int>> graph(n + 1);
    int u, v;

    for (size_t i = 0; i < m; i++) {
        cin >> u >> v; // between which two vertice an edge will exist
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    print_neighbours(graph);

    return 0;
}
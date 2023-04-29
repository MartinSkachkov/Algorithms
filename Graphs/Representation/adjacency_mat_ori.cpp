#include <iostream>
#include <vector>
using namespace std;

void print_neighbours_u(const vector<vector<bool>> &graph, int u) {
    cout << "vertex " << u << " has neighbours: ";
    for (size_t v = 0; v < graph.size(); v++) {
        if (graph[u][v] != 0) {
            cout << v << ' ';
        }
    }
}

void print_neighbours(const vector<vector<bool>> &graph) {
    for (size_t u = 0; u < graph.size(); u++) {
        cout << "vertex " << u << " has neighbours: ";
        for (size_t v = 0; v < graph.size(); v++) {
            if (graph[u][v] != 0) {
                cout << v << ' ';
            }
        }

        cout << '\n';
    }
}

int main() {
    unsigned n, m;
    cout << "# of vertices: ";
    cin >> n;

    cout << "# of edges: ";
    cin >> m;

    cout << "---Create Graph---\n";
    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));
    int u, v;

    for (size_t i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u][v] = 1;
    }

    cout << "u: ";
    cin >> u;
    print_neighbours(graph);

    return 0;
}
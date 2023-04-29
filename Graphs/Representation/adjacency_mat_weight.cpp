#include <iostream>
#include <vector>
using namespace std;

void print_neighbours_u(const vector<vector<int>> &graph, int u) {
    cout << "vertex " << u << " has neighbours: ";
    for (size_t v = 0; v < graph.size(); v++) {
        if (graph[u][v] != 0) {
            cout << v << ' ';
        }
    }
}

void print_neighbours(const vector<vector<int>> &graph) {
    for (size_t u = 0; u < graph.size(); u++) {
        cout << "vertex " << u << " has neighbours: ";
        for (size_t v = 0; v < graph.size(); v++) {
            if (graph[u][v] != 0) {
                cout << '{' << v << ", " << graph[u][v] << '}';
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
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    int u, v, w;

    // directed wighted graph
    for (size_t i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    cout << "u: ";
    cin >> u;
    print_neighbours(graph);

    // undirected weighted graph
    // for (size_t i = 0; i < m; i++) {
    //     cin >> u >> v >> w;
    //     graph[u][v] = w;
    //     graph[v][u] = w;
    // }

    return 0;
}
#include <iostream>
#include <queue>
using namespace std;
#define MAX 104

unsigned n, m, k;
vector<vector<int>> graph(MAX, vector<int>(MAX));
vector<bool> visited;

int coor_to_int(int x, int y) {
    return m * x + y;
}

void dfs(int s) {
    if (visited[s] == true) {
        return;
    }

    visited[s] = true;

    for (int v : graph[s]) {
        dfs(v);
    }
}

int components(const vector<vector<int>> &board) {
    int count = 0;

    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++) {
            if (!board[i][j] && visited[coor_to_int(i, j)] == false) {
                dfs(coor_to_int(i, j));
                count++;
            }
        }
    }

    return count;
}

// we build a directed graph
void build_graph(const vector<vector<int>> &board) {
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++) {
            if (!board[i][j]) {
                if (i + 1 <= n) {
                    graph[coor_to_int(i, j)].push_back(coor_to_int(i + 1, j));
                }

                if (j + 1 <= m) {
                    graph[coor_to_int(i, j)].push_back(coor_to_int(i, j + 1));
                }

                if (i - 1 >= 1) {
                    graph[coor_to_int(i, j)].push_back(coor_to_int(i - 1, j));
                }

                if (j - 1 >= 1) {
                    graph[coor_to_int(i, j)].push_back(coor_to_int(i, j - 1));
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;

    vector<vector<int>> board(MAX, vector<int>(MAX, 0));
    visited.resize(MAX * MAX);

    cin >> k;
    unsigned x, y;
    for (size_t i = 0; i < k; i++) {
        cin >> x >> y;
        board[x][y] = 1;
    }

    build_graph(board);

    cout << components(board);

    return 0;
}
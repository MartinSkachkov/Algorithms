#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<string> grid(1000);
vector<vector<int>> adj(1000);
vector<vector<int>> dist(1000);

vector<pair<int, int>> deltas = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
unsigned n;

bool isInside(int x, int y) {
    return x < n && y < n && x >= 0 && y >= 0;
}

int bfs() {
    queue<pair<int, int>> q;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (grid[i][j] == '0') {
                q.push({i, j});
                dist[i][j] = 0;
            } else {
                dist[i][j] = -1;
            }
        }
    }

    int maxDist = -1;
    while (!q.empty()) {
        pair<int, int> pos = q.front();
        q.pop();

        maxDist = dist[pos.first][pos.second];

        for (pair<int, int> delta : deltas) {
            pair<int, int> newPos = {pos.first + delta.first, pos.second + delta.second};

            if (isInside(newPos.first, newPos.second)) {
                adj[newPos.first][newPos.second]++;

                if (adj[newPos.first][newPos.second] >= 2 && dist[newPos.first][newPos.second] == -1) {
                    q.emplace(newPos.first, newPos.second);
                    dist[newPos.first][newPos.second] = dist[pos.first][pos.second] + 1;
                }
            }
        }
    }

    return maxDist;
}

int main() {
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        cin >> grid[i];
    }

    cout << bfs();
    return 0;
}
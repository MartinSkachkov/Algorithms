#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

vector<int> dirX = {2, 2, -2, -2, 1, 1, -1, -1};
vector<int> dirY = {1, -1, 1, -1, -2, 2, -2, 2};

vector<vector<int>> board;
int n, m, k;

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n && board[x][y] >= 0;
}

int main() {
    cin >> n >> m >> k;

    board.resize(n, vector<int>(n, 0));
    int hx, hy; // holes
    for (size_t i = 0; i < m; i++) {
        cin >> hx >> hy;
        board[hx][hy] = -1;
    }

    int kx, ky; // knights
    for (size_t i = 0; i < k; i++) {
        cin >> kx >> ky;
        board[kx][ky] = 1;
    }

    int px, py; // princess
    cin >> px >> py;

    queue<pair<int, int>> q;
    q.push({px, py});
    board[px][py] = -1; // mark it as hole

    int cntK = 0, currDist = 0, resDist = 0, rem = 1; // rem will tell us how many elements are left in the queue

    while (!q.empty()) {
        pair<int, int> cord = q.front();
        q.pop();
        rem--;

        int currX = cord.first, currY = cord.second;

        for (size_t i = 0; i < 8; i++) {
            int newX = currX + dirX[i], newY = currY + dirY[i];

            if (valid(newX, newY)) {
                if (board[newX][newY]) {
                    cntK++;
                    resDist = currDist + 1;
                }

                board[newX][newY] = -1;
                q.push({newX, newY});
            }
        }

        if (rem == 0) {
            rem = q.size();
            currDist++;
        }
    }

    cout << cntK << ' ' << resDist;

    return 0;
}
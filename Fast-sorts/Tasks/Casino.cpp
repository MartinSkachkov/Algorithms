#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binSearchIdx(const vector<int>& tokens, int n) {

    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (tokens[mid] < 0) low = mid + 1;
        else if (tokens[mid] > 0) high = mid - 1;
        else return mid;
    }
}

int calcPositiveTokens(const vector<int>& tokens, int n) {
    int maxSum = 0;
    int curr = n - 1, next = n - 2, zeroId = binSearchIdx(tokens, n);

    while (curr > zeroId && next > zeroId) {
        if (tokens[curr] > 0 && tokens[next] > 0) {
            maxSum += tokens[curr] * tokens[next];
            curr -= 2; next -= 2;
            continue;
        }

        if (tokens[curr] == 0 || tokens[next] == 0) {
            if (tokens[curr] * tokens[next] >= tokens[curr] + tokens[next]) {
                maxSum += tokens[curr] * tokens[next];
                curr -= 2; next -= 2;
            }
            else {
                maxSum += tokens[curr] + tokens[next];
                curr -= 2; next -= 2;
            }
            continue;
        }

        if (tokens[curr] < 0 && tokens[next] < 0) {
            maxSum += tokens[curr] * tokens[next];
            curr -= 2; next -= 2;
            continue;
        }
    }

    if (curr == zeroId + 1) maxSum += tokens[curr];

    return maxSum;
}

int calcNonPositive(const vector<int>& tokens, int n) {
    int maxSum = 0;
    int zeroId = binSearchIdx(tokens, n);
    int curr = zeroId, next = zeroId - 1;

    while (curr >= 0 && next >= 0) {
        if (tokens[curr] > 0 && tokens[next] > 0) {
            maxSum += tokens[curr] * tokens[next];
            curr -= 2; next -= 2;
            continue;
        }

        if (tokens[curr] == 0 || tokens[next] == 0) {
            if (tokens[curr] * tokens[next] >= tokens[curr] + tokens[next]) {
                maxSum += tokens[curr] * tokens[next];
                curr -= 2; next -= 2;
            }
            else {
                maxSum += tokens[curr] + tokens[next];
                curr -= 2; next -= 2;
            }
            continue;
        }

        if (tokens[curr] < 0 && tokens[next] < 0) {
            maxSum += tokens[curr] * tokens[next];
            curr -= 2; next -= 2;
            continue;
        }
    }

    if (curr == 0) maxSum += tokens[curr];

    return maxSum;
}

int main() {

    int n;
    cin >> n;

    vector<int> tokens(n);

    for (int i = 0; i < n; i++) {
        cin >> tokens[i];
    }

    sort(tokens.begin(), tokens.end());

    cout << calcPositiveTokens(tokens, n) + calcNonPositive(tokens, n);

    return 0;
}

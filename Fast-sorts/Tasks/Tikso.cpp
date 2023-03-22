#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n, m, k; // n - брой скъсани сегменти, m - дължина на лентата, k - брой парчета тиксо
    cin >> n >> m >> k;

    vector<int> tornSeg(n);
    for (int i = 0 ; i < n; i++){
        cin >> tornSeg[i];
    }

    vector<int> gaps;
    for (int i = 0 ; i+1 < n; i++){
        gaps.push_back(tornSeg[i+1] - tornSeg[i] - 1);
    }

    sort(gaps.begin(),gaps.end(), greater <int> ());

    int ans = tornSeg[n-1] - tornSeg[0] + 1;
    for (int i = 0; i < k-1; i++){
        ans -= gaps[i];
    }

    cout << ans;

    return 0;
}

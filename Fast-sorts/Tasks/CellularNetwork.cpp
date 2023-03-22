#include <iostream>
#include <vector>
using namespace std;

void initialize(const int& lim, vector<int>& v){
    for (int i = 0; i < lim; i++){
        cin >> v[i];
    }
}

int main(){

    int n, m, r;
    cin >> n >> m;

    vector<int> home(n);
    initialize(n, home);
    vector<int> tower(m);
    initialize(m, tower);

    int maxR = 0;
    int tidx = 0;

    for (int i = 0; i < n; i++){
        //find the closest tower to the current home from the left side
        while(tidx + 1 < m && tower[tidx + 1] <= home[i]){
            tidx++;
        }

        r = abs(tower[tidx] - home[i]); //find the distance from the left side of the home to the tower
        if(tidx + 1 < m){
            r = min(r, abs(home[i] - tower[tidx+1])); //find the distance from the home to the right tower
        }
        maxR = max(maxR, r);
    }

    cout << maxR;

    return 0;
}

#include <iostream>
using namespace std;

const int MAX = 100;
int arr[MAX + 5];

int main(){

int n;
cout << "n: ";
cin >> n;

// inserting
for (int i = 0; i < n; i++){
    cin >> arr[i];
}

// sorting - O(n^2)
int currMinId;

for (int i = 0; i < n - 1; i++){        // -> O(n)
    currMinId = i;

    for (int j = i + 1; j < n; j++){    // -> O(n)
        if(arr[currMinId] > arr[j])
            currMinId = j;
    }
    swap(arr[i], arr[currMinId]);
}

// printing
for (int i = 0; i < n; i++){
    cout << arr[i] << ' ';
}

return 0;
}

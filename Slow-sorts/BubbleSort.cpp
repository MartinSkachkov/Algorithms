#include <iostream>
using namespace std;

const int MAX = 100;
int arr[MAX + 5]; //good practice too leave some more space

int main(){

int n;
cout << "n: ";
cin >> n;

// inserting
for (int i = 0; i < n; i++){
    cin >> arr[i];
}

// sorting - O(n^2)
for (int i = 0; i < n - 1; i++){            // -> O(n)
    for (int j = 0; j < n - 1 - i; j++){    // -> O(n)
        if (arr[j] > arr[j+1])
        swap(arr[j], arr[j+1]);
    }
}

// printing
for (int i = 0; i < n; i++){
    cout << arr[i] << ' ';
}

return 0;
}

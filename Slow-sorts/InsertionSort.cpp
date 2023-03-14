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

//sorting - O(n^2)
for (int i = 0; i < n; i++){
    int j = i;

    //check to the left
    while (j > 0 && arr[j-1] > arr[j]){
        swap(arr[j-1], arr[j]);
        j--;
    }
}

// printing
for (int i = 0; i < n; i++){
    cout << arr[i] << ' ';
}

return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& v, int target){
    int l = 0, h = v.size()-1;

    while(l <= h){
        int mid = l + (h-l)/2;

        if(target > v[mid]) l = mid + 1;
        else if(target < v[mid]) h = mid - 1;
        else return mid;
    }

    return -1;
}

int main(){

    vector<int> v = {10, 20, 30, 50, 60, 80, 110, 130, 140, 170};
    int target = 20;

    cout << target << " is at index: " << binarySearch(v, target);

    return 0;
}

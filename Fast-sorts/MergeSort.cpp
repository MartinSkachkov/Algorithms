#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& leftArr, vector<int>& rightArr, vector<int>& arr){

    // write the merged sorted data to the original arr
    int leftSize = leftArr.size();
    int rightSize = rightArr.size();

    int l = 0, r = 0, k = 0;
    while (l < leftSize && r < rightSize){
        if(leftArr[l] < rightArr[r]){
            arr[k] = leftArr[l];
            k++; l++;
        }else{
            arr[k] = rightArr[r];
            k++; r++;
        }
    }

    // save the leftovers to the original
    while (l < leftSize){
        arr[k] = leftArr[l];
        k++; l++;
    }

    while (r < rightSize){
        arr[k] = rightArr[r];
        k++; r++;
    }
}

void mergeSort(vector<int>& arr){

    int length = arr.size();
    if (length <= 1){ //base case
        return;
    }

    // create two new arrays for the left & right partition with the corresponding sizes
    int mid = length / 2;
    vector<int> leftArr(mid);
    vector<int> rightArr(length - mid);

    // split the elements from the original arr and save them to the left & right partition
    int l = 0, r = 0; // k - original arr, l - left, r - right
    for (int k = 0; k < length; k++){
        if(l < mid){
            leftArr[l] = arr[k];
            l++;
        }else{
            rightArr[r] = arr[k];
            r++;
        }
    }

    // now when we have the two subarrays call them mergeSort
    mergeSort(leftArr);
    mergeSort(rightArr);
    merge(leftArr, rightArr, arr);
}

int main(){

    vector<int> arr = {3, 7, 8, 5, 4, 2, 6, 1};

    mergeSort(arr);

    for (int elem : arr){
        cout << elem << ' ';
    }

    return 0;
}

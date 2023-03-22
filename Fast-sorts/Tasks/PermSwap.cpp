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

int permSwaps(vector<int>& perms){

    int length = perms.size();
    if (length <= 1){ //base case
        return 0;
    }

    // create two new arrays for the left & right partition with the corresponding sizes
    int mid = length / 2;
    vector<int> leftArr(mid);
    vector<int> rightArr(length - mid);

    // split the elements from the original arr and save them to the left & right partition
    int l = 0, r = 0; // k - original arr, l - left, r - right
    for (int k = 0; k < length; k++){
        if(l < mid){
            leftArr[l] = perms[k];
            l++;
        }else{
            rightArr[r] = perms[k];
            r++;
        }
    }

    long long ans = permSwaps(leftArr) + permSwaps(rightArr);

    int ind2 = mid + 1;
    for (int ind1 = 0; ind1 <= mid; ind1++){
        //found a permutation
        while (ind2 <= r && perms[ind2] <= perms[ind1]){
            ind2++;
        }
        ans += ind2-mid-1;
    }

    merge(leftArr,rightArr,perms);
    return ans;
}

int main(){

    vector<int> perms = {0, 4, 2, 1, 3};

    cout << permSwaps(perms);

    return 0;
}

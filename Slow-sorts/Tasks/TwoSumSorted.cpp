#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> towPointer(const vector<int>& nums, const int& target){
    int sum = 0;
    int l = 0, r = nums.size() - 1;

    while (l < r){
        sum = nums[l] + nums[r];

        if (sum == target){
            return {l, r};
        }else if (sum < target){
            l++;
        }else{ // sum > target
            r--;
        }
    }

    return {};
}

int main(){

int n, num, target;
cout << "n: ";
cin >> n;

cout << "target: ";
cin >> target;

vector<int> numbers;
for (int i = 0; i < n; i++){
    cin >> num;
    numbers.push_back(num);
}

sort(numbers.begin(), numbers.end());

vector<int> res = towPointer(numbers, target);
for (int indx : res){
    cout << indx << ' ';
}

return 0;
}




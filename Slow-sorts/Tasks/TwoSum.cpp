#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {

    int n, num, target;
    cout << "n: ";
    cin >> n;

    cout << "target: ";
    cin >> target;

    vector<int> numbers;
    for (size_t i = 0; i < n; i++) {
        cin >> num;
        numbers.push_back(num);
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if (numbers[i] + numbers[j] == target) {
                cout << i << ' ' << j;
                return 0;
            }
        }
    }

    return 0;
}
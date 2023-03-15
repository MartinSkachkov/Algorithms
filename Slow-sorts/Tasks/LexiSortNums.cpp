#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool lexiComp(int n1, int n2) {
    string n1Str = to_string(n1);
    string n2Str = to_string(n2);

    return lexicographical_compare(n1Str.begin(), n1Str.end(), n2Str.begin(), n2Str.end());
}

int main() {

    int n, num;
    cout << "n: ";
    cin >> n;
    
    vector<int> numbers;
    for (size_t i = 0; i < n; i++) {
        cin >> num;
        numbers.push_back(num);
    }

    sort(numbers.begin(), numbers.end(), lexiComp);

    for (int x : numbers) {
        cout << x << ' ';
    }

    /* using a lambda function
    std::sort(myVector->begin(),myVector->end(), [](const unsigned int& x, const unsigned int& y){
        std::string tmp1 = std::to_string(x);
        std::string tmp2 = std::to_string(y);
        return lexicographical_compare(tmp1.begin(),tmp1.end(),tmp2.begin(),tmp2.end());
} );
    */

    return 0;
}
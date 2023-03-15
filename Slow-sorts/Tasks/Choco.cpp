#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Date {
    unsigned day;
    unsigned month;
    unsigned year;

    bool operator<(const Date& other) {
        if (year != other.year) {
            return year < other.year;
        }

        if (month != other.month) {
            return month < other.month;
        }

        if (day != other.day) {
            return day < other.day;
        }

        return false;
    }
};

int main() {

    char dot;
    unsigned n, day, month, year;

    cout << "n: ";
    cin >> n;

    vector<Date> expDates;
    for (int i = 0; i < n; i++) {
        cin >> day >> dot >> month >> dot >> year;
        Date curr{ day, month, year };
        expDates.push_back(curr);
    }

    sort(expDates.begin(), expDates.end());

    for (Date d : expDates) {
        cout << d.day << '.' << d.month << '.' << d.year << ' ';
    }

    return 0;
}
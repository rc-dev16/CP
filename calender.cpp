#include <iostream>
using namespace std;

int main() {
    int year, firstDay;
    cout << "Enter the year and the first day of the year: ";
    cin >> year >> firstDay;

    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    days[1] += (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    int d = firstDay;

    for (int i = 0; i < 12; i++) {
        int secondSaturday = 14 - ((d + 1) % 7);
        if (secondSaturday <= 0) secondSaturday += 7;

        cout << secondSaturday << endl;

        d = (d + days[i]) % 7;
    }

    return 0;
}
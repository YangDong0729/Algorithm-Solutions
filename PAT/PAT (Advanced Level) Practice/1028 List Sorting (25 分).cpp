#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Student {
    static int c;
    string s[3];

    bool operator<(const Student& x) {
        if (s[c - 1] != x.s[c - 1]) return s[c - 1] < x.s[c - 1];
        else return s[0] < x.s[0];
    }
} student[100010];

int Student::c = 1;

int main() {
    int n;
    cin >> n >> Student::c;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; ++j)
            cin >> student[i].s[j];

    sort(student, student + n);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 3; ++j)
            cout << student[i].s[j] << (j == 2 ? "\n" : " ");
}

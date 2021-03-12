#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string a[10005];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n, [](string& x, string& y) {
        return x + y < y + x;
        });

    string s;
    for (int i = 0; i < n; ++i) s += a[i];

    int l = 0, size = s.length();
    for (; l < size; ++l) if (s[l] != '0') break;

    if (l == size) cout << "0";
    else cout << s.substr(l);
}
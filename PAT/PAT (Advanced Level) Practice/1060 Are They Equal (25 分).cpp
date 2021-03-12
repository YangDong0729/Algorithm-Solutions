#include <iostream>
#include <string>

using namespace std;

int removeLeadingZero(string& s) {
    int i = 0;
    while (i < s.length() and s[i] == '0') ++i;
    s = s.substr(i);
    return i;
}

string deal(string a, int n, string& s, int& k) {
    k = 0;
    s = "";

    removeLeadingZero(a);
    if (a.length() > 0 and a[0] == '.') {
        a.erase(a.begin());
        k -= removeLeadingZero(a);
    }
    else {
        int i = 0;
        while (i < a.length() and a[i] != '.')
            ++i;
        k += i;
        if (i < a.length())
            a.erase(a.begin() + i);
    }
    if (a.length() == 0) k = 0;

    for (int i = 0, j = 0; i < n; ++i) {
        if (j < a.length())
            s += a[j++];
        else
            s += '0';
    }
    return s;
}

int main() {
    int k1, k2, n;
    string a, b, s1, s2;
    cin >> n >> a >> b;

    deal(a, n, s1, k1);
    deal(b, n, s2, k2);

    if (s1 == s2 and k1 == k2)
        cout << "YES 0." << s1 << "*10^" << k1 << '\n';
    else
        cout << "NO 0." << s1 << "*10^" << k1 << " 0." << s2 << "*10^" << k2 << '\n';
}
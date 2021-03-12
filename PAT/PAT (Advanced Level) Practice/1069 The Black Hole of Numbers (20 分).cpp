#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    s.insert(0, 4 - s.length(), '0');

    do {
        string a = s, b = s;

        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end());

        int result = stoi(a) - stoi(b);

        s = to_string(result);
        s.insert(0, 4 - s.length(), '0');

        cout << a << " - " << b << " = " << s << '\n';
    } while (s != "6174" and s != "0000");
}
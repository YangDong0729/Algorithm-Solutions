#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    string s = to_string(a + b);

    for (int i = 0, len = s.length(); i < len; i++) {
        cout << s[i];
        if (s[i] == '-' or i == len - 1) continue;
        if ((i + 1) % 3 == len % 3) cout << ",";
    }
}
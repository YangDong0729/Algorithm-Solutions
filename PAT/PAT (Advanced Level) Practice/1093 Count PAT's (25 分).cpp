#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int p[100005], t[100005];

int main() {
    string s;
    cin >> s;

    long long ans = 0;

    int len = s.length();
    // 计算每个位置（包括）左边的P
    if (s[0] == 'P') p[0] = 1;
    for (int i = 1; i < len; ++i) {
        p[i] = p[i - 1];
        if (s[i] == 'P') ++p[i];
    }

    // 计算每个位置（包括）右边的T
    if (s[len - 1] == 'T') t[len - 1] = 1;
    for (int i = len - 1; i >= 0; --i) {
        t[i] = t[i + 1];
        if (s[i] == 'T') ++t[i];
    }

    for (int i = 1; i < len - 1; ++i)
        if (s[i] == 'A')
            ans = (ans + p[i - 1] * t[i + 1]) % 1000000007;
    cout << ans;
}

#include <array>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    int k;
    string s;
    queue<char> q;
    array<bool, 300> isStuck, isFound;

    isFound.fill(false);
    isStuck.fill(false);

    cin >> k >> s;
    for (auto i = s.begin(); i != s.end();) {
        int c = *i, t = 0;
        while (i != s.end() and *i == c) {
            ++t;
            ++i;
        }
        if (t % k == 0 and !isFound[c]) {
            isStuck[c] = true;
            q.push(c);
        } else if (t % k)
            isStuck[c] = false;
        isFound[c] = true; // 保证只加入一次队列
    };

    while (!q.empty()) {
        char c = q.front();
        q.pop();
        if (isStuck[c])
            cout << c;
    }
    cout << "\n";

    for (auto i = s.begin(); i != s.end(); isStuck[*i] ? i += k : ++i)
        cout << *i;
}
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    int n, k;
    unordered_map<string, vector<int>> mp;

    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int courseNo, m;
        cin >> courseNo >> m;
        for (int j = 0; j < m; ++j) {
            cin >> s;
            mp[s].push_back(courseNo);
        }
    }

    for (int i = 0; i < n; ++i) {
        cin >> s;
        sort(mp[s].begin(), mp[s].end());
        cout << s << ' ' << mp[s].size();
        for (auto& e : mp[s])
            cout << ' ' << e;
        cout << '\n';
    }
}
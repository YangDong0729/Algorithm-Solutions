#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    int n, m, k, t, a, b;

    cin >> n >> m;
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < m; ++i) {
        cin >> k;

        unordered_set<int> list;
        for (int j = 0; j < k; ++j) {
            cin >> t;
            list.insert(t);
        }

        for (auto& u : list)
            for (auto& v : adj[u])
                if (list.count(v)) goto No;

        cout << "Yes\n";
        continue;
    No: 
        cout << "No\n";
    }
}
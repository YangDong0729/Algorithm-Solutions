#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int level;
    vector<int> follower;
} node[1005];

bool visited[1005];

int bfs(int x, int maxLevel, int n) {
    fill_n(visited + 1, n, false);

    int cnt = 0;
    queue<int> q;
    q.push(x);
    visited[x] = true;
    node[x].level = 0;

    while (not q.empty()) {
        int f = q.front();
        q.pop();
        if (node[f].level < maxLevel) {
            for (auto &e : node[f].follower) {
                if (not visited[e]) {
                    ++cnt;
                    node[e].level = node[f].level + 1;
                    visited[e] = true;
                    q.push(e);
                }
            }
        }
    }

    return cnt;
}

int main() {
    int n, l, m, c, q, k;

    cin >> n >> l;
    for (int i = 1; i <= n; ++i) {
        cin >> m;
        for (int j = 0; j < m; ++j) {
            cin >> c;
            node[c].follower.push_back(i);
        }
    }

    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> q;
        cout << bfs(q, l, n) << "\n";
    }
}
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int weight;
    vector<int> child;

    bool isLeaf() {
        return child.size() == 0;
    }
} node[105];

int n, m, s;
vector<int> path;

void dfs(int idx, int weight) {
    if (node[idx].isLeaf() or weight >= s) {
        if (node[idx].isLeaf() and weight == s) {
            for (int i = 0; i < path.size(); ++i) {
                cout << path[i];
                if (i != path.size() - 1)
                    cout << " ";
            }
            cout << '\n';
        }
        return;
    }

    for (auto &e : node[idx].child) {
        path.push_back(node[e].weight);
        dfs(e, weight + node[e].weight);
        path.pop_back();
    }
}

int main() {
    cin >> n >> m >> s;

    for (int i = 0; i < n; ++i)
        cin >> node[i].weight;

    for (int i = 0; i < m; ++i) {
        int t, u;
        cin >> t >> u;

        for (int j = 0; j < u; ++j) {
            int c;
            cin >> c;
            node[t].child.push_back(c);
        }
        // 排序，这样就能够保证路径按照非升输出
        sort(node[t].child.begin(), node[t].child.end(),
             [](int a, int b) {
                 return node[a].weight > node[b].weight;
             });
    }

    path.push_back(node[0].weight);
    dfs(0, node[0].weight);
}
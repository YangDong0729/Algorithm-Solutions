#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int level;
    vector<int> children;
} node[105];

int levelCnt[105];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int id;
        cin >> id;

        int k;
        cin >> k;

        for (int j = 0; j < k; ++j) {
            int c;
            cin >> c;

            node[id].children.push_back(c);
        }
    }

    node[1].level = 1;

    queue<int> q;
    q.push(1);
    int largestLevel = 1;

    while (not q.empty()) {
        int top = q.front();
        Node& t = node[top];
        q.pop();

        if (++levelCnt[t.level] > levelCnt[largestLevel])
            largestLevel = t.level;

        for (auto i : t.children) {
            Node& e = node[i];
            e.level = t.level + 1;
            q.push(i);
        }
    }

    cout << levelCnt[largestLevel] << " " << largestLevel;
}
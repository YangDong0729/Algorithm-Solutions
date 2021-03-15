#include <iostream>
#include <vector>

using namespace std;

vector<int> nodes[105];
// leaf[i]：第i层的叶子结点的个数
// level[i]：结点i的层数
// maxLevel最大层数
int leaf[105], level[105], maxLevel;

void dfs(int root) {
    int l = level[root]; // 当深搜到root时，root的层数一定确定了

    if (l > maxLevel)
        maxLevel = l;

    if (nodes[root].size() == 0)      // 这个结点是叶子结点
        ++leaf[l];                    // 这层的叶子结点数+1
    else                              // 这个结点不是叶子节点
        for (auto &e : nodes[root]) { // 遍历他的孩子
            level[e] = l + 1;
            dfs(e);
        }
}
int main() {
    int n, m;

    cin >> n;

    if (n == 0)
        return 0;

    cin >> m;

    for (int i = 0; i < m; ++i) {
        int id, k;
        cin >> id >> k;

        for (int j = 0; j < k; ++j) {
            int c;
            cin >> c;

            nodes[id].push_back(c);
        }
    }

    level[1] = 0;

    dfs(1);

    for (int i = 0; i <= maxLevel; ++i) {
        cout << leaf[i];
        if (i != maxLevel)
            cout << " ";
    }
}
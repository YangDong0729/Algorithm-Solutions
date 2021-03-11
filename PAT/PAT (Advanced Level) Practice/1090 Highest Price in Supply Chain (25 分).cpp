#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    double p;
    vector<int> children;
} node[100005];

int n, root = -1, cnt;
double rootPrice, r, maxP;

void dfs(int x) {
    if (node[x].children.empty()) {
        if (node[x].p > maxP) {
            maxP = node[x].p;
            cnt = 1;
        }
        else if (node[x].p == maxP) {
            ++cnt;
        }
    }
    else {
        for (auto i : node[x].children) {
            node[i].p = node[x].p * r;
            dfs(i);
        }
    }
}

int main() {
    cin >> n >> rootPrice >> r;

    r = 1 + r / 100;

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;

        if (k == -1) {
            root = i;
            node[root].p = rootPrice;
        }
        else
            node[k].children.push_back(i);
    }

    dfs(root);

    printf("%.2f %d", maxP, cnt);
}
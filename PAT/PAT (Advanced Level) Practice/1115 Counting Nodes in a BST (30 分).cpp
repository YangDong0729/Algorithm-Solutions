#include <iostream>
#include <queue>

using namespace std;

struct node {
    int val;
    node *left, *right;
};

void insert(node *&root, int val) {
    if (root == nullptr) {
        root = new node{val};
        return;
    }

    if (root->val < val) // 题写错了，按照题意这里应该是<=
        insert(root->right, val);
    else
        insert(root->left, val);
}

int cnt[1005];

void dfs(node *root, int level) {
    cnt[level]++;
    if (root->left)
        dfs(root->left, level + 1);
    if (root->right)
        dfs(root->right, level + 1);
}

int main() {
    int n, c;
    node *root = nullptr;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        insert(root, c);
    }

    dfs(root, 1);

    for (int i = 1004; i >= 1; --i) {
        if (cnt[i] != 0) {
            cout << cnt[i] << " + " << cnt[i - 1] << " = " << cnt[i] + cnt[i - 1];
            return 0;
        }
    }
}
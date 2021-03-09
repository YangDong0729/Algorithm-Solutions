#include <iostream>

using namespace std;

struct node {
    int val;
    node *left, *right;
};

bool is_black(node *x) {
    return x == nullptr || x->val > 0; // 3
}

bool is_red(node *x) {
    return x && x->val < 0;
}

void add(node *&root, int val) {
    if (root == nullptr)
        root = new node{val};
    else if (abs(val) < abs(root->val))
        add(root->left, val);
    else
        add(root->right, val);
}

bool check(node *root, int &black_cnt) {
    if (is_black(root))
        ++black_cnt;
    if (root == nullptr)
        return true;
    if (is_red(root) && !(is_black(root->left) && is_black(root->right)))
        return false; // 4
    int l_b_cnt = 0, r_b_cnt = 0;
    if (check(root->left, l_b_cnt) && check(root->right, r_b_cnt) && l_b_cnt == r_b_cnt) { // 5
        black_cnt += l_b_cnt;
        return true;
    }
    return false;
}

int main() {
    int k, n, x;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int black_cnt = 0;
        node *root = nullptr;

        cin >> n;
        for (int j = 0; j < n; ++j) {
            cin >> x;
            add(root, x);
        }
        // 2
        cout << (is_black(root) && check(root, black_cnt) ? "Yes" : "No") << "\n";
    }
}
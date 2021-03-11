#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
    int val;
    node *left, *right;
};

void leftRotate(node *&A) {
    node *B = A->right;
    A->right = B->left;
    B->left = A;
    A = B;
}

void rightRotate(node *&A) {
    node *B = A->left;
    A->left = B->right;
    B->right = A;
    A = B;
}

void leftRightRotate(node *&A) {
    leftRotate(A->left);
    rightRotate(A);
}

void rightLeftRotate(node *&A) {
    rightRotate(A->right);
    leftRotate(A);
}

int getHeight(node *A) {
    if (A == nullptr)
        return 0;
    int l = getHeight(A->left);
    int r = getHeight(A->right);
    return max(l, r) + 1;
}

void insert(node *&A, int val) {
    if (A == nullptr) {
        A = new node{val};
    } else if (A->val > val) {
        insert(A->left, val);
        if (getHeight(A->left) - getHeight(A->right) >= 2) {
            if (val < A->left->val)
                rightRotate(A);
            else
                leftRightRotate(A);
        }
    } else {
        insert(A->right, val);
        if (getHeight(A->left) - getHeight(A->right) <= -2) {
            if (val > A->right->val)
                leftRotate(A);
            else
                rightLeftRotate(A);
        }
    }
}

int main() {
    int n, a;
    node *root = nullptr;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        insert(root, a);
    }

    queue<node *> q;
    q.push(root);

    vector<int> level_order;
    bool complete = true, leaf = false;

    while (not q.empty()) {
        auto front = q.front();
        q.pop();
        if (front->left)
            q.push(front->left);
        if (front->right)
            q.push(front->right);
        level_order.push_back(front->val);
        // 判定完全二叉树
        if (!front->left and !front->right) // 注意这个判断应该放在前面
            leaf = true;                    // 后面全应该是叶子
        else if (leaf)
            complete = false;
        if (front->right and !front->left) // 右有左无一定不能出现
            complete = false;
        else if (!front->right and front->left)
            leaf = true; // 后面全应该是叶子
    }

    for (auto i = level_order.begin(); i != level_order.end(); ++i)
        cout << *i << (i + 1 == level_order.end() ? "\n" : " ");
    cout << (complete ? "YES" : "NO") << "\n";
}
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node {
    int val, depth;
    node *lChild = nullptr, *rChild = nullptr, *parent = nullptr;
};

int postOrder[35], inOrder[35];
bool isFull = true;

node *create(int postRoot, int inL, int inR, int depth, node *parent) {
    if (inL > inR)
        return nullptr;

    node *root = new node;
    root->depth = depth;
    root->parent = parent;
    root->val = postOrder[postRoot];

    int inRoot = inL;
    while (inOrder[inRoot] != postOrder[postRoot])
        ++inRoot;

    root->lChild = create(postRoot - 1 - inR + inRoot, inL, inRoot - 1, depth + 1, root);
    root->rChild = create(postRoot - 1, inRoot + 1, inR, depth + 1, root);

    if ((root->lChild == nullptr and root->rChild != nullptr) or
        (root->lChild != nullptr and root->rChild == nullptr))
        isFull = false;

    return root;
}

node *search(node *root, int target) {
    if (root == nullptr or root->val == target)
        return root;
    node *ret = search(root->lChild, target);
    if (ret and ret->val == target)
        return ret;
    return search(root->rChild, target);
}

int main() {
    //    freopen("in.txt", "r", stdin);
    //    freopen("out.txt", "w", stdout);

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> postOrder[i];
    for (int i = 0; i < n; ++i)
        cin >> inOrder[i];

    node *root = create(n - 1, 0, n - 1, 0, nullptr);

    cin >> n;
    cin.get();
    for (int i = 0; i < n; ++i) {
        bool ok;
        string s;
        int a, b;
        getline(cin, s);

        if (*s.rbegin() == 't') {
            sscanf(s.c_str(), "%d", &a);
            ok = a == root->val;
        } else if (*s.rbegin() == 'e') {
            ok = isFull;
        } else if (*s.rbegin() == 's') {
            sscanf(s.c_str(), "%d and %d", &a, &b);
            node *ra = search(root, a);
            node *rb = search(root, b);
            ok = ra and rb and ra->parent == rb->parent;
        } else if (*s.rbegin() == 'l') {
            sscanf(s.c_str(), "%d and %d", &a, &b);
            node *ra = search(root, a);
            node *rb = search(root, b);
            ok = ra and rb and ra->depth == rb->depth;
        } else if (s.find("parent") != string::npos) {
            sscanf(s.c_str(), "%d is the parent of %d", &a, &b);
            node *ra = search(root, a);
            ok = ra and ((ra->lChild and ra->lChild->val == b) or
                         (ra->rChild and ra->rChild->val == b));
        } else if (s.find("left") != string::npos) {
            sscanf(s.c_str(), "%d is the left child of %d", &a, &b);
            node *rb = search(root, b);
            ok = rb and rb->lChild and rb->lChild->val == a;
        } else {
            sscanf(s.c_str(), "%d is the right child of %d", &a, &b);
            node *rb = search(root, b);
            ok = rb and rb->rChild and rb->rChild->val == a;
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
}
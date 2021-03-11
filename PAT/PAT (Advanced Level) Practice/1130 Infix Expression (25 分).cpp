#include <iostream>
#include <map>
#include <string>

using namespace std;

struct {
    string v;
    int l = -1, r = -1, p = -1;
} tree[25];

void in(int root) {
    if (tree[root].p != -1 and (tree[root].l != -1 or tree[root].r != -1))
        cout << "(";
    if (tree[root].l != -1)
        in(tree[root].l);
    cout << tree[root].v;
    if (tree[root].r != -1)
        in(tree[root].r);
    if (tree[root].p != -1 and (tree[root].l != -1 or tree[root].r != -1))
        cout << ")";
}

int main() {
    string s;
    int n, l, r;

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s >> l >> r;
        tree[i].v = s;
        tree[i].l = l;
        tree[i].r = r;
        if (l != -1)
            tree[l].p = i;
        if (r != -1)
            tree[r].p = i;
    }

    int root = 1;
    while (tree[root].p != -1)
        root = tree[root].p;

    in(root);
}
#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
    int value, order, level_order, left = -1, right = -1;
} node[35];

void insert(int x, int y) {
    if (node[x].order < node[y].order) {
        if (node[y].left == -1) {
            node[y].left = x;
            node[x].level_order = node[y].level_order * 2;
        }
        else insert(x, node[y].left);

    }
    else {
        if (node[y].right == -1) {
            node[y].right = x;
            node[x].level_order = node[y].level_order * 2 + 1;
        }
        else insert(x, node[y].right);
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        node[i].order = i;
        cin >> node[i].value;
    }

    sort(node, node + n, [](Node& a, Node& b) {
        return a.value < b.value;
        });

    node[0].level_order = 1;
    for (int i = 1; i < n; ++i) {
        insert(i, 0);
    }

    sort(node, node + n, [](Node& a, Node& b) {
        return a.level_order < b.level_order;
        });

    for (int i = 0; i < n; ++i) {
        cout << node[i].value << (i == n - 1 ? "" : " ");
    }
}

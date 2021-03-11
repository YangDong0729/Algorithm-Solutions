#include <iostream>
#include <string>

using namespace std;

struct node {
    string s;
    int lChild, rChild, parent = -1;
} nodes[30];

void traverse(int root) {
    if ((nodes[root].lChild == -1 or nodes[root].rChild == -1) and nodes[root].lChild != nodes[root].rChild) {
        cout << "(" << nodes[root].s;
        if (nodes[root].lChild != -1)
            traverse(nodes[root].lChild);
        if (nodes[root].rChild != -1)
            traverse(nodes[root].rChild);
        cout << ")";
    } else if (nodes[root].lChild != -1) {
        cout << "(";
        traverse(nodes[root].lChild);
        traverse(nodes[root].rChild);
        cout << nodes[root].s << ")";
    } else {
        cout << "(" << nodes[root].s << ")";
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> nodes[i].s >> nodes[i].lChild >> nodes[i].rChild;
        nodes[nodes[i].lChild].parent = i;
        nodes[nodes[i].rChild].parent = i;
    }

    int root = 1;
    while (nodes[root].parent != -1)
        root = nodes[root].parent;

    traverse(root);
}
#include <iostream>
#include <cctype>
#include <sstream>
#include <queue>
#include <algorithm>

using namespace std;

struct {
    int lChild = -1, rChild = -1;
} node[15];

bool isChild[15];

void levelOrder(int root) {
    queue<int> q;
    q.push(root);

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        if (node[top].lChild != -1) q.push(node[top].lChild);
        if (node[top].rChild != -1) q.push(node[top].rChild);

        cout << top;
        if (!q.empty()) cout << " ";
    }

    cout << "\n";
}

void inOrder(int root) {
    if (node[root].lChild != -1) {
        inOrder(node[root].lChild);
        cout << " ";
    }
    cout << root;
    if (node[root].rChild != -1) {
        cout << " ";
        inOrder(node[root].rChild);
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if (isdigit(c)) {  // 在读入时反向
            int r = c - '0';
            node[i].rChild = r;
            isChild[r] = true;
        }
        cin >> c;
        if (isdigit(c)) {
            int l = c - '0';
            node[i].lChild = l;
            isChild[l] = true;
        }
    }

    int root = 0;
    while (isChild[root]) ++root;

    levelOrder(root);
    inOrder(root);
}
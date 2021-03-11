#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct {
    int val;
    int lChild, rChild;
} node[105];

int arr[105];

void inOrder(int root, int& index) {
    if (node[root].lChild != -1)
        inOrder(node[root].lChild, index);

    node[root].val = arr[index++];

    if (node[root].rChild != -1)
        inOrder(node[root].rChild, index);
}

void levelOrder() {
    queue<int> q;
    q.push(0);

    while (not q.empty()) {
        int top = q.front();
        q.pop();

        cout << node[top].val;

        if (node[top].lChild != -1) q.push(node[top].lChild);
        if (node[top].rChild != -1) q.push(node[top].rChild);

        if (not q.empty()) cout << " ";
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> node[i].lChild >> node[i].rChild;

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    sort(arr, arr + n);

    int i = 0;
    inOrder(0, i);

    levelOrder();
}
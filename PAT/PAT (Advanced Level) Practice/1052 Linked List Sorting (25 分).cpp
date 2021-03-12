#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int address;
    int key;
    int next;
    bool valid;

    friend bool operator<(const Node &a, const Node &b) {
        if (!a.valid or !b.valid)
            return a.valid > b.valid;
        else
            return a.key < b.key;
    }
} node[100005];

int main() {
    int n, head;
    cin >> n >> head;

    for (int i = 0; i < n; ++i) {
        int a, k, nt;
        cin >> a >> k >> nt;
        node[a] = {a, k, nt};
    }

    // 统计所有有效的节点
    int size = 0;
    for (int p = head; p != -1; p = node[p].next) {
        node[p].valid = true;
        ++size;
    }
    cout << size << " ";

    sort(node, node + 100005);

    if (!node[0].valid) // 坑点： size 可能为 0
        cout << -1 << '\n';
    else
        cout << setw(5) << setfill('0') << node[0].address << '\n';

    for (int i = 0; i < size; ++i) {
        cout << setw(5) << setfill('0') << node[i].address << " "
             << node[i].key << " ";
        if (i + 1 == size)
            cout << -1;
        else
            cout << setw(5) << setfill('0') << node[i + 1].address;
        cout << '\n';
    }
}
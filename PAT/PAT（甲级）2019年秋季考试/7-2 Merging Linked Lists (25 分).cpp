#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct node {
    int data, addr;
};

node nodes[100005];

int main() {
    int headA, headB, n;
    cin >> headA >> headB >> n;

    for (int i = 0; i < n; ++i) {
        int address, data, next;
        cin >> address >> data >> next;
        nodes[address] = {data, next};
    }

    vector<node> a, b, c;
    for (int p = headA; p != -1; p = nodes[p].addr)
        a.push_back({nodes[p].data, p});
    for (int p = headB; p != -1; p = nodes[p].addr)
        b.push_back({nodes[p].data, p});

    if (a.size() < b.size())
        swap(a, b);
    reverse(b.begin(), b.end());
    for (int i = 0, j = 0, k = 0; i < a.size() || j < b.size(); ++k) {
        if (k % 3 == 2 && j < b.size())
            c.push_back(b[j++]);
        else
            c.push_back(a[i++]);
    }

    for (int i = 0; i < c.size(); ++i) {
        printf("%05d %d ", c[i].addr, c[i].data);
        if (i == c.size() - 1)
            cout << "-1\n";
        else
            printf("%05d\n", c[i + 1].addr);
    }
}
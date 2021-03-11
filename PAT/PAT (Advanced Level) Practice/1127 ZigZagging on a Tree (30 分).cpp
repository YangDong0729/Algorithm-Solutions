#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int in[35], post[35];

struct node {
    int val, index;
    bool operator<(const node &x) const {
        return index < x.index;
    }
};

vector<node> t;

void trav(int inL, int postL, int len, int index) {
    if (len <= 0)
        return;
    int root = post[postL + len - 1];
    t.push_back({root, index});

    // 找到root
    int pos = inL;
    for (int i = 0; i < len; ++i) {
        if (in[inL + i] == root) {
            pos += i;
            break;
        }
    }

    // 遍历子树
    trav(inL, postL, pos - inL, index * 2);
    trav(pos + 1, postL + pos - inL, inL + len - pos - 1, index * 2 + 1);
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> in[i];
    for (int i = 1; i <= n; ++i)
        cin >> post[i];

    trav(1, 1, n, 1);
    sort(t.begin(), t.end()); // 得到层序遍历

    bool should_reverse = true;
    for (int i = 0, j, min = 1; i < t.size(); i = j, min *= 2, should_reverse = !should_reverse) {
        j = i;
        while (min <= t[j].index and t[j].index < min * 2)
            ++j;
        if (should_reverse)
            reverse(t.begin() + i, t.begin() + j);
    }

    for (auto i = t.begin(); i != t.end(); ++i)
        cout << i->val << (i + 1 == t.end() ? "\n" : " ");
}
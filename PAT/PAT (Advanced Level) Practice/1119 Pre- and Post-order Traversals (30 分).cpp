#include <iostream>
#include <vector>

using namespace std;

vector<int> in;
bool uniq = true;
int pre[35], post[35];

void trav(int preL, int postL, int n) {
    if (n == 1) {
        in.push_back(pre[preL]);
        return;
    }

    int p = pre[preL];
    int l = pre[preL + 1]; // 左子树的根
    int q = postL;
    for (; q < postL + n; ++q) // 在后序遍历中，左子树的根是左子树中最后一个被访问的
        if (post[q] == l)
            break;

    trav(preL + 1, postL, q - postL + 1); // 向左子树递归
    in.push_back(p);
    if (q == postL + n - 2)
        uniq = false; // 说明只有一个子树，那是左子树还是右子树就都有可能了
    else
        trav(preL + 1 + q - postL + 1, q + 1, postL + n - q - 2); // 向右子树递归
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> pre[i];
    for (int i = 0; i < n; ++i)
        cin >> post[i];

    trav(0, 0, n);

    cout << (uniq ? "Yes\n" : "No\n");
    for (auto i = in.begin(); i != in.end(); ++i)
        cout << *i << (i + 1 == in.end() ? "\n" : " ");
}
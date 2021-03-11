#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> inOrder, preOrder;

// preL：前序遍历起始位置，inL：中序遍历起始位置，len：长度
void create(int preL, int inL, int len) {
    int root;  // 当前子树的根节点在中序遍历中的位置
    for (root = inL; root < inL + len; ++root) {
        if (inOrder[root] == preOrder[preL])
            break;
    }

    int lLen = root - inL;            // 当前子树的左子树的中序遍历长度
    int rLen = inL + len - root - 1;  // 当前子树的右子树的中序遍历长度

    if (lLen > 0) {  // 递归地构建左子树
        create(preL + 1, inL, lLen);
        cout << " ";
    }

    if (rLen > 0) {  // // 递归地构建右子树
        create(preL + len - rLen, root + 1, rLen);
        cout << " ";
    }

    cout << preOrder[preL];
}

int main() {
    int n;
    cin >> n;

    stack<int> stk;  // 用这个栈去执行一遍给定的操作，得到前序遍历和中序遍历

    for (int i = 0; i < 2 * n; ++i) {
        string op;
        cin >> op;

        if (op[1] == 'u') {
            int val;
            cin >> val;

            stk.push(val);
            preOrder.push_back(val);
        }
        else {
            inOrder.push_back(stk.top());
            stk.pop();
        }
    }

    create(0, 0, n);
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <vector>

#define SIZE 10005

using namespace std;

int in[SIZE], pre[SIZE];
unordered_map<int, int> pos; // pos记录每个结点在中序遍历中的位置

void lca(int inL, int inR, int preL, int a, int b) {
    if (inL > inR)
        return;

    int inRoot = pos[pre[preL]], aIn = pos[a], bIn = pos[b];

    if (aIn < inRoot and bIn < inRoot) // 最低公共结点在root的左子树
        lca(inL, inRoot - 1, preL + 1, a, b);
    else if ((aIn < inRoot and bIn > inRoot) or (aIn > inRoot and bIn < inRoot)) // LCA就是root
        printf("LCA of %d and %d is %d.\n", a, b, in[inRoot]);
    else if (aIn > inRoot and bIn > inRoot) // LCA在root的右子树
        lca(inRoot + 1, inR, preL + 1 + (inRoot - inL), a, b);
    else if (aIn == inRoot)
        printf("%d is an ancestor of %d.\n", a, b);
    else if (bIn == inRoot)
        printf("%d is an ancestor of %d.\n", b, a);
}

int main() {
    int m, n, a, b;
    scanf("%d %d", &m, &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &in[i]);
        pos[in[i]] = i; // 免得重建时还需要查找，也便于确定是否存在
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &pre[i]);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        if (pos[a] == 0 and pos[b] == 0)
            printf("ERROR: %d and %d are not found.\n", a, b);
        else if (pos[a] == 0 or pos[b] == 0)
            printf("ERROR: %d is not found.\n", pos[a] == 0 ? a : b);
        else
            lca(1, n, 1, a, b);
    }
}

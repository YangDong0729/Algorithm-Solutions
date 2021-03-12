#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int postOrder[35], inOrder[35];
vector<pair<int, int>> layerOrder;

void build(int inL, int postL, int len, int index) {
    if (len <= 0) return;

    layerOrder.push_back({ index, postOrder[postL + len - 1] });

    int inRoot = inL;
    while (inRoot < inL + len and inOrder[inRoot] != postOrder[postL + len - 1])
        ++inRoot;

    int lLen = inRoot - inL, rLen = len - lLen - 1;

    build(inL, postL, lLen, index * 2);
    build(inRoot + 1, postL + lLen, rLen, index * 2 + 1);
}

int main() {
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &postOrder[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &inOrder[i]);

    build(0, 0, n, 1);
    sort(layerOrder.begin(), layerOrder.end());

    for (auto i = layerOrder.begin(); i < layerOrder.end(); ++i) {
        printf("%d", i->second);
        if (i + 1 != layerOrder.end()) printf(" ");
    }
}
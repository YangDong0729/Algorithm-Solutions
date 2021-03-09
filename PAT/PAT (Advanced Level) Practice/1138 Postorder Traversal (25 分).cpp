#include <iostream>

using namespace std;

int in[50005], pre[50005];

int firstOfPostOder(int *in, int *pre, int len) {
    if (len == 1)
        return *in;
    int root = *pre;
    int *p = in;
    while (*p != root)
        ++p;
    if (p != in)
        return firstOfPostOder(in, pre + 1, p - in);
    else
        return firstOfPostOder(in + 1, pre + 1, len - 1); // 左子树为空
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> pre[i];
    for (int i = 1; i <= n; ++i)
        cin >> in[i];
    cout << firstOfPostOder(in + 1, pre + 1, n);
}
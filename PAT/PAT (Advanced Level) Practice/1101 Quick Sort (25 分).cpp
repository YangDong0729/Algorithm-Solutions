#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int arr[100005];
int lMax[100005];
int rMin[100005];

int main() {
    // 读入
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    // 计算每个位置（包括）的左边最大的数
    lMax[0] = arr[0];
    for (int i = 1; i < n; ++i)
        lMax[i] = max(arr[i], lMax[i - 1]);

    // 计算每个位置（包括）的右边最小的数
    if (n - 1 > 0)
        rMin[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; --i)
        rMin[i] = min(arr[i], rMin[i + 1]);

    // 计算可能的主元
    vector<int> priv;
    if (arr[0] <= rMin[1])
        priv.push_back(arr[0]);
    if (n - 2 > 0 and arr[n - 1] >= lMax[n - 2])
        priv.push_back(arr[n - 1]);
    for (int i = 1; i < n - 1; ++i)
        if (arr[i] >= lMax[i - 1] and arr[i] <= rMin[i + 1])
            priv.push_back(arr[i]);

    // 排序后输出
    sort(priv.begin(), priv.end());
    int sz = priv.size();
    cout << sz << '\n';
    for (int i = 0; i < sz; ++i) {
        cout << priv[i];
        if (i != sz - 1)
            cout << ' ';
    }
    cout << '\n';
}

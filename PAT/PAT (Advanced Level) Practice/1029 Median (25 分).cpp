#include <iostream>

using namespace std;

long int arr[200005];

int main() {
    // 关闭流同步，否则最后一个测试点会超时
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    int n1, n2, cur1 = 0, cur2 = 0, mid, ans;

    cin >> n1;
    for (int i = 0; i < n1; ++i)
        cin >> arr[i];

    cin >> n2;
    mid = (n1 + n2 + 1) / 2;

    while (cur1 + cur2 < mid and cur2 < n2) {  // 在线处理第二个数组
        int t;
        cin >> t;
        while (cur1 < n1 and cur1 + cur2 < mid and arr[cur1] <= t)
            ans = arr[cur1++];
        if (cur1 + ++cur2 <= mid) ans = t;
    }

    while (cur1 + cur2 < mid)
        ans = arr[cur1++];

    cout << ans;
}
#include <iostream>
#include <algorithm>

using namespace std;

int arr[10010];

int main() {
    int n;
    cin >> n;

    int left = 0, right = n - 1, sum = -1, nowSum = 0, nowLeft = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        nowSum += arr[i];

        if (nowSum < 0) {
            nowSum = 0;
            nowLeft = i + 1;
        }
        else if (nowSum > sum) {
            sum = nowSum;
            left = nowLeft;
            right = i;
        }
    }

    cout << max(sum, 0) << " " << arr[left] << " " << arr[right];
}
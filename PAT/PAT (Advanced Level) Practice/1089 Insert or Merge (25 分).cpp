#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n, original[100], intermediate[100], i, j;

    // 读入数组
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> original[i];
    for (i = 0; i < n; i++)
        cin >> intermediate[i];

    // 找到一个有序前缀
    for (i = 0; i < n - 1 and intermediate[i] <= intermediate[i + 1]; i++)
        ;
    // 判断之后的序列是否相同
    for (j = i + 1; original[j] == intermediate[j] and j < n; j++)
        ;

    if (j == n) {
        cout << "Insertion Sort" << endl;
        sort(original, original + i + 2);
    } else {
        cout << "Merge Sort" << endl;
        int len = 1, different = 1;
        while (different) {
            different = 0;
            // 判断是否到达了中间结果
            for (i = 0; i < n; i++) {
                if (original[i] != intermediate[i])
                    different = 1;
            }
            len = len * 2;
            for (i = 0; i < n / len; i++)
                sort(original + i * len, original + (i + 1) * len);
            sort(original + n / len * len, original + n);
        }
    }

    for (j = 0; j < n; j++) {
        if (j != 0)
            printf(" ");
        printf("%d", original[j]);
    }
}
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_C = 210;  // 最大颜色数
const int MAX_N = 10010;  // 最大L

int hashTable[MAX_C];  // 将喜欢的颜色序列映射为递增序列，不喜欢的颜色映射为-1
int a[MAX_N], dp[MAX_N];

int main() {
    int n, m, x;
    scanf("%d%d", &n, &m);
    memset(hashTable, -1, sizeof(hashTable));

    for (int i = 0; i < m; ++i) {
        scanf("%d", &x);
        hashTable[x] = i;  // 将喜欢的颜色按顺序映射到递增序列0 1 2 ...
    }

    int l, num = 0;  // num存放颜色序列中喜欢的颜色的总数（暂不考虑顺序）
    scanf("%d", &l);
    for (int i = 0; i < l; ++i) {
        scanf("%d", &x);
        if (hashTable[x] >= 0) a[num++] = hashTable[x];
    }

    // 以下全部为LIS问题的模板
    int ans = -1;
    for (int i = 0; i < num; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (a[j] <= a[i] and dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
        ans = max(ans, dp[i]);
    }

    printf("%d\n", ans);
}
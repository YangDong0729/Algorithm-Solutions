#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    const int M = 100005;
    int dist[M], pre_sum[M] = {};

    int n, sum;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &dist[i]);
        pre_sum[i + 1] = pre_sum[i] + dist[i];
    }
    sum = pre_sum[n + 1];

    int m;
    scanf("%d", &m);

    while (m--) {
        int b1, b2;
        scanf("%d%d", &b1, &b2);
        if (b2 < b1)
            swap(b1, b2);

        int s1 = pre_sum[b2] - pre_sum[b1];
        int s2 = sum - s1;
        printf("%d", min(s1, s2));

        if (m)
            putchar('\n');
    }
}
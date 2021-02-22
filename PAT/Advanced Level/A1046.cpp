#include <iostream>
#include <cstdio>

using namespace std;

int dis[100005];

int main() {
    dis[1] = 0;

    int t, n, sum = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &t);
        sum += t;
        dis[i + 1] = dis[i] + t;
    }

    int m;
    scanf("%d", &m);

    while (m--) {
        int b1, b2;
        scanf("%d%d", &b1, &b2);
        if (b2 < b1) swap(b1, b2);

        int s1 = dis[b2] - dis[b1];
        int s2 = sum - s1;
        printf("%d", min(s1, s2));

        if (m) putchar('\n');
    }
}
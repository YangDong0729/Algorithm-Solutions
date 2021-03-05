#include <cstdio>

int main() {
    constexpr auto SIZE = 10005;
    double poly[SIZE] = {};

    for (int i = 0; i < 2; ++i) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            int p;
            double q;
            scanf("%d %lf", &p, &q);
            poly[p] += q;
        }
    }

    int cnt = 0;
    for (int i = 0; i < SIZE; ++i)
        if (poly[i] != 0)
            ++cnt;
    printf("%d", cnt);

    if (cnt)
        for (int i = SIZE - 1; i >= 0; --i)
            if (poly[i] != 0)
                printf(" %d %.1f", i, poly[i]);
}
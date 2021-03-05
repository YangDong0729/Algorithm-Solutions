#include <cstdio>

int main() {
    const int SIZE = 2005;
    double poly[SIZE] = {}, result[SIZE] = {};

    for (int i = 0; i < 2; ++i) {
        int n;
        scanf("%d", &n);
        for (int j = 0; j < n; ++j) {
            int exp;
            double cof;
            scanf("%d %lf", &exp, &cof);

            if (i == 0)
                poly[exp] = cof;
            else
                for (int k = 0; k <= 1000; ++k)
                    result[k + exp] += cof * poly[k];
        }
    }

    int cnt = 0;
    for (int i = 0; i < SIZE; ++i)
        if (result[i] != 0)
            ++cnt;
    printf("%d", cnt);

    if (cnt)
        for (int i = SIZE - 1; i >= 0; --i)
            if (result[i] != 0)
                printf(" %d %.1f", i, result[i]);
}
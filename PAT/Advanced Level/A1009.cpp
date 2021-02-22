#include <cstdio>

using namespace std;

const int SIZE = 2005;
double arr[SIZE], res[SIZE];

int main() {
    for (int i = 0; i < 2; ++i) {
        int n;
        scanf("%d", &n);
        for (int j = 0; j < n; ++j) {
            int exp;
            double cof;
            scanf("%d %lf", &exp, &cof);

            if (i == 0) arr[exp] = cof;
            else
                for (int k = 0; k <= 1000; ++k)
                    res[k + exp] += cof * arr[k];
        }
    }

    int cnt = 0;
    for (int i = 0; i < SIZE; ++i)
        if (res[i] != 0) ++cnt;
    printf("%d", cnt);

    if (cnt)
        for (int i = SIZE - 1; i >= 0; --i)
            if (res[i] != 0) printf(" %d %.1f", i, res[i]);
}
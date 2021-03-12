#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using namespace std;

int ac[100005], ap[100005];

int main() {
    int c, p, sum = 0;

    scanf("%d", &c);
    for (int i = 0; i < c; ++i)
        scanf("%d", &ac[i]);
    sort(ac, ac + c);
    scanf("%d", &p);
    for (int i = 0; i < p; ++i)
        scanf("%d", &ap[i]);
    sort(ap, ap + p);

    for (int i = c - 1, j = p - 1;
        i >= 0 and j >= 0 and ac[i] > 0 and ap[j] > 0; --i, --j)
        sum += ac[i] * ap[j];
    for (int i = 0, j = 0;
        i < c and j < p and ac[i] < 0 and ap[j] < 0; ++i, ++j)
        sum += ac[i] * ap[j];

    printf("%d", sum);
}
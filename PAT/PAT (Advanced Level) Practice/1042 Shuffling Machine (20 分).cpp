#include <cstdio>

int main() {
    int result[60], tmp[60], order[60];
    char color[] = {'S', 'H', 'C', 'D', 'J'};

    int t;
    scanf("%d", &t);

    for (int i = 1; i <= 54; ++i)
        result[i] = i;
    for (int i = 1; i <= 54; ++i)
        scanf("%d", &order[i]);

    while (t--) {
        for (int i = 1; i <= 54; ++i)
            tmp[order[i]] = result[i];
        for (int i = 1; i <= 54; ++i)
            result[i] = tmp[i];
    }

    for (int i = 1; i <= 54; ++i) {
        printf("%c%d", color[(result[i] - 1) / 13], (result[i] - 1) % 13 + 1);
        if (i != 54) putchar(' ');
    }
}
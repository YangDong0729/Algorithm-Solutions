#include <cstdio>

int a1[60], a2[60], b[60];
char mp[] = { 'S', 'H', 'C', 'D', 'J' };

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 1; i <= 54; ++i)
        a1[i] = i;  // ��ʼ������
    for (int i = 1; i <= 54; ++i)
        scanf("%d", &b[i]);

    while (t--) {
        for (int i = 1; i <= 54; ++i)
            a2[b[i]] = a1[i];  // a2 ��Ϊ������
        for (int i = 1; i <= 54; ++i)
            a1[i] = a2[i];  // ���ƻ� a1
    }

    for (int i = 1; i <= 54; ++i) {
        printf("%c%d", mp[(a1[i] - 1) / 13], (a1[i] - 1) % 13 + 1);
        if (i != 54) putchar(' ');
    }
}
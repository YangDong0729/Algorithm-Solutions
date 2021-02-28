#include <stdio.h>

#define MAXN 100

void Shift(int Array[], int N);

int main() {
    int Number[MAXN], N, M;
    int i;

    scanf("%d%d", &N, &M);
    for (i = 0; i < N; i++)
        scanf("%d", &Number[i]);
    M %= N; /* 当M大于等于N时转化成等价的小于N的数　*/
    for (i = 0; i < M; i++)
        Shift(Number, N);       /* N个元素循环位移1位 */
    for (i = 0; i < N - 1; i++) /* 打印输出 */
        printf("%d ", Number[i]);
    printf("%d\n", Number[N - 1]);
    return 0;
}

void Shift(int Array[], int N) {
    int i, ArrayHead;

    ArrayHead = Array[0];
    for (i = 0; i < N - 1; i++) /* N个元素循环位移1位 */
        Array[i] = Array[i + 1];
    Array[N - 1] = ArrayHead;
}

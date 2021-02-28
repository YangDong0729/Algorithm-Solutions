#include <stdio.h>

#define MAXN 100
#define Swap(a, b) a ^= b, b ^= a, a ^= b;
/* 通过连续三次异或运算交换a与b */

void LeftShift(int Array[], int N, int M);

int main() {
    int Number[MAXN], N, M;
    int i;

    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++)
        scanf("%d", &Number[i]);
    M %= N;                  /* 当M大于等于N时转化成等价的小于N的数 */
    LeftShift(Number, N, M); /* 循环左移M位　*/
    printf("%d", Number[0]); /* 打印输出 */
    for (i = 1; i < N; i++)
        printf(" %d", Number[i]);
    printf("\n");

    return 0;
}

void LeftShift(int Array[], int N, int M) {
    int i, j;

    if (M > 0 && M < N) {
        for (i = 0, j = N - 1; i < j; i++, j--) /* 逆转N个数据 */
            Swap(Array[i], Array[j]);
        for (i = 0, j = N - M - 1; i < j; i++, j--) /* 逆转前N-M个数据 */
            Swap(Array[i], Array[j]);
        for (i = N - M, j = N - 1; i < j; i++, j--) /* 逆转后M个数据 */
            Swap(Array[i], Array[j]);
    }
}

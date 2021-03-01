#include <stdio.h>

int main() {
    int A, N, K, S, i;

    scanf("%d %d", &A, &N);
    if (!N) { /* 处理N为0时的特殊情况 */
        printf("0\n");
        return 0;
    }
    S = K = A; /* 初始化K和总和S */
    for (i = 1; i < N; i++) {
        K = K * 10 + A; /* 计算下一个数列项 */
        S += K;
    }
    printf("%d\n", S);

    return 0;
}

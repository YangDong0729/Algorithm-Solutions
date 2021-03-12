#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2, sqr = sqrt(n); i <= sqr; ++i)
        if (n % i == 0) return false;
    return true;
}

int num[111];

int main() {
    int n, radix;
    while (scanf("%d", &n) != EOF) {
        if (n < 0) break;  // n 是负数时退出循环
        scanf("%d", &radix);

        if (not isPrime(n))  // n 不是素数，输出 No，结束
            printf("No\n");
        else {
            int len = 0;

            do {  // 转换为raidx进制，同时逆序
                num[len++] = n % radix;
                n /= radix;
            } while (n != 0);

            for (int i = 0; i < len; ++i)  // 计算这个数在十进制下的值
                n = n * radix + num[i];

            if (isPrime(n)) printf("Yes\n");
            else printf("No\n");
        }
    }
}
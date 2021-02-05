#include <cstdio>

int main() {
    int t;
    scanf("%d", &t);

    long long a, b, c, sum;

    for (int i = 1; i <= t; ++i) {
        scanf("%lld%lld%lld", &a, &b, &c);

        sum = a + b;

        if (a > 0 && b > 0 && sum < 0) {  // 正溢出
            printf("Case #%d: true\n", i);
        }
        else if (a < 0 && b < 0 && sum >= 0) {  // 负溢出
            printf("Case #%d: false\n", i);
        }
        else if (sum > c) {
            printf("Case #%d: true\n", i);
        }
        else {
            printf("Case #%d: false\n", i);
        }
    }
}
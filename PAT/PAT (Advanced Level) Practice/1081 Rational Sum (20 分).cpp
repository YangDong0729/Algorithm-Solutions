#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

struct fraction {
    int up, down;
};

fraction reduction(fraction &result) {
    int d = gcd(abs(result.up), abs(result.down));
    result.up /= d;
    result.down /= d;
    return result;
}

fraction add(fraction &f1, fraction &f2) {
    fraction result;
    result.up = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

int main() {
    int n;
    scanf("%d", &n);
    fraction sum{0, 1}, temp;
    for (int i = 0; i < n; ++i) {
        scanf("%d/%d", &temp.up, &temp.down);
        sum = add(sum, temp);
    }
    if (sum.down == 1)
        printf("%d\n", sum.up);        // 整数
    else if (abs(sum.up) > sum.down) { // 假分数
        printf("%d %d/%d\n", sum.up / sum.down, abs(sum.up) % sum.down, sum.down);
    } else { // 真分数
        printf("%d/%d\n", sum.up, sum.down);
    }
}
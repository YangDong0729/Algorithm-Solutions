#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;
char n1[15], n2[15];

inline int to_num(char a) { // 把0-9和a-z转换成对应的数字
    if (isdigit(a))
        return a - '0';
    else
        return a - 'a' + 10;
}

ll convert(char x[], int rad) { // 把rad进制的x转换成10进制
    ll val = 0;
    for (int i = 0, len = strlen(x); i < len; ++i) {
        val = val * rad + to_num(x[i]);
        if (val <= 0)
            return -1; // 溢出返回-1
    }
    return val;
}

ll b_search(char x[], ll target) { // 二分答案 x：未知进制的数，t：已知进制数的十进制值
    int len = strlen(x);

    ll left = ll(to_num(*max_element(x, x + len))) + 1; // 左边界是x中最大数字+1
    // ll right = target < 36 ? target + 1 : target;
    ll right = target + 1, mid; // 右边界是t+1

    while (left <= right) {
        mid = (left + right) / 2;
        ll val = convert(x, mid);

        if (val < 0 or val > target)
            right = mid - 1;
        else if (val < target)
            left = mid + 1;
        else if (val == target)
            return mid;
    }
    return -1;
}

int main() {
    int tag, rad;
    scanf("%s %s %d %d", n1, n2, &tag, &rad);

    if (tag == 2)
        swap(n1, n2);

    ll v1 = convert(n1, rad);
    ll n2_rad = b_search(n2, v1);

    if (n2_rad == -1)
        printf("Impossible");
    else
        printf("%lld", n2_rad);
}
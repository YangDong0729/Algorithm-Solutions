#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>

using namespace std;

int a[100005];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] != i) {
            if (i > 0)
                cnt += 2;
            while (a[i] != i) {
                swap(a[i], a[a[i]]);
                ++cnt;
            }
        }
    }

    printf("%d", cnt);
}
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <climits>

using namespace std;

int ans[100005][2];
int diamond[100005];

int main() {
    int n, m;

    scanf("%d %d\n", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", diamond + i);

    int cnt = 0;
    for (int sum = 0, l = 1, r = 0, cost = INT_MAX;;) {
        while (sum < m and r <= n) sum += diamond[++r];
        if (sum < m) break;
        if (cost > sum - m) {
            cnt = 1;
            cost = sum - m;
            ans[0][0] = l;
            ans[0][1] = r;
        } else if (cost == sum - m) {
            ans[cnt][0] = l;
            ans[cnt][1] = r;
            ++cnt;
        }
        do {
            sum -= diamond[l++];
        } while (l <= r and sum - diamond[l] >= m);
    }

    for (int i = 0; i < cnt; ++i)
        printf("%d-%d\n", ans[i][0], ans[i][1]);
}
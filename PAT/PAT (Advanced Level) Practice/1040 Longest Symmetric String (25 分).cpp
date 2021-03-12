﻿#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N = 1010;

char s[MAX_N];
int dp[MAX_N][MAX_N];  // dp[x][y] = 1：s在[x, y]区间内是对称的。

int main() {
    cin.getline(s, MAX_N);
    int len = strlen(s), ans = 1;

    // 边界
    for (int i = 0; i < len; ++i) {
        dp[i][i] = 1;  // 所有长度为1的子串
        if (i < len - 1) {
            if (s[i] == s[i + 1]) {  // 所有长度为2的子串
                dp[i][i + 1] = 1;
                ans = 2;
            }
        }
    }

    // 状态转移方程
    for (int l = 3; l <= len; ++l) {  // 枚举子串的长度（从3开始）
        for (int i = 0; i + l - 1 < len; ++i) {  // 枚举子串的起始端点
            int j = i + l - 1;  // 子串的右端点
            if (s[i] == s[j] and dp[i + 1][j - 1] == 1) {
                dp[i][j] = 1;
                ans = l;
            }
        }
    }

    printf("%d\n", ans);
}
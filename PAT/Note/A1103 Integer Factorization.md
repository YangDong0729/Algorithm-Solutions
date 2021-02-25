# 题目详情
==The $K-P$ factorization of a positive integer $N$ is to write $N$ as the sum of the $P$-th power of $K$ positive integers==. You are supposed to write a program to find the $K-P$ factorization of $N$ for any positive integers $N$, $K$ and $P$.

### Input Specification:

Each input file contains one test case which gives in a line the three positive integers $N$ ($\le 400$), $K$ ($\le N$) and $P$ ($1 < P\le 7$). The numbers in a line are separated by a space.

### Output Specification:

For each case, if the solution exists, output in the format:

    N = n[1]^P + ... n[K]^P


where `n[i]` (`i` = 1, ..., `K`) is the `i`\-th factor. All the factors must be printed in non-increasing order.

Note: the solution may not be unique. For example, the 5-2 factorization of 169 has 9 solutions, such as 122+42+22+22+1212^2 + 4^2 + 2^2 + 2^2 + 1^2, or 112+62+22+22+2211^2 + 6^2 + 2^2 + 2^2 + 2^2, or more. ==You must output the one with the maximum sum of the factors==. ==If there is a tie, the largest factor sequence must be chosen==-- sequence { $a_1, a_2, \cdots , a_K$ } is said to be **larger** than { $b_1, b_2, \cdots , b_K$ } if there exists $1\le L\le K$ such that $a_i=b_i$ for $i<L$ and $a_L>b_L$.

If there is no solution, simple output `Impossible`.

### Sample Input 1:

    169 5 2


### Sample Output 1:

    169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2


### Sample Input 2:

    169 167 3


### Sample Output 2:

    Impossible

# 题解

将正整数N表示为K个正整数的P次方，按照底数的大小降序排列，底数可以重复。如果有多种方案，选择底数之和最大的；如果还有多种方案，选择底数序列的字典序最大的。

深搜，但是关键是要从大的数开始搜索，这样一来不会超时，二来自然满足底数降序和字典序最大的条件。

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pow(int x, int p) {
    int ans = 1;

    while (p > 0) {
        if (p & 1) ans *= x;
        x *= x;
        p >>= 1;
    }

    return ans;
}

int n, k, p, max_num, max_sum;
vector<int> ans, now;

void dfs(int num, int cnt, int sum, int sum_p) {
    if (cnt >= k or sum_p >= n) {
        if (cnt == k and sum_p == n and sum > max_sum) {
            ans = now;
            max_sum = sum;
        }
        return;
    }

    for (int i = num; i >= 1 && pow(i, p) * (k - now.size()) + sum_p >= n; --i) {
        now.push_back(i);
        dfs(i, cnt + 1, sum + i, sum_p + pow(i, p));
        now.pop_back();
    }
}

int main() {
    cin >> n >> k >> p;

    // 确定可能的最大值
    while (pow(max_num + 1, p) + k - 1 <= n) ++max_num;

    dfs(max_num, 0, 0, 0);

    if (ans.size() == 0) cout << "Impossible\n";
    else {
        cout << n << " = ";
        for (auto i = ans.begin(); i != ans.end(); ++i) {
            cout << *i << "^" << p;
            if (i + 1 != ans.end()) cout << " + ";
        }
        cout << "\n";
    }
}
```


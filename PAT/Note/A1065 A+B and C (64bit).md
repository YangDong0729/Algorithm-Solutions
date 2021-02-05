==Given three integers $A$, $B$ and $C$ in $[−2^{63},2^{63}]$, you are supposed to tell whether $A+B>C$.==

### Input Specification:
The first line of the input gives the positive number of test cases, $T (≤10)$. Then $T$ test cases follow, each consists of a single line containing three integers $A$, $B$ and $C$, separated by single spaces.
### Output Specification:
For each test case, output in one line `Case #X: true` if $A+B>C$, or `Case #X: false` otherwise, where X is the case number (starting from 1).
### Sample Input:
```
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0
```
### Sample Output:

```
Case #1: false
Case #2: true
Case #3: false
```
# 题解

给出三个数A，B和C，判断A+B和C的大小，A、B和C在$[−2^{63},2^{63}]$内。



关键就是C也在$[−2^{63},2^{63}]$内，所以用long long存储A和B，如果A+B溢出，再根据A和B的符号就可以确定A+B和C的大小关系。



这种方法是有问题的（比如$A+B=2^{63}$，如果$C=2^{63}$，那么$A+B=C$，而`long long`无法表示$2^{63}$，会溢出），但是数据比较弱。

```cpp
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    long long a, b, c, sum;

    for (int i = 1; i <= t; ++i) {
        scanf("%lld%lld%lld", &a, &b, &c);

        sum = a + b;

        if (a > 0 && b > 0 && sum < 0) {
            printf("Case #%d: true\n", i);
        } else if (a < 0 && b < 0 && sum >= 0) {
            printf("Case #%d: false\n", i);
        } else if (sum > c) {
            printf("Case #%d: true\n", i);
        } else {
            printf("Case #%d: false\n", i);
        }
    }
}
```
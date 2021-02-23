# 题目详情

People on Mars count their numbers with base 13:

*   ==Zero on Earth is called "tret" on Mars.==
*   ==The numbers 1 to 12 on Earth is called "jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec" on Mars, respectively.==
*   ==For the next higher digit, Mars people name the 12 numbers as "tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou", respectively.==

For examples, the number 29 on Earth is called "hel mar" on Mars; and "elo nov" on Mars corresponds to 115 on Earth. In order to help communication between people from these two planets, you are supposed to write a program for mutual translation between Earth and Mars number systems.

### Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer $N$ ($< 100$). Then $N$ lines follow, each contains a number in \[0, 169), given either in the form of an Earth number, or that of Mars.

### Output Specification:

For each number, print in a line the corresponding number in the other language.

### Sample Input:

    4
    29
    5
    elo nov
    tam


### Sample Output:

    hel mar
    may
    115
    13

# 题解

### 题意

### 思路

注意如果火星数字的低位是0而高位不是0的话，低位的0是不用输出的。

### 代码

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>

using namespace std;

int main() {
    string int2str[2][13] = { {"tret", "jan", "feb", "mar", "apr", "may", "jun",
                               "jly", "aug", "sep", "oct", "nov", "dec"},
                              {"tret", "tam", "hel", "maa", "huh", "tou", "kes",
                               "hei", "elo", "syy", "lok", "mer", "jou"} };

    unordered_map<string, int> str2int;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 13; ++j) {
            str2int[int2str[i][j]] = i ? 13 * j : j;
        }
    }

    int query;
    cin >> query;
    cin.get();  // 吃掉回车

    string s;
    while (query--) {
        getline(cin, s);

        if (isdigit(s[0])) {
            int num, a, b;

            sscanf(s.c_str(), "%d", &num);

            a = num % 13;
            b = num / 13;

            if (b != 0) {
                cout << int2str[1][b];
                if (a != 0) cout << " ";
            }
            if (a != 0 || b == 0)
                cout << int2str[0][a];

            cout << "\n";
        }
        else {
            int num = 0;
            int blk_loc = s.find(" ");

            if (blk_loc != string::npos)
                num = str2int[s.substr(blk_loc + 1)] +
                str2int[s.substr(0, blk_loc)];
            else
                num = str2int[s];

            cout << num << "\n";
        }
    }
}
```
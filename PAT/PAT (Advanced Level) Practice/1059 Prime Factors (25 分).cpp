#include <iostream>

using namespace std;
#define MAX_N 100000

bool sum_number[MAX_N];  // 合数

int main() {
    int x;
    cin >> x;
    cout << x << "=";
    if (x == 1)
        cout << "1";

    for (int i = 2; i < MAX_N; ++i)  // 欧拉筛
        if (not sum_number[i])
            for (int j = i + i; sum_number[j / i]; j += i)
                sum_number[j] = true;

    bool first = true;
    for (int i = 2; i < MAX_N and x != 1; ++i) {
        if (!sum_number[i]) {
            int cnt = 0;
            while (x % i == 0) {
                x /= i;
                ++cnt;
            }
            if (cnt > 0) {
                if (first)
                    first = false;
                else
                    cout << '*';
                cout << i;
                if (cnt > 1)
                    cout << '^' << cnt;
            }
        }
    }
    if (x != 1)
        cout << '*' << x;
}

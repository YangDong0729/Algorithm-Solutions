#include <iostream>

using namespace std;

char bt[5] = "WTL";

int main() {
    char pr[5];
    double sum = 1;

    for (int i = 0; i < 3; ++i) {
        double mx = 0;
        for (int j = 0; j < 3; ++j) {
            double tmp;
            cin >> tmp;
            if (mx < tmp) {
                mx = tmp;
                pr[i] = bt[j];
            }
        }
        sum *= mx;
    }

    sum = (sum * 0.65 - 1) * 2;
    for (int i = 0; i < 3; ++i)
        cout << pr[i] << " ";

    printf("%.2f", sum);
}
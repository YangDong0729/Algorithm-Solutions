#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> prices(N);
    for (int i = 0; i < N; i++) {
        cin >> prices[i];
    }

    int ways = 0;
    for (int len = 1; len <= N; len++) {
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += prices[i];
        }
        if (sum <= M) {
            ways++;
            // for (int i = 0; i < len; i++) {
            //     cout << prices[i] << " ";
            // }
            // cout << "\n";
        }
        for (int i = len; i < N; i++) {
            sum -= prices[i - len];
            sum += prices[i];
            if (sum <= M) {
                ways++;
                // for (int j = i - len + 1; j <= i; j++) {
                //     cout << prices[j] << " ";
                // }
                // cout << "\n";
            }
        }
    }

    cout << ways;
}
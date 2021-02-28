#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int N, M;
    cin >> N >> M;
    M %= N;

    vector<int> Number(N);
    for (int i = 0; i < N; i++) {
        cin >> Number[i];
    }

    int Loop = gcd(M, N);
    for (int i = 0; i < Loop; i++) {
        int head = i, tmp = Number[i];
        do {
            int nxt = (i - M + N) % N;
            swap(Number[nxt], tmp);
            i = nxt;
        } while (i != head);
    }

    for (int i = 0; i < N; ++i) {
        cout << Number[i] << (i == N - 1 ? "\n" : " ");
    }
}

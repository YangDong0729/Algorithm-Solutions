#include <iostream>
#include <stack>

using namespace std;

int main() {
    int M, N, K;
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        int nxt = 1;
        stack<int> stk;
        bool legal = true;
        for (int j = 0; j < N; j++) {
            int a;
            cin >> a;
            if (legal) {
                if (!stk.empty() && stk.top() == a) {
                    stk.pop();
                } else {
                    while ((stk.empty() || stk.top() != a) && stk.size() < M) {
                        stk.push(nxt++);
                    }
                    if (stk.empty() || stk.top() != a) {
                        cout << "NO\n";
                        legal = false;
                        continue;
                    } else {
                        stk.pop();
                    }
                }
            }
        }
        if (legal)
            cout << "YES\n";
    }
}
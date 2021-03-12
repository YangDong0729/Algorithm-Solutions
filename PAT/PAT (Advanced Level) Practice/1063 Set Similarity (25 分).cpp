#include <iomanip>
#include <iostream>
#include <set>

using namespace std;

set<int> sets[55];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        for (int j = 0; j < t; ++j) {
            int num;
            cin >> num;
            sets[i].insert(num);
        }
    }

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int nc = 0, nt = 0, a, b;

        cin >> a >> b;
        for (auto& e : sets[a]) {
            if (sets[b].count(e))
                ++nc;
            else
                ++nt;
        }
        nt += sets[b].size();

        cout << fixed << setprecision(1) << 100.0 * nc / nt << "%\n";
    }
}
#include <iostream>
#include <set>

using namespace std;

int cir[205];
set<int> graph[205];

int main() {
    int n, m, a, b, k;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    cin >> k;
    for (int i = 0; i < k; ++i) {
        int p;
        bool is_visited[205] = {}, hc;

        cin >> p;
        for (int j = 0; j < p; ++j)
            cin >> cir[j];
        hc = false;
        if (p == n + 1) {
            hc = true;
            if (cir[0] != cir[p - 1])
                hc = false;
            for (int j = 0; j < p - 1; ++j) {
                if (graph[cir[j]].count(cir[j + 1]) == 0)
                    hc = false;
                if (is_visited[cir[j]])
                    hc = false;
                else
                    is_visited[cir[j]] = true;
                if (!hc)
                    break;
            }
        }
        cout << (hc ? "YES\n" : "NO\n");
    }
}
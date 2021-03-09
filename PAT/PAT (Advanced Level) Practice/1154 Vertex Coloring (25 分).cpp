#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int color[10004];
unordered_set<int> color_set;
vector<pair<int, int>> edge;

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        edge.push_back({a, b});
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; ++i) {
        color_set.clear();
        for (int j = 0; j < n; ++j) {
            cin >> color[j];
            color_set.insert(color[j]);
        }
        bool flag = true;
        for (auto &edge : edge) {
            if (color[edge.first] == color[edge.second]) {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << color_set.size() << "-coloring\n";
        else
            cout << "No\n";
    }
}
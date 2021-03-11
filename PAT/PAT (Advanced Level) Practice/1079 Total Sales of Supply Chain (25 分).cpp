#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct {
    double p, cnt;
    vector<int> children;
} graph[100005];

int main() {
    int n, k, c;
    double r, sum = 0;

    cin >> n >> graph[0].p >> r;
    r = 1 + r / 100;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        if (k == 0)
            cin >> graph[i].cnt;
        else
            for (int j = 0; j < k; ++j) {
                cin >> c;
                graph[i].children.push_back(c);
            }
    }

    queue<int> q;
    q.push(0);
    while (not q.empty()) {
        int top = q.front();
        q.pop();
        auto &children = graph[top].children;
        if (children.size() == 0)
            sum += graph[top].cnt * graph[top].p;
        else
            for (int i = 0; i < children.size(); ++i) {
                graph[children[i]].p = graph[top].p * r;
                q.push(children[i]);
            }
    }

    printf("%.1f", sum);
}
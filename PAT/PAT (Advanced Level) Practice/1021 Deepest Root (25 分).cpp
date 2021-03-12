#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int maxH = 0;
bool visit[10010];
set<int> sub, ans;
vector<int> graph[10010];

void dfs(int u, int height) {
    visit[u] = true;

    if (height > maxH) {  // 如果获得了更大的树高
        sub.clear();
        sub.insert(u);
        maxH = height;
    }
    else if (height == maxH)
        sub.insert(u);

    for (int i = 0; i < graph[u].size(); ++i)
        if (!visit[graph[u][i]]) dfs(graph[u][i], height + 1);
}

int main() {
    int a, b, n;
    scanf("%d", &n);

    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int block = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visit[i]) {
            ++block;
            dfs(i, 1);
        }
    }

    if (block > 1) printf("Error: %d components\n", block);
    else {
        ans = sub;
        fill_n(visit + 1, n, false);
        dfs(*sub.begin(), 1);
        for (auto& e : sub) ans.insert(e);
        for (auto& e : ans) printf("%d\n", e);
    }
}
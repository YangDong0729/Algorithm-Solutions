#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 1111;

vector<int> adj[N];  // 邻接表
bool is_visited[N];         // 访问标志
int deleteP;         // 需要删除的顶点

void dfs(int v) {
    is_visited[v] = true;
    for (int i = 0; i < adj[v].size(); ++i)
        if (not is_visited[adj[v][i]] and adj[v][i] != deleteP)
            dfs(adj[v][i]);
}

int n, m, k;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int q = 0; q < k; ++q) {
        scanf("%d", &deleteP);

        fill_n(is_visited, N, false);

        int block = 0;
        for (int i = 1; i <= n; ++i) {
            if (i != deleteP and not is_visited[i]) {
                dfs(i);
                ++block;
            }
        }

        printf("%d\n", block - 1);
    }
}
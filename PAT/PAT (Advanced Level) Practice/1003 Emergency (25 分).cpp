#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define MAX_V 505
#define INF -1

struct edge {
    int to, weight;
    bool operator>(const edge& x) const {
        return weight > x.weight;
    }
};

bool visited[MAX_V];
vector<edge> graph[MAX_V];
int dist[MAX_V], path_cnt[MAX_V], team_sum[MAX_V], team_num[MAX_V];

void dijkstra(int start) {
    fill_n(dist, MAX_V, INF);

    dist[start] = 0;

    priority_queue<edge, vector<edge>, greater<edge>> pq;
    pq.push({ start, 0 });

    path_cnt[start] = 1;
    team_sum[start] = team_num[start];

    while (not pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int u = top.to;
        int uDist = top.weight;

        visited[u] = true;

        if (dist[u] < uDist) continue;

        for (auto& e : graph[u]) {
            int v = e.to;
            int uvWeight = e.weight;

            if (not visited[v] and (dist[v] == INF or dist[v] > dist[u] + uvWeight)) {
                dist[v] = dist[u] + uvWeight;
                pq.push({ v, dist[v] });
                path_cnt[v] = path_cnt[u];
                team_sum[v] = team_num[v] + team_sum[u];
            }
            else if (dist[v] == dist[u] + uvWeight) {
                path_cnt[v] += path_cnt[u];
                if (team_sum[v] < team_num[v] + team_sum[u])
                    team_sum[v] = team_num[v] + team_sum[u];
            }
        }
    }
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
int main() {
    int n, m, c1, c2;
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; ++i) cin >> team_num[i];
    for (int i = 0; i < m; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        graph[a].push_back({ b, l });
        graph[b].push_back({ a, l });
    }
    dijkstra(c1);
    cout << path_cnt[c2] << " " << team_sum[c2];
}
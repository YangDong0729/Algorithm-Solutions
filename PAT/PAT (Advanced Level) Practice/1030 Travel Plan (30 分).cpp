#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 505;
const int INF = -1;

struct edge {
    int to, weight, cost;

    bool operator>(const edge& e) const {
        return weight > e.weight;
    }
};

bool visit[MAX_N];
vector<edge> graph[MAX_N];
int dist[MAX_N], pre[MAX_N], cost[MAX_N];

void dijkstra(int s) {
    fill_n(dist, MAX_N, INF);

    dist[s] = 0;
    cost[s] = 0;
    pre[s] = INF;

    priority_queue<edge, vector<edge>, greater<edge>> pq;
    pq.push({ s, 0, 0 });

    while (not pq.empty()) {
        edge top = pq.top();
        pq.pop();

        int u = top.to, uDist = top.weight;

        visit[u] = true;

        if (dist[u] < uDist) continue;

        for (auto& e : graph[u]) {
            int v = e.to, uvWeight = e.weight, uvCost = e.cost;

            if (not visit[v] and (dist[v] == INF or dist[v] > dist[u] + uvWeight)) {
                pre[v] = u;

                dist[v] = dist[u] + uvWeight;
                cost[v] = cost[u] + uvCost;

                pq.push({ v, dist[v], cost[v] });
            }
            else if (dist[v] == dist[u] + uvWeight and cost[v] > cost[u] + uvCost) {
                pre[v] = u;
                cost[v] = cost[u] + uvCost;
            }
        }
    }
}

void printPath(int d) {
    if (pre[d] != INF) printPath(pre[d]);
    cout << (pre[d] == INF ? "" : " ") << d;
}

int main() {
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    for (int i = 0; i < m; ++i) {
        int c1, c2, weight, cost;
        cin >> c1 >> c2 >> weight >> cost;
        graph[c1].push_back({ c2, weight, cost });
        graph[c2].push_back({ c1, weight, cost });
    }

    dijkstra(s);
    printPath(d);
    cout << " " << dist[d] << " " << cost[d];
}
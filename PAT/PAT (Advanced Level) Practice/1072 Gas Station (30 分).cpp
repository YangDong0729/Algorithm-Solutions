#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

const int INF = -1;
const int MAX_V = 1100;

int n, m, k, ds;

struct Node {
    int dist;
    bool visit;
    vector<pair<int, int>> adj;
} node[MAX_V];

void dijkstra(int s) {
    for (int i = 0; i < MAX_V; ++i) {
        node[i].dist = INF;
        node[i].visit = false;
    }

    node[s].dist = 0;

    using pair = pair<int, int>;
    priority_queue<pair, vector<pair>, greater<pair>> pq;
    pq.push({ 0, s });

    while (not pq.empty()) {
        int u = pq.top().second, uDist = pq.top().first;
        pq.pop();

        node[u].visit = true;

        if (node[u].dist < uDist)
            continue;
        for (auto& e : node[u].adj) {
            int v = e.second, uvWeight = e.first;

            if (not node[v].visit 
                and (node[v].dist == INF or node[v].dist > node[u].dist + uvWeight)) {
                node[v].dist = node[u].dist + uvWeight;
                pq.push({ node[v].dist, v });
            }
        }
    }
}

int getId(string& s) {  // 把加油站和住宅统一编号
    if (s[0] == 'G') return stoi(s.substr(1)) + n;
    else return stoi(s);
}

int main() {
    scanf("%d%d%d%d", &n, &m, &k, &ds);

    for (int i = 0; i < k; ++i) {
        int d, p1, p2;
        string sp1, sp2;
        cin >> sp1 >> sp2 >> d;

        p1 = getId(sp1);
        p2 = getId(sp2);

        node[p1].adj.push_back({ d, p2 });
        node[p2].adj.push_back({ d, p1 });
    }

    int station_dist_sum = INF, station_min_dist = 0, station_id = INF;

    for (int i = 1; i <= m; ++i) {
        dijkstra(n + i); // 计算这个加油站到所有住宅的最短路径

        bool ok = true;

        for (int j = 1; j <= n; ++j) { // 判断能否覆盖所有住宅
            if (node[j].dist > ds) {
                ok = false;
                break;
            }
        }

        if (ok) {
            int dist_sum = node[1].dist;
            int min_dist = node[1].dist;

            for (int j = 2; j <= n; ++j) { // 计算到所有住宅的距离之和和其中的最短距离
                dist_sum += node[j].dist;
                if (min_dist > node[j].dist) min_dist = node[j].dist;
            }

            if (station_min_dist < min_dist 
                or (station_min_dist == min_dist and station_dist_sum > dist_sum)) { // 更新最短距离最大的加油站位置
                station_id = i;
                station_dist_sum = dist_sum;
                station_min_dist = min_dist;
            }
        }
    }

    if (station_id != INF)
        printf("G%d\n%.1f %.1f", station_id, double(station_min_dist), double(station_dist_sum) / n);
    else
        printf("No Solution");
}
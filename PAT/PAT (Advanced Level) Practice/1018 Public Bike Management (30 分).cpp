#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_V 505
#define INF 0x3fffffff

struct node {
    int v, weight;

    bool operator>(const node& e) const {
        return weight > e.weight;
    }
};

bool visit[MAX_V];  // 访问标志
vector<int> pre[MAX_V];  // 前驱
vector<node> graph[MAX_V];  // 邻接表
int dist[MAX_V], bikeCnt[MAX_V];  // 从起点到每个点的最短距离 每个车站的车的数量

void dijkstra(int start) {
    fill_n(dist, MAX_V, INF);

    dist[start] = 0;
    pre[start].push_back(INF);

    priority_queue<node, vector<node>, greater<node>> pq;
    pq.push({ start, 0 });

    while (not pq.empty()) {
        node top = pq.top();
        pq.pop();

        int u = top.v, uDist = top.weight;

        visit[u] = true;

        if (dist[u] < uDist) continue;

        for (auto& e : graph[u]) {
            int v = e.v, uvWeight = e.weight;

            if (not visit[v] and (dist[v] == INF or dist[v] > dist[u] + uvWeight)) {
                dist[v] = dist[u] + uvWeight;
                pq.push({ v, dist[v] });

                pre[v].clear();
                pre[v].push_back(u);
            }
            else if (dist[v] == dist[u] + uvWeight) {
                pre[v].push_back(u);
            }
        }
    }
}

int perfectNum;  // 完美条件的数量
vector<int> path, tempPath;
int minSend = INF, minTakeBack = INF;  // 需要从节点0发出的车的数量 需要带回节点0的车的数量

void dfs(int end) {
    if (end == INF) {  // 深搜到了一条完整的路径，开始计算花费
        int send = 0, takeBack = 0;
        for (int i = tempPath.size() - 2; i >= 0; --i) {  // 从经过的第一个**车站**开始到终点
            int p = tempPath[i];

            if (bikeCnt[p] > perfectNum) {
                takeBack += bikeCnt[p] - perfectNum;
            }
            else if (bikeCnt[p] < perfectNum) {
                if (takeBack >= perfectNum - bikeCnt[p])
                    takeBack -= perfectNum - bikeCnt[p];
                else {
                    send += perfectNum - bikeCnt[p] - takeBack;
                    takeBack = 0;
                }
            }
        }

        if (send < minSend or (send == minSend and takeBack < minTakeBack)) {
            path = tempPath;
            reverse(path.begin(), path.end());

            minSend = send;
            minTakeBack = takeBack;
        }

        return;
    }

    tempPath.push_back(end);
    for (auto e : pre[end]) dfs(e);
    tempPath.pop_back();
}

int main() {
    int c_max, n, sp, m;  // 最大容量 站台的数量 需要处理的车站的编号 路的数量
    cin >> c_max >> n >> sp >> m;
    perfectNum = c_max / 2;

    for (int i = 1; i <= n; ++i)
        cin >> bikeCnt[i];

    for (int i = 0; i < m; ++i) {
        int si, sj, t;
        cin >> si >> sj >> t;

        graph[si].push_back({ sj, t });
        graph[sj].push_back({ si, t });
    }

    dijkstra(0);
    dfs(sp);

    cout << minSend << " ";
    for (auto i = path.begin(); i != path.end(); ++i) {
        cout << *i;
        if (i + 1 != path.end()) cout << "->";
    }
    cout << " " << minTakeBack;
}
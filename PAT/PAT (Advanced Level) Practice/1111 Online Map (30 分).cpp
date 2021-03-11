#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF -1
#define MAX_V 505

struct Node {
    int dist;                             // 与源点的距离
    bool visit;                           // 访问
    vector<int> pre;                      // 前驱
    vector<pair<int, array<int, 2>>> adj; // 邻接的节点 {距离, 时间}
} graph[MAX_V];                           // 邻接表

int flag = 0;
array<int, 2> weight[MAX_V][MAX_V]; // 邻接矩阵表示的 {距离, 时间}

void dijkstra(int start) {
    for (int i = 0; i < MAX_V; ++i) {
        graph[i].dist = INF;
        graph[i].pre.clear();
        graph[i].visit = false;
    }

    using pair = pair<int, int>;
    priority_queue<pair, vector<pair>, greater<pair>> pq;

    graph[start].dist = 0;
    pq.push({0, start});

    while (not pq.empty()) {
        int uIdx = pq.top().second;
        int uDist = pq.top().first;
        auto &u = graph[uIdx];
        pq.pop();

        u.visit = true;

        if (u.dist < uDist)
            continue;

        for (auto &e : u.adj) {
            auto &v = graph[e.first];
            int uvWeight = e.second[flag];

            if (not v.visit and (v.dist == INF or v.dist > u.dist + uvWeight)) {
                v.dist = u.dist + uvWeight;
                pq.push({v.dist, e.first});

                v.pre.clear();
                v.pre.push_back(uIdx);
            } else if (v.dist == u.dist + uvWeight)
                v.pre.push_back(uIdx);
        }
    }
}

int minSecondStandard = INF;
vector<int> shortestPath[2], tmpPath;

void dfs(int end, int secondStandard) {
    tmpPath.push_back(end);
    if (graph[end].pre.empty() and (minSecondStandard == INF or minSecondStandard > secondStandard)) {
        minSecondStandard = secondStandard;
        shortestPath[flag] = tmpPath;
    }
    for (auto e : graph[end].pre)
        dfs(e, secondStandard + (flag == 0 ? weight[e][end][1] : 1));
    tmpPath.pop_back();
}

void printPath(vector<int> &path) {
    for (auto i = path.rbegin(); i != path.rend(); ++i) {
        cout << *i;
        if (i + 1 != path.rend())
            cout << " -> ";
        else
            cout << "\n";
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int v1, v2, one;
        array<int, 2> value;

        cin >> v1 >> v2 >> one >> value[0] >> value[1];

        graph[v1].adj.emplace_back(v2, value);
        weight[v1][v2] = value;
        if (not one) {
            graph[v2].adj.emplace_back(v1, value);
            weight[v2][v1] = value;
        }
    }

    int source, destination;
    cin >> source >> destination;

    array<int, 2> shortest;

    for (flag = 0; flag < 2; ++flag) {
        dijkstra(source);
        minSecondStandard = INF;
        dfs(destination, 0);
        shortest[flag] = graph[destination].dist;
    }

    if (shortestPath[0] == shortestPath[1]) {
        cout << "Distance = " << shortest[0] << "; Time = " << shortest[1] << ": ";
        printPath(shortestPath[0]);
    } else {
        cout << "Distance = " << shortest[0] << ": ";
        printPath(shortestPath[0]);
        cout << "Time = " << shortest[1] << ": ";
        printPath(shortestPath[1]);
    }
}
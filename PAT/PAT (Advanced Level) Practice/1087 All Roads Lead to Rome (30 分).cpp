#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

struct Node {
    bool visit;                     // 访问标志
    vector<string> pre;             // 最短路径上的前驱
    vector<pair<int, string>> adj;  // 邻接表
    int dist = -1, happiness, pathCnt;   // 最短路径估计 快乐值 最短路径个数
};

unordered_map<string, Node> node;

void dijkstra(string start) {
    node[start].dist = 0;
    node[start].pathCnt = 1;

    using pair = pair<int, string>;
    priority_queue<pair, vector<pair>, greater<pair>> pq;
    pq.push({ 0, start });

    while (not pq.empty()) {
        int u_dist = pq.top().first;
        string u = pq.top().second;
        pq.pop();

        node[u].visit = true;

        if (node[u].dist < u_dist) continue;
        for (auto& e : node[u].adj) {
            string v = e.second;
            int uv_cost = e.first;

            if (not node[v].visit and (node[v].dist == -1 or node[v].dist > node[u].dist + uv_cost)) {
                node[v].dist = node[u].dist + uv_cost;
                pq.push({ node[v].dist, v });

                node[v].pre.clear();
                node[v].pre.push_back(u);

                node[v].pathCnt = node[u].pathCnt;
            }
            else if (node[v].dist == node[u].dist + uv_cost) {
                node[v].pre.push_back(u);
                node[v].pathCnt += node[u].pathCnt;
            }
        }
    }
}

int max_sum = 0;
double max_avg = 0;
vector<string> temp_path, path;

void dfs(string name, int sum_happiness) {
    sum_happiness += node[name].happiness;
    temp_path.push_back(name);
    if (node[name].pre.empty()) {  // 深搜到了路径的源点
        double avgHappiness = double(sum_happiness) / (int(temp_path.size()) - 1);
        if (sum_happiness > max_sum
            or (sum_happiness == max_sum and avgHappiness > max_avg)) {
            max_sum = sum_happiness;
            max_avg = avgHappiness;

            path = temp_path;
            reverse(path.begin(), path.end());
        }
    }
    else {
        for (auto e : node[name].pre)
            dfs(e, sum_happiness);
    }
    temp_path.pop_back();
}

int main() {
    int n, k;
    string start, end = "ROM";
    cin >> n >> k >> start;

    // 读取每个城市的快乐值
    for (int i = 0; i < n - 1; ++i) {
        int happiness;
        string name;
        cin >> name >> happiness;
        
        node[name].happiness = happiness;
    }

    // 读取所有的道路
    for (int i = 0; i < k; ++i) {
        int cost;
        string c1, c2;

        cin >> c1 >> c2 >> cost;

        node[c1].adj.push_back({ cost, c2 });
        node[c2].adj.push_back({ cost, c1 });
    }

    dijkstra(start);   // dijkstra找出所有最短路径
    dfs(end, 0);       // dfs选出快乐值最大且平均快乐值尽可能大的最短路径

    cout << node["ROM"].pathCnt << " " << node["ROM"].dist << " "
        << max_sum << " " << int(max_avg) << "\n";

    for (auto iter = path.begin(); iter != path.end(); ++iter) {
        cout << *iter;
        if (iter + 1 != path.end()) cout << "->";
    }
}
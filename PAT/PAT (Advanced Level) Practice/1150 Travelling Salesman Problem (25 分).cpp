#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

struct node {
    int v, w;
};

int graph[205][205], path[205];
unordered_set<int> visitedCity;
set<pair<int, int>> visitedEdge;

int main() {

    int n, m, u, v, w, k;

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        graph[u][v] = graph[v][u] = w;
    }

    cin >> k;
    int minWeight = 1e9, minIndex;
    for (int i = 1; i <= k; ++i) {
        // 读入路径并判断路径是否存在
        bool isExist = true;
        int pathLen, totalWeight = 0;

        cin >> pathLen;
        visitedCity.clear();
        for (int j = 0; j < pathLen; ++j) {
            cin >> path[j];
            if (isExist) {
                if (j > 0) {
                    if (graph[path[j]][path[j - 1]] == 0)
                        isExist = false;
                    else
                        totalWeight += graph[path[j]][path[j - 1]];
                }
                visitedCity.insert(path[j]);
            }
        }

        cout << "Path " << i << ": ";

        if (!isExist) {
            cout << "NA (Not a TS cycle)\n";
            continue;
        }

        // 判断是否是经过了所有城市的环
        cout << totalWeight << " ";
        if (!(visitedCity.size() == n && path[0] == path[pathLen - 1])) {
            cout << "(Not a TS cycle)\n";
            continue;
        }

        if (minWeight > totalWeight) {
            minWeight = totalWeight;
            minIndex = i;
        }

        // 判断是否是简单环
        bool isSimple = true;

        visitedEdge.clear();
        for (int j = 0; j < pathLen - 1 && isSimple; ++j) {
            int u = path[j];
            int v = path[j + 1];
            if (u > v)
                swap(u, v);
            if (visitedEdge.count({u, v}) == 0)
                visitedEdge.insert({u, v});
            else if (visitedEdge.count({u, v}) == 1)
                isSimple = false;
        }

        if (isSimple)
            cout << "(TS simple cycle)\n";
        else
            cout << "(TS cycle)\n";
    }
    cout << "Shortest Dist(" << minIndex << ") = " << minWeight;
}
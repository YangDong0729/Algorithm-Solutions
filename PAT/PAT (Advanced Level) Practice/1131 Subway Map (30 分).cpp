#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

#define MAX_N 10005

array<int, MAX_N> dist;
array<bool, MAX_N> visit;
map<pair<int, int>, int> line;
vector<int> pre[MAX_N], graph[MAX_N];

void dijkstra(int start) {
	dist.fill(-1);
	visit.fill(false);

	using pair = pair<int, int>;
	priority_queue<pair, vector<pair>, greater<pair>> pq;

	dist[start] = 0;
	pre[start].clear();
	pre[start].push_back(-1);
	pq.push({ 0, start });

	while (!pq.empty()) {
		int u = pq.top().second, u_dist = pq.top().first;

		pq.pop();
		visit[u] = true;

		if (dist[u] != -1 and dist[u] < u_dist)
			continue; // dist[u] != -1
		for (auto& v : graph[u]) {
			if (!visit[v] and (dist[v] == -1 or dist[v] > u_dist + 1)) {
				dist[v] = u_dist + 1;
				pq.push({ dist[v], v });
				pre[v].clear();
				pre[v].push_back(u);
			}
			else if (dist[v] == u_dist + 1)
				pre[v].push_back(u);
		}
	}
}

int min_trans_cnt = MAX_N;
vector<int> path, tmp_path;

void trace(int x, int l, int trans_cnt) {
	if (trans_cnt > min_trans_cnt)
		return;
	if (pre[x][0] == -1) {
		if (min_trans_cnt > trans_cnt) {
			path = tmp_path;
			path.push_back(x);
			min_trans_cnt = trans_cnt;
		}
		return;
	}

	tmp_path.push_back(x);
	for (auto& v : pre[x]) {
		trace(v, line[{v, x}], trans_cnt + (line[{v, x}] != l)); // 这里 (line[{v, x}] != l) 需要加括号
																 // 但我之前用 unordered_map 时，由于不能用 pair ，所以哈希了一下，写成了 line[v * 10000 + x] ，这种不写括号竟然也对了
	}
	tmp_path.pop_back();
}

int main() {
	int n, m, pre_stop, k, start, dest;

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> m >> pre_stop;
		for (int j = 1, stop; j < m; ++j, pre_stop = stop) {
			cin >> stop;
			line[{pre_stop, stop}] = i;
			line[{stop, pre_stop}] = i;
			graph[pre_stop].push_back(stop);
			graph[stop].push_back(pre_stop);
		}
	}

	cin >> k;
	for (int i = 0; i < k; ++i) {
		cin >> start >> dest;

		dijkstra(start);
		min_trans_cnt = MAX_N;
		trace(dest, 0, 0);
		reverse(path.begin(), path.end());

		cout << path.size() - 1 << "\n";
		int p = path[0], seg = path[0], l = line[{path[0], path[1]}];
		for (auto j = path.begin() + 1; j != path.end(); p = *(j++)) {
			if (l != line[{p, * j}]) {
				printf("Take Line#%d from %04d to %04d.\n", l, seg, p);
				l = line[{p, * j}];
				seg = p;
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", l, seg, p);
	}
}
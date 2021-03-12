#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

int peoCnt = 0;
string id2name[2000];
unordered_map<string, int> name2id;

int getId(string name) {
    int id;
    if (name2id.count(name) == 0) {  // 给新名字分配一个id
        id = peoCnt++;
        name2id[name] = id;
        id2name[id] = name;
    }
    else id = name2id[name];  // 返回已有的id

    return id;
}

bool is_visited[2000];
int weight[2000];  // 点权
int netWeight[2000][2000];  // 边权

void dfs(int now, int& head, int& member_cnt, int& net_weight) {
    ++member_cnt;
    is_visited[now] = true;
    if (weight[now] > weight[head]) head = now;

    for (int i = 0; i < peoCnt; ++i) {
        if (netWeight[now][i] > 0) {
            net_weight += netWeight[now][i];
            netWeight[now][i] = netWeight[i][now] = 0;
            if (not is_visited[i]) dfs(i, head, member_cnt, net_weight);
        }
    }
}

map<string, int> gangs; // head -> cnt

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        int w;
        string a, b;
        cin >> a >> b >> w;

        int ida = getId(a);
        int idb = getId(b);

        weight[ida] += w;
        weight[idb] += w;

        netWeight[ida][idb] += w;
        netWeight[idb][ida] += w;
    }

    for (int i = 0; i < peoCnt; ++i) {
        if (not is_visited[i]) {
            int head = i, member_cnt = 0, net_weight = 0;
            dfs(i, head, member_cnt, net_weight);
            if (net_weight > k and member_cnt > 2)
                gangs[id2name[head]] = member_cnt;
        }
    }

    cout << gangs.size() << "\n";
    for (auto& g : gangs)
        cout << g.first << " " << g.second << "\n";
}
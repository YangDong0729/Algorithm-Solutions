#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

struct record {
    set<int> callBack; // 别人打给他的电话
    int calls[1005];   // 打出的电话
};

struct gan {
    vector<int> member; // 团伙成员

    bool operator<(gan &x) { // 对gang排序之前先把member排序
        if (!is_sorted(member.begin(), member.end()))
            sort(member.begin(), member.end());
        if (!is_sorted(x.member.begin(), x.member.end()))
            sort(x.member.begin(), x.member.end());
        return member[0] < x.member[0];
    }
};

int k, n, m;
gan gangs[1005];
int father[1005];
record records[1005];
vector<int> suspects; // 所有可疑人员

int find(int x) {
    int f;
    if (father[x] == x)
        f = x;
    else
        f = find(father[x]);
    return f;
}

void unin(int a, int b) {
    int fa = find(a);
    int fb = find(b);
    if (fa != fb)
        father[fa] = fb; // 注意是fa
}

int main() {
    //    freopen("in.txt", "r", stdin);
    //    freopen("out.txt", "w", stdout);

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> k >> n >> m;
    for (int i = 0; i < m; ++i) {
        int caller, receiver, duration;
        cin >> caller >> receiver >> duration;
        records[caller].calls[receiver] += duration;
        records[receiver].callBack.insert(caller);
    }

    // 找出所有可疑的人
    for (int i = 1; i <= n; ++i) {
        int shortCall = 0, callback = 0;
        for (int j = 1; j <= n; ++j) {
            if (records[i].calls[j] > 0 and records[i].calls[j] <= 5) {
                ++shortCall;
                if (records[i].callBack.count(j))
                    ++callback;
            }
        }
        if (shortCall > k and callback * 5 <= shortCall) {
            suspects.push_back(i);
        }
    }

    if (suspects.size() == 0) {
        cout << "None\n";
        return 0;
    }

    // 通过并查集计算团伙
    for (int i = 1; i <= n; ++i)
        father[i] = i;
    for (int i = 0; i < suspects.size(); ++i) {
        for (int j = i + 1; j < suspects.size(); ++j) {
            if (records[suspects[i]].calls[suspects[j]] != 0 and records[suspects[j]].calls[suspects[i]] != 0)
                unin(suspects[i], suspects[j]);
        }
    }

    int gangsCnt = 0;
    map<int, int> head2index;
    for (int i = 0; i < suspects.size(); ++i) {
        int head = find(suspects[i]);
        if (!head2index.count(head))
            head2index[head] = gangsCnt++;
        gangs[head2index[head]].member.push_back(suspects[i]);
    }

    sort(gangs, gangs + gangsCnt);

    for (int i = 0; i < gangsCnt; ++i) {
        for (int j = 0; j < gangs[i].member.size(); ++j) {
            cout << gangs[i].member[j];
            if (j != gangs[i].member.size() - 1)
                cout << " ";
        }
        cout << "\n";
    }
}
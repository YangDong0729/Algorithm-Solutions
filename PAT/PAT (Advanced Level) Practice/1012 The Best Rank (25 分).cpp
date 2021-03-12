#include <iostream>
#include <algorithm>

using namespace std;

int flag;
int id2pos[1000000];
char course[5] = "ACME";

struct stu {
    int id, best = 0, grade[4], rank[4];
};

stu st[2005];

bool cmp(const stu& s1, const stu& s2) {
    return s1.grade[flag] > s2.grade[flag];
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> st[i].id >> st[i].grade[1] >> st[i].grade[2] >> st[i].grade[3];
        st[i].grade[0] = (st[i].grade[1] + st[i].grade[2] + st[i].grade[3]) / 3;
    }

    for (flag = 0; flag < 4; ++flag) {
        sort(st, st + n, cmp);  // 排序
        st[0].rank[flag] = 1;
        for (int i = 1; i < n; ++i) {  // 计算排名
            if (st[i].grade[flag] == st[i - 1].grade[flag])
                st[i].rank[flag] = st[i - 1].rank[flag];
            else st[i].rank[flag] = i + 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        id2pos[st[i].id] = i + 1;  // id2pos[id] == 0 代表id不存在
        int bestRank = st[i].rank[0];  // 计算最好成绩
        for (int j = 1; j < 4; ++j) {
            if (st[i].rank[j] < bestRank) {
                bestRank = st[i].rank[j];
                st[i].best = j;
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        if (id2pos[x]) {
            int pos = id2pos[x] - 1;
            int best = st[pos].best;
            cout << st[pos].rank[best] << " " << course[best] << "\n";
        }
        else cout << "N/A\n";
    }
}
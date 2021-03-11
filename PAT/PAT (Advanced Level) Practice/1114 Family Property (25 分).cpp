#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct {
    int estate = 0, area = 0, visit = 1;
    vector<int> children, parents;
} person[10005];

struct Family {
    int memberCnt = 0, estateCnt = 0, area = 0, id = 10000;

    double avgArea() const {
        return area * 1.0 / memberCnt;
    }

    bool operator<(const Family &x) const {
        if (avgArea() != x.avgArea())
            return avgArea() > x.avgArea();
        else
            return id < x.id;
    }
};

vector<Family> family;

void dfs(int id, Family &f) {
    person[id].visit = 1;
    f.memberCnt += 1;
    f.estateCnt += person[id].estate;
    f.area += person[id].area;
    f.id = min(f.id, id);

    for (auto &c : person[id].children)
        if (not person[c].visit)
            dfs(c, f);
    for (auto &p : person[id].parents)
        if (not person[p].visit)
            dfs(p, f);
}

void addParent(int id, int parentId) {
    person[id].visit = 0;
    if (parentId != -1) {
        person[parentId].visit = 0;
        person[id].parents.push_back(parentId);
        person[parentId].children.push_back(id);
    }
}

int main() {
    int n, id, k, c, father, mother;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> id >> father >> mother >> k;
        addParent(id, father);
        addParent(id, mother);
        for (int j = 0; j < k; ++j) {
            cin >> c;
            addParent(c, id);
        }
        cin >> person[id].estate >> person[id].area;
    }

    for (int i = 0; i < 10005; ++i) {
        if (not person[i].visit) {
            Family f;
            dfs(i, f);
            family.push_back(f);
        }
    }

    sort(family.begin(), family.end());

    cout << family.size() << "\n";
    for (auto &f : family)
        printf("%04d %d %.3f %.3f\n", f.id, f.memberCnt,
               f.estateCnt * 1.0 / f.memberCnt, f.area * 1.0 / f.memberCnt);
}
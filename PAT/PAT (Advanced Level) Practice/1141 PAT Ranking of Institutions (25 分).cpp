#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Inst {
    int count;
    string code;
    double tws;
};

vector<Inst> inst;
unordered_map<string, int> inst_index;

int getIndex(string &s) {
    if (inst_index.count(s))
        return inst_index[s];
    else {
        inst_index[s] = inst.size();
        inst.push_back(Inst{0, s, 0});
        return inst.size() - 1;
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        double tws;
        string id, code;

        cin >> id >> tws >> code;

        if (id[0] == 'B')
            tws /= 1.5;
        else if (id[0] == 'T')
            tws *= 1.5;
        // 这种写法是没问题的，PAT 编译器的版本太低
        // transform(code.begin(), code.end(), code.begin(), tolower);
        transform(code.begin(), code.end(), code.begin(), ::tolower);
        int sid = getIndex(code);
        inst[sid].count++;
        inst[sid].tws += tws;
    }

    sort(inst.begin(), inst.end(), [](Inst &a, Inst &b) {
        if (int(a.tws) != int(b.tws))
            return a.tws > b.tws;
        else if (a.count != b.count)
            return a.count < b.count;
        else
            return a.code < b.code;
    });

    cout << inst.size() << "\n";
    int rank = 1, tws = inst.begin()->tws;
    for (auto i = inst.begin(); i != inst.end(); ++i) {
        if (tws != int(i->tws)) {
            rank = i - inst.begin() + 1;
            tws = i->tws;
        }
        printf("%d %s %d %d\n", rank, i->code.c_str(), tws, i->count);
    }
}
#include <cstdio>
#include <iostream>
#include <set>
#include <string>

using namespace std;

struct person {
    string id, birth;

    person(string &id) : id(id) {
        birth = id.substr(6, 8);
    }

    bool operator<(const person &x) const {
        if (birth != x.birth)
            return birth < x.birth;
        else
            return id < x.id;
    }
};

int main() {
    //    freopen("in.txt", "r", stdin);
    //    freopen("out.txt", "w", stdout);

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    set<person> alumnus, all, com;

    int n;
    string s;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        alumnus.insert(person(s));
    }

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        all.insert(person(s));
        if (alumnus.count(person(s)))
            com.insert(person(s));
    }

    cout << com.size() << "\n";
    if (com.size() == 0)
        cout << all.begin()->id;
    else
        cout << com.begin()->id;
}
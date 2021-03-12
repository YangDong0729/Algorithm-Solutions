#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> course2Names[2505];

int main() {
    string name;
    int n, k, p, courseNum;

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> name >> courseNum;
        for (int j = 0; j < courseNum; ++j) {
            cin >> p;
            course2Names[p].push_back(name);
        }
    }

    for (int i = 1; i <= k; ++i) {
        cout << i << " " << course2Names[i].size() << "\n";
        sort(course2Names[i].begin(), course2Names[i].end());
        for (auto& e : course2Names[i])
            cout << e << "\n";
    }
}
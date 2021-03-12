#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;
    cin.get();

    unordered_map<int, unordered_map<string, vector<string>>> maps;

    while (n--) {
        string id, item;
        getline(cin, id);

        for (int i = 1; i <= 5; ++i) {
            getline(cin, item);

            if (i == 3) {  // 处理关键字
                stringstream ssm;
                ssm << item;
                while (ssm >> item) maps[i][item].push_back(id);
            }
            else {
                maps[i][item].push_back(id);
            }
        }
    }

    cin >> n;
    cin.get();

    while (n--) {
        string query;
        getline(cin, query);

        cout << query << '\n';
        if (maps[query[0] - '0'].count(query.substr(3)) == 0)
            cout << "Not Found\n";
        else {
            auto& ids = maps[query[0] - '0'].at(query.substr(3));
            sort(ids.begin(), ids.end());  // 在查询时再排序
            for (auto& e : ids) cout << e << '\n';
        }
    }
}
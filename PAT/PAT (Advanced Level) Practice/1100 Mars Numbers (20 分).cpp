#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string int2str[2][13] = {{"tret", "jan", "feb", "mar", "apr", "may", "jun",
                              "jly", "aug", "sep", "oct", "nov", "dec"},
                             {"tret", "tam", "hel", "maa", "huh", "tou", "kes",
                              "hei", "elo", "syy", "lok", "mer", "jou"}};

    unordered_map<string, int> str2int;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 13; ++j) {
            str2int[int2str[i][j]] = i ? 13 * j : j;
        }
    }

    int query;
    cin >> query;
    cin.get(); // 吃掉回车

    string s;
    while (query--) {
        getline(cin, s);

        if (isdigit(s[0])) {
            int num, a, b;

            sscanf(s.c_str(), "%d", &num);

            a = num % 13;
            b = num / 13;

            if (b != 0) {
                cout << int2str[1][b];
                if (a != 0)
                    cout << " ";
            }
            if (a != 0 or b == 0)
                cout << int2str[0][a];

            cout << "\n";
        } else {
            int num = 0;
            int blk_loc = s.find(" ");

            if (blk_loc != string::npos)
                num = str2int[s.substr(blk_loc + 1)] +
                      str2int[s.substr(0, blk_loc)];
            else
                num = str2int[s];

            cout << num << "\n";
        }
    }
}
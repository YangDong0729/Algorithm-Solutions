#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        auto map = vector<int>(256, -1); // 字符->最后出现的位置

        int ans = 0;
        int start = 0; // 当前子串的开始位置

        for (int i = 0; i < s.length(); ++i) {

            if (map[s[i]] >= start) {  // 当前字符与之前字符重复
                start = map[s[i]] + 1; // 从重复的下一个开始
            }

            // 当前的无重复字符串：[start, i]
            ans = max(ans, i - start + 1);
            map[s[i]] = i;
        }

        return ans;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i + 1];
            switch (nextChar) {
            case '\"':
                result.push_back('\"');
                break;
            case '/':
                result.push_back('/');
                break;
            case '\\':
                result.push_back('\\');
                break;
            case 'b':
                result.push_back('\b');
                break;
            case 'f':
                result.push_back('\f');
                break;
            case 'r':
                result.push_back('\r');
                break;
            case 'n':
                result.push_back('\n');
                break;
            case 't':
                result.push_back('\t');
                break;
            default:
                break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);

        int ret = Solution().lengthOfLongestSubstring(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
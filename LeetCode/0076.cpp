class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int left = 0, right = 0;  // ����ҿ�����ʼ����Ϊ 0
        int valid = 0;
        // ��¼��С�����Ӵ�����ʼ����������
        int start = 0, len = INT_MAX;
        while (right < s.size()) {
            // c �ǽ����봰�ڵ��ַ�
            char c = s[right];
            right++;
            // ���д��������ݵ�һϵ�и���
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
                // �ж���ര���Ƿ�Ҫ����
                while (valid == need.size()) {
                    // �����������С�����Ӵ�
                    if (right - left < len) {
                        start = left;
                        len = right - left;
                    }
                    // d �ǽ��Ƴ����ڵ��ַ�
                    char d = s[left];
                    left++;
                    // ���д��������ݵ�һϵ�и���
                    if (need.count(d)) {
                        if (window[d] == need[d]) {
                            valid--;
                        }
                        window[d]--;
                    }
                }
            }
        }
        // ������С�����Ӵ�
        return len == INT_MAX ? "" : s.substr(start, len);
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
            case '\"': result.push_back('\"'); break;
            case '/': result.push_back('/'); break;
            case '\\': result.push_back('\\'); break;
            case 'b': result.push_back('\b'); break;
            case 'f': result.push_back('\f'); break;
            case 'r': result.push_back('\r'); break;
            case 'n': result.push_back('\n'); break;
            case 't': result.push_back('\t'); break;
            default: break;
            }
            i++;
        }
        else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string t = stringToString(line);

        string ret = Solution().minWindow(s, t);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
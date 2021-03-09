#include <iostream>
#include <sstream>
#include <string>

using namespace std;

bool isPrime(int x) {
    bool ans = true;

    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            ans = false;
            break;
        }
    }

    return ans;
}

int main() {
    int l, k;
    string s;

    cin >> l >> k >> s;

    for (int i = 0; i + k <= l; ++i) {
        int num;
        sscanf(s.substr(i, k).c_str(), "%d", &num);
        if (isPrime(num)) {
            cout << s.substr(i, k);
            return 0;
        }
    }

    cout << "404";
}
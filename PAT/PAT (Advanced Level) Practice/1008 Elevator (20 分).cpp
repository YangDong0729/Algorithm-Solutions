#include <iostream>

using namespace std;

int main() {
    int n, now = 0, t = 0;

    cin >> n;
    while (n--) {
        int tmp, c;
        cin >> tmp;

        c = tmp - now;
        if (c >= 0) t += 6 * c + 5;
        else if (c < 0) t += -4 * c + 5;
        now = tmp;
    }
    cout << t;
}
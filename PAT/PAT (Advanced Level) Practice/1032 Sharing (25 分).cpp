#include <iostream>
#include <iomanip>

using namespace std;

struct {
    int next;
    bool is_visited;
} node[100005];

int main() {
    int a, b, n;
    cin >> a >> b >> n;

    for (int i = 0; i < n; i++) {
        int id, ne;
        char d;
        cin >> id >> d >> ne;

        node[id].next = ne;
    }

    for (int pos = a; pos != -1; pos = node[pos].next)
        node[pos].is_visited = 1;

    int ans = -1;
    for (int pos = b; pos != -1; pos = node[pos].next) {
        if (node[pos].is_visited == 1) {
            ans = pos;
            break;
        }
    }

    if (ans == -1)
        cout << -1;
    else  // 注意格式
        cout << setw(5) << setfill('0') << ans;
}

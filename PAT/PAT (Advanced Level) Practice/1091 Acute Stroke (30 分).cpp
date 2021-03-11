#include <iostream>
#include <queue>

using namespace std;

int m, n, l, t;
int brain[65][130][130];
int steps[6][3] = {{1, 0, 0},
                   {-1, 0, 0},
                   {0, 1, 0},
                   {0, -1, 0},
                   {0, 0, 1},
                   {0, 0, -1}};

struct node {
    int x, y, z;
};

bool isValid(node &a) {
    if (a.x < 0 or a.x >= l or
        a.y < 0 or a.y >= m or
        a.z < 0 or a.z >= n)
        return false;
    return brain[a.x][a.y][a.z] == 1;
}

int bfs(node start) {
    int cnt = 0;
    queue<node> q;

    q.push(start);
    brain[start.x][start.y][start.z] = 2;

    while (not q.empty()) {
        node top = q.front();
        q.pop();
        ++cnt;

        for (int i = 0; i < 6; ++i) {
            node next{top.x + steps[i][0], top.y + steps[i][1], top.z + steps[i][2]};
            if (isValid(next)) {
                q.push(next);
                brain[next.x][next.y][next.z] = 2;
            }
        }
    }

    return cnt;
}

int main() {
    cin >> m >> n >> l >> t;

    for (int i = 0; i < l; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < n; ++k)
                cin >> brain[i][j][k];

    int total = 0;
    for (int i = 0; i < l; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < n; ++k)
                if (brain[i][j][k] == 1) {
                    int cnt = bfs({i, j, k});
                    if (cnt >= t)
                        total += cnt;
                }

    cout << total;
}
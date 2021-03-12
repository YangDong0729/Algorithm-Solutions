#include <iostream>
#include <vector>

using namespace std;

int pre[1005];
vector<int> post;
bool mirror = false;

bool postTravel(int preL, int len) {
    if (len < 1) return true;

    int root = pre[preL];
    int leftR = preL + 1, rightR;

    if (mirror) {
        while (leftR < preL + len and pre[leftR] >= root) ++leftR;
        rightR = leftR;
        while (rightR < preL + len and pre[rightR] < root) ++rightR;
    }
    else {
        while (leftR < preL + len and pre[leftR] < root) ++leftR;
        rightR = leftR;
        while (rightR < preL + len and pre[rightR] >= root) ++rightR;
    }

    if (rightR == preL + len
        and postTravel(preL + 1, leftR - preL - 1)
        and postTravel(leftR, rightR - leftR)) {
        post.push_back(root);
        return true;
    }
    return false;
}

int main() {
    int n;

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> pre[i];

    if (not postTravel(0, n)) {
        post.clear();
        mirror = true;
        if (not postTravel(0, n)) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    for (auto i = post.begin(); i != post.end(); ++i)
        cout << *i << (i + 1 == post.end() ? "\n" : " ");
}
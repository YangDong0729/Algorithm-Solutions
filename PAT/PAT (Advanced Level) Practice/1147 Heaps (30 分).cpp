#include <iostream>

using namespace std;

int m, n, arr[1005];

void postOrder(int root) {
    if (root * 2 <= n) {
        postOrder(root * 2);
        cout << " ";
    }
    if (root * 2 + 1 <= n) {
        postOrder(root * 2 + 1);
        cout << " ";
    }
    cout << arr[root];
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        bool maxH = true, minH = true;
        for (int j = 1; j <= n; ++j)
            cin >> arr[j];
        for (int j = 1; j <= n; ++j) {
            if (j * 2 <= n) {
                if (arr[j * 2] > arr[j])
                    maxH = false;
                else if (arr[j * 2] < arr[j])
                    minH = false;
            }
            if (j * 2 + 1 <= n) {
                if (arr[j * 2 + 1] > arr[j])
                    maxH = false;
                else if (arr[j * 2 + 1] < arr[j])
                    minH = false;
            }
        }

        if (maxH)
            cout << "Max Heap\n";
        else if (minH)
            cout << "Min Heap\n";
        else
            cout << "Not Heap\n";
        postOrder(1);
        cout << "\n";
    }
}
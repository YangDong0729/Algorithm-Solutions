#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a;
    vector<int> A, B, C;
    while (cin >> a && a != -1) {
        A.push_back(a);
    }
    while (cin >> a && a != -1) {
        B.push_back(a);
    }
    for (int i = 0, j = 0; i < A.size() && j < B.size();) {
        while (i < A.size() && A[i] < B[j])
            i++;
        while (j < B.size() && A[i] > B[j])
            j++;
        if (A[i] == B[j]) {
            C.push_back(A[i]);
            i++, j++;
        }
    }
    if (C.empty())
        cout << "NULL";
    else {
        for (int i = 0; i < C.size(); i++) {
            cout << C[i] << (i == C.size() - 1 ? "" : " ");
        }
    }
}
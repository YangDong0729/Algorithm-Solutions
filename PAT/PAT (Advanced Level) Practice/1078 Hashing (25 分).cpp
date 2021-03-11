#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

bool hashTable[10005];

void insert(int key, int size) {
    for (int step = 0; step < size; ++step) {
        int pos = (key + step * step) % size;
        if (not hashTable[pos]) {
            hashTable[pos] = true;
            cout << pos;
            return;
        }
    }
    cout << "-";
}

int main() {
    int n, size, key;
    cin >> size >> n;
    while (not isPrime(size))
        ++size;
    for (int i = 0; i < n; ++i) {
        cin >> key;
        if (i != 0)
            cout << " ";
        insert(key, size);
    }
}
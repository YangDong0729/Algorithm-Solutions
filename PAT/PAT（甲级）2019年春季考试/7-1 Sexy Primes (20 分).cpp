#include <cmath>
#include <iostream>

using namespace std;

bool isPrime(int x) {
    if (x <= 1)
        return false;
    int sqr = sqrt(x);
    for (int i = 2; i <= sqr; ++i)
        if (x % i == 0)
            return false;
    return true;
}

int isSexy(int x) {
    if (isPrime(x)) {
        if (isPrime(x - 6))
            return x - 6;
        if (isPrime(x + 6))
            return x + 6;
    }
    return -1;
}

int main() {
    int a, b;
    cin >> a;

    if ((b = isSexy(a)) != -1)
        cout << "Yes\n"
             << b;
    else {
        while (isSexy(++a) == -1)
            ;
        cout << "No\n"
             << a;
    }
}
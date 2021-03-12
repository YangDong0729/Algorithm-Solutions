#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char account[1005][15], password[1005][15];
bool modified[1005];

int main() {
    int n, cnt = 0;
    scanf("%d\n", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%s %s", account[i], password[i]);
        int len = strlen(password[i]);

        for (int j = 0; j < len; ++j) {
            switch (password[i][j]) {
                case '1':
                    password[i][j] = '@';
                    modified[i] = true;
                    break;
                case '0':
                    password[i][j] = '%';
                    modified[i] = true;
                    break;
                case 'l':
                    password[i][j] = 'L';
                    modified[i] = true;
                    break;
                case 'O':
                    password[i][j] = 'o';
                    modified[i] = true;
                    break;
            }
        }

        if (modified[i]) ++cnt;
    }

    if (cnt) {
        printf("%d\n", cnt);
        for (int i = 0; i < n; ++i)
            if (modified[i]) printf("%s %s\n", account[i], password[i]);
    } else if (n == 1)
        printf("There is %d account and no account is modified", n);
    else
        printf("There are %d accounts and no account is modified", n);
}

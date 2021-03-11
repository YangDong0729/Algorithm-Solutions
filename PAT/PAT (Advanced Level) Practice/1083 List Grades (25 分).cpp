#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>

using namespace std;

struct Student {
    char name[11], id[11];
    int grade;
} stu[50];

int main() {
    int n, left, right;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
    scanf("%d%d", &left, &right);

    sort(stu, stu + n, [](Student &a, Student &b) {
        return a.grade > b.grade;
    });

    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (stu[i].grade >= left and stu[i].grade <= right) {
            printf("%s %s\n", stu[i].name, stu[i].id);
            flag = true;
        }
    }
    if (flag == false)
        printf("NONE\n");
}
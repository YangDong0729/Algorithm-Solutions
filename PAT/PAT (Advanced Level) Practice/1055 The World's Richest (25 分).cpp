#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
const int max_n = 100010;

int age[max_n];

struct Person {
    int age, worths;
    char name[10];
} person[max_n];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%s%d%d", person[i].name, &person[i].age, &person[i].worths);

    sort(person, person + n,
        [](Person a, Person b) {
            if (a.worths != b.worths)
                return a.worths > b.worths;
            else if (a.age != b.age)
                return a.age < b.age;
            return strcmp(a.name, b.name) < 0;
        });

    int validCnt = 0;
    for (int i = 0; i < n; i++) {
        if (age[person[i].age] < 100) {
            age[person[i].age]++;
            person[validCnt++] = person[i];
        }
    }

    for (int i = 1; i <= k; i++) {
        int m, ageL, ageR, cnt = 0;
        scanf("%d%d%d", &m, &ageL, &ageR);
        printf("Case #%d:\n", i);
        for (int j = 0; j < validCnt and cnt < m; j++) {
            if (person[j].age >= ageL and person[j].age <= ageR) {
                printf("%s %d %d\n", person[j].name, person[j].age, person[j].worths);
                cnt++;
            }
        }
        if (cnt == 0)
            printf("None\n");
    }
}
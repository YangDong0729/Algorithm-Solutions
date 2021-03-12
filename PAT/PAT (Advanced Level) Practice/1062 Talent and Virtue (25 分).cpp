#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct Person {
    char id[10];
    int v, t, cls, sum;
} person[100005];

int main() {
    int n, l, h;
    scanf("%d %d %d\n", &n, &l, &h);

    int m = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%s %d %d", person[m].id, &person[m].v, &person[m].t);
        if (!(person[m].v < l or person[m].t < l)) {
            person[m].sum = person[m].v + person[m].t;
            if (person[m].v >= h and person[m].t >= h)
                person[m].cls = 1;
            else if (person[m].v >= h and person[m].t < h)
                person[m].cls = 2;
            else if (person[m].v < h and person[m].t < h and person[m].t <= person[m].v)
                person[m].cls = 3;
            else
                person[m].cls = 4;
            ++m;
        }
    }

    sort(person, person + m, [](Person &a, Person &b) {
        if (a.cls != b.cls)
            return a.cls < b.cls;
        else if (a.sum != b.sum)
            return a.sum > b.sum;
        else if (a.v != b.v)
            return a.v > b.v;
        else
            return strcmp(a.id, b.id) < 0;
    });

    printf("%d\n", m);
    for (int i = 0; i < m; ++i)
        printf("%s %d %d\n", person[i].id, person[i].v, person[i].t);
}
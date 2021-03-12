#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

struct Student {
    char name[50], major[50];
    int grade;
} f, m;

int main() {
    m.grade = 9999;
    f.grade = -9999;

    int n;
    scanf("%d", &n);

    bool absent = false;
    while (n--) {
        char sex;
        Student st;
        scanf("%s %c %s %d\n", st.name, &sex, st.major, &st.grade);
        if (sex == 'M' and st.grade < m.grade) m = st;
        else if (sex == 'F' and st.grade > f.grade) f = st;
    }

    if (f.grade == -9999) {
        absent = true;
        printf("Absent\n");
    }
    else printf("%s %s\n", f.name, f.major);

    if (m.grade == 9999) {
        absent = true;
        printf("Absent\n");
    }
    else printf("%s %s\n", m.name, m.major);

    if (absent) printf("NA\n");
    else printf("%d\n", f.grade - m.grade);
}
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string id;
    int score, loc_id, loc_rank;
    friend bool operator<(const Student &a, const Student &b) {
        if (a.score != b.score)
            return a.score > b.score;
        else
            return a.id < b.id;
    }
    Student(string id, int score, int loc_id, int loc_rank) : id(id), score(score), loc_id(loc_id), loc_rank(loc_rank) {}
};

int main() {
    int n, k, cnt = 0;
    vector<Student> student;

    cin >> n;
    for (int i = 0; i < n; ++i, cnt += k) {
        cin >> k;
        for (int j = 0; j < k; ++j) {
            student.emplace_back("", 0, i + 1, 0);
            cin >> student.back().id >> student.back().score;
        }

        // 计算考场内的排名
        sort(student.begin() + cnt, student.begin() + cnt + k);
        student[cnt].loc_rank = 1;
        for (int j = 1; j < k; ++j)
            if (student[cnt + j].score == student[cnt + j - 1].score)
                student[cnt + j].loc_rank = student[cnt + j - 1].loc_rank;
            else
                student[cnt + j].loc_rank = j + 1;
    }
    // 输出考生总人数
    cout << cnt << "\n";

    // 计算总排名并输出
    sort(student.begin(), student.end());
    int rank = 1;
    int score = student[0].score;
    for (int i = 0; i < student.size(); ++i) {
        if (student[i].score != score) {
            rank = i + 1;
            score = student[i].score;
        }
        cout << student[i].id << ' ' << rank << ' ' << student[i].loc_id << ' '
             << student[i].loc_rank << '\n';
    }
}
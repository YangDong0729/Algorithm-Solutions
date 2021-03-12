#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>

using namespace std;

struct User {
    int user_id;
    int final_score[6] = { -1, -1, -1, -1, -1, -1 }; // -1代表用户没提交过
    int total_score = 0;
    int full_mark_cnt = 0;
    bool show = false;
} users[10005];

int full_mark[5];

int main() {
    int n, k, m;
    scanf("%d %d %d\n", &n, &k, &m);

    for (int i = 1; i <= n; ++i) // 设置用户id
        users[i].user_id = i;
    for (int i = 1; i <= k; ++i) // 读入每道题的满分
        scanf("%d", &full_mark[i]);
    for (int i = 0; i < m; ++i) {
        int user_id, problem_id, obtained_score;
        scanf("%d %d %d\n", &user_id, &problem_id, &obtained_score); // 读入一个提交

        User& user = users[user_id];
        int& final_score = user.final_score[problem_id];
        final_score = max(final_score, 0);  // 对于应该show1的人，即使没编译通过的题目也要显示0，没提交过的才显示-
        if (obtained_score >= 0)  // 至少有一道题通过了编译
            user.show = true;
        if (final_score < obtained_score) { // 更新用户的分数
            user.total_score += obtained_score - final_score;
            if (obtained_score == full_mark[problem_id])
                user.full_mark_cnt++;
            final_score = obtained_score;
        }
    }

    sort(users + 1, users + 1 + n, [](User& a, User& b) {
        if (a.show != b.show)
            return a.show > b.show;
        else if (a.total_score != b.total_score)
            return a.total_score > b.total_score;
        else if (a.full_mark_cnt != b.full_mark_cnt)
            return a.full_mark_cnt > b.full_mark_cnt;
        else
            return a.user_id < b.user_id;
        });

    int cnt = 0, rank = 0, last_sum = -1;
    for (int i = 1; i <= n and users[i].show; ++i) {
        ++cnt;
        if (last_sum != users[i].total_score) {
            rank = cnt;
            last_sum = users[i].total_score;
        }
        printf("%d %05d %d ", rank, users[i].user_id, users[i].total_score);
        for (int j = 1; j <= k; ++j) {
            if (users[i].final_score[j] >= 0)
                printf("%d", users[i].final_score[j]);
            else
                printf("-");
            if (j != k)
                printf(" ");
        }
        printf("\n");
    }
}
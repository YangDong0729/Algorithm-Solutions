#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define timestamp(h, m, s) ((h)*3600 + (m)*60 + (s))

constexpr int startTime = timestamp(8, 0, 0);
constexpr int endTime = timestamp(21, 0, 0);

int n, k, m;

struct Player {
    int arriveTime, play, serveTime = endTime, vip; // 到达时间 游戏时间

    bool operator<(const Player &b) {
        return arriveTime > b.arriveTime;
    }

    struct Cmp {
        bool operator()(Player *a, Player *b) {
            return *a < *b;
        }
    };
} player[10005];
priority_queue<Player *, vector<Player *>, Player::Cmp> commonPlayer, vipPlayer;

struct Table {
    int id, freeTime = startTime, vip = 0, serveCnt = 0;

    bool operator<(const Table &b) { // a的优先级 < b的优先级
        if (freeTime != b.freeTime)
            return freeTime > b.freeTime;
        else
            return id > b.id;
    }

    struct Cmp {
        bool operator()(Table *a, Table *b) {
            return *a < *b;
        }
    };
} table[105];
priority_queue<Table *, vector<Table *>, Table::Cmp> commonTable, vipTable;

Player *getPlayer() {
    auto v = vipPlayer.empty() ? nullptr : vipPlayer.top(),
         c = commonPlayer.empty() ? nullptr : commonPlayer.top();

    if (!v or !c) {
        if (v)
            vipPlayer.pop();
        if (c)
            commonPlayer.pop();
        return v ? v : c;
    }

    if (*v < *c) {
        commonPlayer.pop();
        return c;
    } else {
        vipPlayer.pop();
        return v;
    }
}

Table *getFreeTable(Player &p) {
    Table *c = commonTable.top();

    if (vipTable.empty()) {
        commonTable.pop();
        return c;
    }

    Table *v = vipTable.top();

    if (p.vip) {
        if (v->freeTime <= max(c->freeTime, p.arriveTime)) {
            vipTable.pop();
            return v;
        } else {
            commonTable.pop();
            return c;
        }
    } else {
        if (*c < *v and (vipPlayer.empty() or
                         vipPlayer.top()->arriveTime > vipTable.top()->freeTime)) {
            vipTable.pop();
            return v;
        } else {
            commonTable.pop();
            return c;
        }
    }
}

void addFreeTable(Table *t) {
    if (t->vip)
        vipTable.push(t);
    else
        commonTable.push(t);
}

void printTime(int timestamp) {
    printf("%02d:%02d:%02d", timestamp / 3600, (timestamp / 60) % 60,
           timestamp % 60);
}

int main() {
    cin >> n; // 读入客户数据
    for (int i = 0; i < n; ++i) {
        int hour, minute, second, play;

        scanf("%d:%d:%d", &hour, &minute, &second);
        player[i].arriveTime = timestamp(hour, minute, second);

        cin >> play;
        if (play > 120)
            play = 120;
        player[i].play = play * 60;

        cin >> player[i].vip;
        if (player[i].vip)
            vipPlayer.push(player + i);
        else
            commonPlayer.push(player + i);
    }

    cin >> k >> m; // 读入桌子数据
    for (int i = 1; i <= k; ++i)
        table[i].id = i;
    for (int i = 0; i < m; ++i) {
        int id;
        cin >> id;
        table[id].vip = true;
    }

    for (int i = 1; i <= k; ++i) {
        if (table[i].vip)
            vipTable.push(table + i);
        else
            commonTable.push(table + i);
    }

    while (true) {
        Player *p = getPlayer();
        if (p == nullptr)
            break;
        Table *t = getFreeTable(*p);

        p->serveTime = max(t->freeTime, p->arriveTime);
        if (p->serveTime >= endTime)
            continue; // 由于VIP客户的存在，这里不能是break
        t->freeTime = p->serveTime + p->play;
        t->serveCnt++;
        addFreeTable(t);
    }

    sort(player, player + n,
         [](Player &a, Player &b) { return a.serveTime < b.serveTime; });

    for (int i = 0; i < n and player[i].serveTime < endTime; ++i) {
        printTime(player[i].arriveTime);
        printf(" ");
        printTime(player[i].serveTime);
        int waitTimeStamp = player[i].serveTime - player[i].arriveTime;
        printf(" %d\n", waitTimeStamp / 60 + (waitTimeStamp % 60 >= 30));
    }
    for (int i = 1; i <= k; ++i)
        cout << table[i].serveCnt << (i == k ? "" : " ");
}
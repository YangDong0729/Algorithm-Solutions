#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

const int IN = 0, OUT = 1;
map<string, int> parkTime;

struct Record {
    string plate;
    int timeStamp, status;
} record[10005];

int timeStamp(string &time) {
    int h, m, s;
    sscanf(time.c_str(), "%d:%d:%d", &h, &m, &s);
    return h * 3600 + m * 60 + s;
}

bool cmp(Record &a, Record &b) {
    if (a.timeStamp != b.timeStamp)
        return a.timeStamp < b.timeStamp;
    else
        return a.status < b.status;
}

int main() {
    int n, k; // 读入所有记录
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        string time, status;
        cin >> record[i].plate >> time >> status;
        record[i].timeStamp = timeStamp(time);
        record[i].status = status[0] == 'o';
    }

    int validCnt = 0; // 筛选出有效的记录
    sort(record, record + n, [](Record &a, Record &b) {
        if (a.plate != b.plate)
            return a.plate < b.plate;
        else
            return cmp(a, b);
    });

    for (int i = 0; i < n; ++i) {
        while (i < n and record[i].status != IN)
            ++i;
        if (i + 1 < n and record[i + 1].status == OUT and
            record[i + 1].plate == record[i].plate)
            for (int j = 0; j < 2; ++j)
                record[validCnt++] = record[i + j];
    }

    int longestPark = 0; // 计算在校园内的最长时间
    for (int i = 0; i < validCnt; i += 2) {
        parkTime[record[i].plate] += record[i + 1].timeStamp - record[i].timeStamp;
        longestPark = max(longestPark, parkTime[record[i].plate]);
    }

    sort(record, record + validCnt, cmp); // query
    for (int i = 0, j = 0, cnt = 0; i < k; ++i) {
        string time;
        cin >> time;

        for (; j < validCnt and timeStamp(time) >= record[j].timeStamp; ++j) {
            if (record[j].status == 0)
                ++cnt;
            else
                --cnt;
        }

        printf("%d\n", cnt);
    }

    for (auto &e : parkTime) { // map内部会按照车牌排序
        if (longestPark == e.second)
            cout << e.first << " ";
    }
    printf("%02d:%02d:%02d", longestPark / 3600, (longestPark % 3600) / 60, longestPark % 60);
}

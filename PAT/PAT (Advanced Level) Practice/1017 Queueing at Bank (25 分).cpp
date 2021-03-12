#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define timestamp(h, m, s) (((h) * 60 + (m)) * 60 + (s))

struct Customer {
    int arriveTime, processTime;

    bool operator<(const Customer& x) const {
        return arriveTime < x.arriveTime;
    }
}customer[10005];

int n, k;

int main() {
    scanf("%d %d\n", &n, &k);
    for (int i = 0; i < n; ++i) {
        int h, m, s;
        scanf("%d:%d:%d %d", &h, &m, &s, &customer[i].processTime);

        customer[i].arriveTime = timestamp(h, m, s);
        if (customer[i].processTime > 60) customer[i].processTime = 3600;
        else customer[i].processTime *= 60;
    }

    sort(customer, customer + n);

    int startTime = timestamp(8, 0, 0);
    int endTime = timestamp(17, 0, 0);

    // 用优先队列得到最先空闲的窗口
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; ++i) pq.push(startTime);

    int serveCnt = 0;
    double totalWaitTime = 0;
    for (int i = 0; i < n; ++i) {
        if (customer[i].arriveTime > endTime) break;

        int availableTime = pq.top();
        pq.pop();

        ++serveCnt;

        int serveTime = max(availableTime, customer[i].arriveTime);
        totalWaitTime += serveTime - customer[i].arriveTime;
        availableTime = serveTime + customer[i].processTime;

        pq.push(availableTime);
    }

    if (serveCnt == 0) printf("0.0\n");
    else printf("%.1f", totalWaitTime / serveCnt / 60);
}
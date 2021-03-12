#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define time2Minute(h, m) ((h)*60 + (m))

const int startTime = time2Minute(8, 0);
const int endTime = time2Minute(17, 0);

struct Customer {
    int process;                                    // 服务时长
    int serveTime = endTime;                        // 被服务的时刻
    int doneTime() {
        return serveTime + process;
    }  // 完成服务的时刻
} customer[1005];

struct Window {
    int index;
    int finishTime = startTime;  // 当前队列全部完成服务的时刻
    queue<Customer*> waitQ;      // 当前窗口的队列

    int nextTime() const {  // 队列中第一个用户服务完成时间
        return waitQ.empty() ? finishTime : waitQ.front()->doneTime();
    }

    void addCustomer(Customer& c) {
        waitQ.push(&c);
        c.serveTime = finishTime;
        finishTime += c.process;
    }
} window[25];

struct cmp {
    bool operator()(const Window* a, const Window* b) {
        if (a->nextTime() != b->nextTime())
            return a->nextTime() > b->nextTime();
        else
            return a->index > b->index;
    }
};

int main() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;

    for (int i = 0; i < n; ++i) window[i].index = i;
    for (int i = 1; i <= k; ++i) cin >> customer[i].process;

    int nextId = 1;

    // 前 n * m 个用户直接进入黄线前等待被服务
    for (int i = 0; i < m and nextId <= k; ++i)
        for (int j = 0; j < n and nextId <= k; ++j)
            window[j].addCustomer(customer[nextId++]);

    // 优先队列用来得到最先完成服务的窗口
    priority_queue<Window*, vector<Window*>, cmp> pq;
    for (int i = 0; i < n; ++i) pq.push(&window[i]);

    // 从第 n * m + 1 个客户开始，需要等待某个窗口处理完成后才能进入黄线前排队
    while (nextId <= k) {
        Customer& c = customer[nextId++];
        Window& w = *pq.top();
        pq.pop();

        w.waitQ.pop();
        w.addCustomer(c);

        pq.push(&w);
    }

    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;

        Customer& c = customer[x];
        if (c.serveTime < endTime) {
            printf("%02d:%02d\n", c.doneTime() / 60, c.doneTime() % 60);
        }
        else
            cout << "Sorry\n";
    }
}
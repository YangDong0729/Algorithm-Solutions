#include <algorithm>
#include <iostream>

using namespace std;

struct node {
    int address, data, next;
} nodes[100005], list[100005];

int main() {
    int head, n, k, addr;
    cin >> head >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> addr;
        nodes[addr].address = addr;
        cin >> nodes[addr].data >> nodes[addr].next;
    }

    int len = 0;
    for (int iter = head; iter != -1; iter = nodes[iter].next)  // 获得链表
        list[len++] = nodes[iter];
    for (int i = k; i <= len; i += k)  // 分组倒置
        reverse(list + i - k, list + i);
    for (int i = 0; i < len - 1; ++i)
        printf("%05d %d %05d\n", list[i].address, list[i].data, list[i + 1].address);
    printf("%05d %d -1\n", list[len - 1].address, list[len - 1].data);
}
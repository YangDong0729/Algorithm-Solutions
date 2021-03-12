#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Record {
    string name;
    int timestamp, month, day, hour, minute, status;

    bool operator<(const Record& x) const {
        if (name != x.name) return name < x.name;
        else return timestamp < x.timestamp;
    }
}record[1005];

int rate[25];

double fakeBill(Record& r) {  // 计算从本月00:00:00开始到r时所需的费用
    double bill = rate[24] * r.day * 60 + rate[r.hour] * r.minute;
    for (int i = 0; i < r.hour; ++i) bill += rate[i] * 60;
    return bill / 100;
}

int main() {
    for (int i = 0; i < 24; ++i) {
        cin >> rate[i];
        rate[24] += rate[i];  // rate[24]存放通话一整天的费用
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> record[i].name;
        scanf("%d:%d:%d:%d", &record[i].month, &record[i].day, &record[i].hour, &record[i].minute);
        string status;
        cin >> status;
        record[i].timestamp = record[i].day * 24 * 60 + record[i].hour * 60 + record[i].minute;
        record[i].status = status == "on-line";
    }

    sort(record, record + n);

    // 选出合理的记录
    int validCnt = 0;
    for (int i = 1; i < n; ++i) {
        if (record[i - 1].name == record[i].name and record[i - 1].status == 1 and record[i].status == 0) {
            record[validCnt++] = record[i - 1];
            record[validCnt++] = record[i];
        }
    }

    for (int i = 0; i < validCnt;) {
        int j = i + 1;
        while (j < validCnt and record[j].name == record[i].name) ++j;

        printf("%s %02d\n", record[i].name.c_str(), record[i].month);

        double totalBill = 0;
        for (int k = i; k < j; k += 2) {
            double bill = fakeBill(record[k + 1]) - fakeBill(record[k]);
            totalBill += bill;

            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
                record[k].day, record[k].hour, record[k].minute,
                record[k + 1].day, record[k + 1].hour, record[k + 1].minute,
                record[k + 1].timestamp - record[k].timestamp, bill);
        }
        printf("Total amount: $%.2f\n", totalBill);
        i = j;
    }
}
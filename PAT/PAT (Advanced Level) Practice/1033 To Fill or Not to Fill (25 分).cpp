#include <iostream>
#include <algorithm>

using namespace std;

struct Station {
	double price, dist;
} station[600];

int main() {
	int n;
	double tank_cap, dist, unit_dist, dist_can_go, gone = 0, left_fuel = 0, cost = 0;

	cin >> tank_cap >> dist >> unit_dist >> n;
	dist_can_go = tank_cap * unit_dist;

	for (int i = 0; i < n; ++i) cin >> station[i].price >> station[i].dist;
	sort(station, station + n, [](Station& a, Station& b) { return a.dist < b.dist; });

	if (station[0].dist != 0) {
		cout << "The maximum travel distance = 0.00";
		return 0;
	}

	station[n].dist = dist;

	for (Station* iter = station, *next; iter != station + n;) {
		if ((iter + 1)->dist > gone + dist_can_go) {
			printf("The maximum travel distance = %.2f", gone + dist_can_go);
			return 0;
		}

		next = iter + 1;
		for (auto i = next; i <= station + n and i->dist <= gone + dist_can_go; ++i) {
			if (i->price <= next->price) {
				next = i;  // next是所有能到达中价格最低中最远的
				if (i->price <= iter->price) break;  // 找到比当前站价格更低的，必到达
			}
		}

		double len = next->dist - iter->dist, fuel = len / unit_dist;
		if (next->price <= iter->price) {  // 在当前站尽量不加油
			left_fuel -= fuel;
			if (left_fuel < 0) {
				cost += (-left_fuel) * iter->price;
				left_fuel = 0;
			}
		}
		else {  // 在当前站加满油
			cost += (tank_cap - left_fuel) * iter->price;
			left_fuel = tank_cap - fuel;
		}

		gone += len;
		iter = next;
	}
	printf("%.2f", cost);
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class gasstation {
public:
	gasstation(){}
	gasstation(int a, int b) {
		this->a = a;
		this->b = b;
	}
	int a;
	int b;
	bool operator<(const gasstation gas) const {
		return this->a > gas.a;
	}
};
bool compare(gasstation gas1, gasstation gas2) {
	return gas1.a < gas2.a;
}
int cnt = 0;
int l, p;
int n;
gasstation arr[10000];
priority_queue<int> pq;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[i] = gasstation(a, b);
	}
	sort(arr, arr + n, compare);
	cin >> l >> p;
	int i = 0;
	while (p < l) {
		for (i; i < n; i++) {
			if (arr[i].a > p) {
				if (pq.empty()) {
					cnt = -1;
					break;
				}
			}
			else {
				pq.push(arr[i].b);
			}
			while (p < arr[i].a) {
				if (pq.empty()) {
					cnt = -1;
					break;
				}
				p += pq.top(); pq.pop();
				cnt++;
				if (arr[i].a <= p) {
					pq.push(arr[i].b);
				}
			}
			if (cnt == -1) break;
		}
		while (p <l) {
			if (pq.empty()) {
				cnt = -1;
				break;
			}
			p += pq.top(); pq.pop();
			cnt++;
		}
		if (cnt == -1) break;
	}
	cout << cnt << endl;
}
#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T; cin >> T;
	while (T--) {
		priority_queue<int, vector<int>, greater<int>>pq_s;
		priority_queue<int>pq_b;
		map<int, int>m;
		int k; cin >> k;
		while (k--) {
			char tmp; int tmp2;
			cin >> tmp >> tmp2;
			if (tmp == 'I') {
				pq_s.push(tmp2);
				pq_b.push(tmp2);
				m[tmp2]++;
			}
			else {
				if (tmp2 == 1) {
					if (!pq_b.empty()) {
						m[pq_b.top()]--;
						pq_b.pop();
					}
				}
				else {
					if (!pq_s.empty()) {
						m[pq_s.top()]--;
						pq_s.pop();
					}
				}
				while (!pq_b.empty() && m[pq_b.top()] == 0) pq_b.pop();
				while (!pq_s.empty() && m[pq_s.top()] == 0) pq_s.pop();
			}
		}
		while (!pq_b.empty() && m[pq_b.top()] == 0) pq_b.pop();
		while (!pq_s.empty() && m[pq_s.top()] == 0) pq_s.pop();
		if (pq_b.empty()|| pq_s.empty()) {
			cout << "EMPTY" << endl;
		}
		else {
			while (m[pq_s.top()] == 0) {
				pq_s.pop();
			}
			while (m[pq_b.top()] == 0) {
				pq_b.pop();
			}
			if (pq_b.top() > pq_s.top()) {
				cout << pq_b.top() << " " << pq_s.top() << endl;
			}
			else {
				cout << pq_s.top() << " " << pq_b.top() << endl;
			}
		}
	}
}
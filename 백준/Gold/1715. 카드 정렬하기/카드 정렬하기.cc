#include <iostream>
#include <queue>
using namespace std;
int main() {
	int N; cin >> N;
	priority_queue<int, vector<int>, greater<int>>pq;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}
	if (N == 1) {
		cout << 0 << endl;
		return 0;
	}
	long long sum = 0;
	while (!pq.empty()) {
		if (pq.size() == 1) {
			break;
		}
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();
		sum += first + second;
		pq.push(first + second);
	}
	cout << sum << endl;
}
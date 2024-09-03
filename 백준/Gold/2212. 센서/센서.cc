#include<iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	int sum = 0;
	priority_queue<int>pq;
	for (int i = 1; i < N; i++) {
		pq.push(v[i] - v[i - 1]);
		sum += v[i] - v[i - 1];
	}
	for (int i = 0; i < K-1; i++) {
		if (pq.empty()) break;
		sum -= pq.top();
		pq.pop();
	}
	cout << sum << endl;
}
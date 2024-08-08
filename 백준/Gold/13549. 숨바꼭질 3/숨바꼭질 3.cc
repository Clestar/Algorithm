#include <iostream>
#include<queue>
using namespace std;
int main() {
	int N, K; cin >> N >> K;
	int dist[100001];
	for (int i = 0; i <= 100000; i++) {
		dist[i] = 100000000;
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater< pair<int, int>>> pq;
	pq.push({ 0,N });
	while (!pq.empty()) {
		int cnt = pq.top().first;
		int x = pq.top().second;
		pq.pop();
		if (x == K) {
			cout << cnt << endl;
			return 0;
		}
		if (x - 1 >= 0 && dist[x - 1] > cnt + 1) {
			pq.push({ cnt + 1,x - 1 });
			dist[x - 1] = cnt + 1;
		}
		if (x + 1 <= 100000 && dist[x + 1] > cnt + 1) {
			pq.push({ cnt + 1,x + 1 });
			dist[x + 1] = cnt + 1;
		}
		if (x *2 <= 100000 && dist[x *2] > cnt ) {
			pq.push({ cnt,x  * 2 });
			dist[x*2] = cnt;
		}
	}
}
#include <iostream>
#include <queue>
using namespace std;
int arr[1000];
bool visited[1000];
int main() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		arr[x] = y;
	}
	for (int i = 0; i < M; i++) {
		int x, y; cin >> x >> y;
		arr[x] = y;
	}
	pq.push({ 0,1 });
	while (!pq.empty()) {
		int cnt = pq.top().first;
		int x = pq.top().second;
		if (arr[x] != 0) x = arr[x];
		pq.pop();
		if (x == 100) {
			cout << cnt << endl;
			break;
		}
		cnt++;
		for (int i = 1; i <= 6; i++) {
			if (visited[x + i] == false) {
				pq.push({ cnt,x + i });
				visited[x + i] = true;
			}
		}
	}
}
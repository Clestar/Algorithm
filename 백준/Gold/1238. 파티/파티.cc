#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int arr[1001][1001];
int dist[1001][1001];
int main() {
	int N, M, X; cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		arr[a][b] = c;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dist[i][j] = 1000000000;
		}
	}
	for (int i = 1; i <= N; i++) {
		priority_queue < pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>> pq;
		pq.push({ 0,i });
		while (!pq.empty()) {
			int cost = pq.top().first;
			int x = pq.top().second;
			if (x == X) {
				break;
			}
			pq.pop();
			for (int j = 1; j <= N; j++) {
				if (arr[x][j] == 0) continue;
				int nCost = cost + arr[x][j];
				if (dist[i][j] > nCost) {
					pq.push({ nCost,j });
					dist[i][j] = nCost;
				}
			}
		}
	}
	priority_queue < pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>> pq;
	pq.push({ 0,X });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int x = pq.top().second;
		
		pq.pop();
		for (int j = 1; j <= N; j++) {
			if (arr[x][j] == 0) continue;
			int nCost = cost + arr[x][j];
			if (dist[X][j] > nCost) {
				pq.push({ nCost,j });
				dist[X][j] = nCost;
			}
		}
	}
	int mSum = 0;
	for (int i = 1; i <= N; i++) {
		if (i == X)continue;
		mSum = max(mSum, dist[i][X] + dist[X][i]);
	}
	cout << mSum << endl;
}
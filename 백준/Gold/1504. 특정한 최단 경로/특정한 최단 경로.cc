#include<iostream>
#include<queue>
int arr[801][801];
int dist[801][4];
using namespace std;
int main() {
	priority_queue <pair<int, pair<int, int>>, vector<pair<int,pair<int, int>>>, greater<pair<int,pair<int, int>>>> pq;
	int N, E; cin >> N >> E;
	for (int i = 1; i <= E; i++) {
		int a, b, c; cin >> a >> b >> c;
		arr[a][b] = c;
		arr[b][a] = c;
	}
	int v1, v2; cin >> v1 >> v2;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 4; j++) {
			dist[i][j] = 1000000000;
		}
	}
	if (v1 == 1) {
		pq.push({ 0,{1,1} });
	}
	else {
		pq.push({ 0,{1,0} });
	}
	dist[1][0] = 0;
	while (!pq.empty()) {
		int cnt = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		if (cnt > dist[x][y])continue;
		if (x == N&&y==3) {
			cout << cnt << endl;
			return 0;
		}
		for (int i = 1; i <= N; i++) {
			if (arr[x][i] == 0 || x == i)continue;
			int tmp=y;
			if (v1 == i && y != 1&&y!=3) tmp++;
			else if (v2 == i && y != 2 && y != 3)tmp += 2;
			if (dist[i][tmp] > arr[x][i] + cnt) {
				dist[i][tmp] = arr[x][i] + cnt;
				pq.push({ cnt + arr[x][i],{i,tmp} });
			}
		}
	}
	cout << -1 << endl;
}
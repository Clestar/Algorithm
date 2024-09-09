#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	int cnt = 1;
	while (true) {
		int N; cin >> N;
		if (N == 0)break;
		vector<vector<int>>v(N, vector<int>(N));
		vector<vector<int>>dist(N, vector<int>(N,100000000));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int tmp; cin >> tmp;
				v[i][j] = tmp;
			}
		}
		priority_queue<pair<int, pair<int, int>>, vector< pair<int, pair<int, int>>>, greater< pair<int, pair<int, int>>>>pq;
		pq.push({ v[0][0],{0,0 } });
		dist[0][0] = v[0][0];
		while (!pq.empty()) {
			int cost = pq.top().first;
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();
			if (dist[y][x] < cost)continue;
			if (x == N - 1 && y == N - 1) {
				cout << "Problem " << cnt << ": " << cost << endl;
				cnt++;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
				int nc = cost + v[ny][nx];
				if (dist[ny][nx] > nc) {
					pq.push({ nc,{nx,ny} });
					dist[ny][nx] = nc;
				}
			}
		}
	}
}
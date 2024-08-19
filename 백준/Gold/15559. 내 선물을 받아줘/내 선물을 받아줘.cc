#include<iostream>
#include<queue>
using namespace std;
int arr[1000][1000];
int visited[1000][1000];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char tmp; cin >> tmp;
			if (tmp == 'S')arr[i][j] = 1;
			if (tmp == 'E')arr[i][j] = 0;
			if (tmp == 'N')arr[i][j] = 3;
			if (tmp == 'W')arr[i][j] = 2;
		}
	}
	queue<pair<int, int>>q;
	int total = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 0) {
				total++;
				visited[i][j] = total;
				q.push({ j, i });
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					int nx = x + dx[arr[y][x]];
					int ny = y + dy[arr[y][x]];
					if (visited[ny][nx] == 0) {
						q.push({ nx,ny });
						visited[ny][nx] = total;
					}
					else if (visited[ny][nx] != total) {
						int tmp = visited[ny][nx];
						visited[y][x] = tmp;
						queue<pair<int, int>>q2;
						q2.push({ x,y });
						while (!q2.empty()) {
							int x = q2.front().first;
							int y = q2.front().second;
							q2.pop();
							for (int k = 0; k < 4; k++) {
								int nx = x + dx[k];
								int ny = y + dy[k];
								if (nx < 0 || nx >= M || ny < 0 || ny >= N)continue;
								if (visited[ny][nx] == total) {
									visited[ny][nx] = tmp;
									q2.push({ nx,ny });
								}
							}
						}
						total--;
					}
				}
			}
		}
	}
	cout << total << endl;

}
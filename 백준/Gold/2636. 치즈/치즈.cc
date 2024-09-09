#include <iostream>
#include <queue>
using namespace std;
int arr[100][100];
bool visited[100][100];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp; cin >> tmp;
			arr[i][j] = tmp;
		}
	}
	int day = 0;
	int last = 0;
	while (true) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = false;
			}
		}
		queue<pair<int, int>>q;
		q.push({ 0,0 });
		visited[0][0] = true;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			cnt++;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= M || ny < 0 || ny >= N)continue;
				if (arr[ny][nx] == 1)continue;
				if (visited[ny][nx])continue;
				q.push({ nx,ny });
				visited[ny][nx] = true;
			}
		}
		if (cnt == N * M)break;
		last = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (visited[i][j])continue;
				if (arr[i][j] == 0)continue;
				last++;
				for (int k = 0; k < 4; k++) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (nx < 0 || nx >= M || ny < 0 || ny >= N)continue;
					if (arr[ny][nx] == 1)continue;
					if (visited[ny][nx]==false)continue;
					arr[i][j] = 0;
					break;
				}
			}
		}
		day++;
	}
	cout << day << endl;
	cout << last << endl;
}
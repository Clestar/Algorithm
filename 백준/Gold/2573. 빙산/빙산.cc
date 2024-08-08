#include<iostream>
#include<queue>
using namespace std;
int arr[300][300];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	int N, M; cin >> N >> M;
	int total = 0; queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp; cin >> tmp;
			if (tmp != 0) {
				total++;
				q.push({ j,i });
			}
			arr[i][j] = tmp;
		}
	}
	int size = q.size();
	int year = 1;
	int arr2[300][300];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr2[i][j] = arr[i][j];
		}
	}
	while (!q.empty()) {
		if (size == 0) {
			size = q.size();
			queue<pair<int, int>> q2;
			int cnt = 1;
			q2.push({ q.front().first,q.front().second });
			bool visited[300][300] = { false };
			visited[q.front().second][q.front().first] = true;
				while (!q2.empty()) {
				int x = q2.front().first;
				int y = q2.front().second;
				q2.pop();
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (arr[ny][nx] != 0 && visited[ny][nx] == false) {
						cnt++;
						q2.push({ nx,ny });
						visited[ny][nx] = true;
					}
				}
			}
			if (cnt != size) {
				cout << year << endl;
				return 0;
			}
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					arr2[i][j] = arr[i][j];
				}
			}
			year++;
		}
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (arr2[ny][nx] == 0) {
				arr[y][x]--;
				if (arr[y][x] == 0) break;
			}
		}
		if (arr[y][x] != 0)q.push({ x,y });
		size--;
	}
	cout << 0 << endl;
}
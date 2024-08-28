#include <iostream>
#include <queue>
using namespace std;
int arr[50][50];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int main() {
	int N, M;
	cin >> N >> M;
	int r, c, d;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp; cin >> tmp;
			arr[i][j] = tmp;
		}
	}
	int cnt = 0;
	while (true) {
		
		if (arr[r][c] == 0) {
			arr[r][c] = 2;
			cnt++;
		}
		bool flag = false;
		for (int i = 0; i < 4; i++) {
			int nx = c + dx[i];
			int ny = r + dy[i];
			if (nx < 0 || nx >= M || ny < 0 || ny >= N)continue;
			if (arr[ny][nx] == 0) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			int back = (d + 2) % 4;
			int nx = c + dx[back];
			int ny = r + dy[back];
			if (arr[ny][nx] == 1)break;
			else {
				r = ny;
				c = nx;
				continue;
			}
		}
		else {
			int nd = d-1;
			if (nd < 0)nd = 3;
			d = nd;
			int nx = c + dx[nd];
			int ny = r + dy[nd];
			if (arr[ny][nx] == 0) {
				r = ny;
				c = nx;
				continue;
			}
		}
	}
	
	cout << cnt << endl;
}
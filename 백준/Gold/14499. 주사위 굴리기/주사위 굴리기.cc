#include <iostream>
using namespace std;
int arr[20][20];
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };
int dice[7];
void swap(int a, int b) {
	int tmp = dice[a];
	dice[a] = dice[b];
	dice[b] = tmp;
}
int main() {
	int n, m, x, y, k; cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp; cin >> tmp;
			arr[i][j] = tmp;
		}
	}
	int loc = 0;
	for (int i = 0; i < k; i++) {
		int tmp; cin >> tmp;
		int nx = x + dx[tmp];
		int ny = y + dy[tmp];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
		if (tmp == 1) {
			swap(1, 3);
			swap(1, 4);
			swap(4, 6);
		}
		if (tmp == 2) {
			swap(1, 4);
			swap(1, 3);
			swap(3, 6);
		}
		if (tmp == 3) {
			swap(1, 2);
			swap(1, 5);
			swap(5, 6);
		}
		if (tmp == 4) {
			swap(1, 5);
			swap(1, 2);
			swap(2, 6);
		}
		if (arr[nx][ny] == 0) {
			arr[nx][ny] = dice[6];
		}
		else {
			dice[6] = arr[nx][ny];
			arr[nx][ny] = 0;
		}
		x = nx;
		y = ny;
		cout << dice[1] << endl;
	}
}
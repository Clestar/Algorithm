#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int arr[50][50];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	int r, c, t; cin >> r >> c >> t;
	vector<pair<int, int>> v;
	pair<int, int>bottom;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			int tmp; cin >> tmp;
			arr[i][j] = tmp;
			if (arr[i][j] == -1)v.push_back({ j,i });
		}
	}
	for (int l = 0; l < t; l++) {
		queue < pair<int, pair<int, int>>>q;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (arr[i][j] == -1)continue;
				int cost = arr[i][j] / 5;	
				for (int k = 0; k < 4; k++) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (nx < 0 || nx >= c || ny < 0 || ny >= r|| arr[ny][nx] == -1) continue;
					q.push({ cost, {nx,ny} });
					arr[i][j] -= cost;
				}
			}
		}
		while (!q.empty()) {
			int cost = q.front().first;
			int x = q.front().second.first;
			int y = q.front().second.second;
			q.pop();
			arr[y][x] += cost;
		}
		int top_x = v[0].first;
		int top_y = v[0].second;
		for (int i = top_y-1; i > 0; i--) {
			arr[i][top_x] = arr[i - 1][top_x];
		}
		for (int i = 0; i < c - 1; i++) {
			arr[0][i] = arr[0][i + 1];
		}
		for (int i = 0; i <top_y; i++) {
			arr[i][c-1] = arr[i + 1][c-1];
		}
		for (int i = c - 1; i > 0; i--) {
			if (i == 1) {
				arr[top_y][i] = 0;
				continue;
			}
			arr[top_y][i] = arr[top_y][i - 1];
		}
		int bottom_x = v[1].first;
		int bottom_y = v[1].second;
		for (int i = bottom_y + 1; i < r-1; i++) {
			arr[i][bottom_x] = arr[i + 1][bottom_x];
		}
		for (int i = 0; i <c-1; i++) {
			arr[r-1][i] = arr[r-1][i + 1];
		}
		for (int i = r-1; i >bottom_y; i--) {
			arr[i][c - 1] = arr[i - 1][c - 1];
		}
		for (int i = c - 1; i > 0; i--) {
			if (i == 1) {
				arr[bottom_y][i] = 0;
				continue;
			}
			arr[bottom_y][i] = arr[bottom_y][i - 1];
		}
	}
	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] != -1)sum+=arr[i][j];
		}
	}
	cout << sum << endl;
}
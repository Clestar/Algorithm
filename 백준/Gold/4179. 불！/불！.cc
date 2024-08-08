#include <iostream>
#include <queue>
using namespace std;
int arr[1000][1000];
bool visited[1000][1000];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	int R, C; cin >> R >> C;
	int start_x, start_y;
	queue<pair<int,int>>human;
	queue<pair<int, int>>fire;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char tmp; cin >> tmp;
			if (tmp == 'J') {
				start_x = j;
				start_y = i;
				human.push({ j, i });
				visited[i][j] = true;
			}
			else if (tmp == 'F') {
				fire.push({ j,i });
				arr[j][i] == 0;
			}
			else if (tmp == '#') {
				arr[i][j] = -2;
			}
			else {
				arr[i][j] = -1;
			}
		}
	}
	bool escape = false;
	while (!fire.empty()) {
		int x = fire.front().first;
		int y = fire.front().second;
		int cnt = arr[y][x];
		fire.pop();
		for (int i = 0; i < 4; i++) {
			int next_cnt = cnt + 1;
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x < 0 || next_x >= C || next_y < 0 || next_y >= R)continue;
			if (arr[next_y][next_x] == -2)continue;
			if (arr[next_y][next_x]==-1) {
				arr[next_y][next_x] = next_cnt;
				fire.push({next_x,next_y});
			}
		}
	}
	arr[start_y][start_x] = 0;
	while (!human.empty()) {
		int x = human.front().first;
		int y = human.front().second;
		int cnt = arr[y][x];
		human.pop();
		for (int i = 0; i < 4; i++) {
			int next_cnt = cnt + 1;
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x < 0 || next_x >= C || next_y < 0 || next_y >= R) {
				cout << next_cnt << endl;
				escape = true;
				break;
			}
			if (arr[next_y][next_x] == -2)continue;
			if ((arr[next_y][next_x]==-1)||(arr[next_y][next_x] > next_cnt&&visited[next_y][next_x]==false)) {
				human.push({next_x,next_y});
				arr[next_y][next_x] = next_cnt;
				visited[next_y][next_x] == true;
			}
		}
		if (escape)break;
	}
	if (!escape) {
		cout << "IMPOSSIBLE" << endl;
	}
}
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	int T; cin >> T;
	while (T--) {
		int w, h; cin >> w >> h;
		vector<vector<int>>v (h,vector<int>(w));
		vector<vector<int>>visited(h, vector<int>(w,false));
		queue<pair<int, pair<int,int>>>fire;
		queue<pair<int, pair<int,int>>>human;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				char tmp; cin >> tmp;
				if (tmp == '.') v[i][j] = -1;
				if (tmp == '#') v[i][j] = -2;
				if (tmp == '*') {
					fire.push({ 0,{j,i } });
					v[i][j] = 0;
				}
				if (tmp == '@') {
					human.push({ 0,{j,i } });
					v[i][j] = -1;
					visited[i][j] = true;
				}
			}
		}
			while (!fire.empty()) {
			int cnt = fire.front().first;
			int x = fire.front().second.first;
			int y = fire.front().second.second;
			fire.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= w || ny < 0 || ny >= h)continue;
				if (v[ny][nx] == -2) continue;
				int nc = cnt+1;
				if ( v[ny][nx] == -1) {
					v[ny][nx] = nc;
					fire.push({ nc,{nx,ny} });
				}
			}
		}
		bool flag = true;
		while (!human.empty()) {
			int cnt = human.front().first;
			int x = human.front().second.first;
			int y = human.front().second.second;
			human.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nc = cnt+1;
				if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
					cout << nc << endl; 
					flag = false;
					break;
				}
				if (v[ny][nx] == -2) continue;
				if (visited[ny][nx]==1)continue;
				if (v[ny][nx] > nc || v[ny][nx] == -1) {
					human.push({ nc,{nx,ny} });
					visited[ny][nx] = true;
				}
			}
			if (flag == false) break;
		}
		if (flag) cout << "IMPOSSIBLE" << endl;
	}
}
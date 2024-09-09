#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n; cin >> n;
		vector<vector<int>>v(n, vector<int>(n));
		vector<vector<int>>visited(n, vector<int>(n,false));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int tmp; cin >> tmp;
				v[i][j] = tmp;
			}
		}
		priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>>pq;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][j] != 0 &&visited[i][j]==false) {
					visited[i][j] = true;
					int height = 0, width = 0;
					queue<pair<int, int>>q;
					q.push({ j,i });
					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						height = max(x - j + 1, height);
						width = max(y - i + 1, width);
						for (int i = 0; i < 4; i++) {
							int nx = x + dx[i];
							int ny = y + dy[i];
							if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
							if (visited[ny][nx]==true)continue;
							if (v[ny][nx] == 0)continue;
							q.push({ nx,ny });
							visited[ny][nx] = true;
						}
					}
					pq.push({ height*width,{ width,height } });
				}
			}
		}
		cout << "#" << t << " " << pq.size() << " ";
		while (!pq.empty()) {
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			cout << x << " " << y << " ";
			pq.pop();
		}
		cout << endl;
	}
}
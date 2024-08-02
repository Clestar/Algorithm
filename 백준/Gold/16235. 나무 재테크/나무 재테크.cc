#include<iostream>
#include<queue>
#include<deque>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int arr[11][11];
int m[11][11];
int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int dy[8] = { -1,-1,-1,0,0,1,1,1 };
vector<int> v[11][11];
deque < pair<int, pair<int, int>>> dq;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue< pair<int, int>> q;
	queue< pair<int, pair<int,int>>> q2;
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp; cin >> tmp;
			arr[i][j] = tmp;
			m[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int x, y, z; cin >> x >> y >> z;
		v[x][y].push_back(z);
	}
	while (K-- != 0) {
		vector<int> v2[11][11];
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int age : v[i][j]) {
					if (m[i][j] >= age) {
						v2[i][j].push_back(age + 1);
						m[i][j] -= age;
						if ((age + 1) % 5 == 0) {
							q.push({ j,i });
						}
					}
					else {
						q2.push({ age,{j,i } });
					}
				}
			}
		}
		while (!q2.empty()) {
			int z = q2.front().first;
			int x = q2.front().second.first;
			int y = q2.front().second.second;
			q2.pop();
			m[y][x] += (z / 2);
		}
	
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 8; i++) {
				int next_x = x + dx[i];
				int next_y = y + dy[i];
				if (next_x<1 || next_x>N || next_y<1 || next_y>N)continue;
				v2[next_y][next_x].push_back(1);
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				sort((v2[j][i]).begin(), v2[j][i].end());
				v[j][i] = v2[j][i];
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				m[i][j] += arr[i][j];
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += v[i][j].size();
		}
	}
	cout << ans << endl;
}
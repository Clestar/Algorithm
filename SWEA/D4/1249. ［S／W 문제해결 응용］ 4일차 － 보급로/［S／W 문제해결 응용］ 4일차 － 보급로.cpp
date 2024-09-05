#include <iostream>
#include <queue>
using namespace std;
int arr[100][100];
int visited[100][100];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	int T; cin >> T; 
	int i = 1;
	while (T--) {
		int N; cin >> N;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				visited[j][k] = 1000000000;
				char tmp; cin >> tmp;
				int tmp2 = tmp - '0';
				arr[j][k] = tmp2;
			}
		}
		queue<pair<int, int>> q;
		visited[0][0] = 0;
		q.push(make_pair(0,0));
		while (!q.empty()) {
			pair<int, int> p = q.front();
			int y = p.first;
			int x = p.second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				if (x + dx[j] >= 0 && x + dx[j] < N && y + dy[j] >= 0 && y + dy[j] < N) {
					if (visited[y][x] + arr[y + dy[j]][x + dx[j]] < visited[y + dy[j]][x + dx[j]]) {
						q.push(make_pair(y + dy[j], x + dx[j]));
						visited[y + dy[j]][x + dx[j]] = visited[y][x] + arr[y + dy[j]][x + dx[j]];
					}
				}
			}
		}
		cout << "#" << i << " " << visited[N-1][N-1] << endl;
		i++;
	}
}
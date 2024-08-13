#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;
bool visited[26];
int arr[20][20];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int R, C;
int total = 0;
void dfs(int x, int y,int cnt) {
	total = max(total, cnt);
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
		if (visited[arr[ny][nx]])continue;
		visited[arr[ny][nx]] = true;
		dfs(nx, ny, cnt+1);
		visited[arr[ny][nx]] = false;
	}
	return;
}
int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string tmp; cin >> tmp;
		for (int j = 0; j < tmp.length(); j++) {
			arr[i][j] = tmp[j]-'A';
		}
	}
	visited[arr[0][0]] = true;
	dfs(0, 0, 1);
	cout << total << endl;
}
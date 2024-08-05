#include <iostream>
#include <vector>
using namespace std;

char color[101][101];
int visited[101][101];
int w_sum, b_sum = 0;
int w_c, b_c = 0;
int n, m;

void dfs(int j, int k, char c) {
	if (j <= m && k <= n && j > 0 && k > 0) {
		visited[j][k] = 1;
		if (c == 'W') w_c++;
		if (c == 'B') b_c++;
		if (j <= m - 1) {
			if (color[j + 1][k]== c && !(visited[j + 1][k]))
				dfs(j + 1, k, c);
		}
		if (j > 1) {
			if (color[j - 1][k] == c && !(visited[j - 1][k]))
				dfs(j - 1, k, c);
		}
		if (k <= n - 1) {
			if (color[j][k + 1] == c && !(visited[j][k + 1]))
				dfs(j, k + 1, c);
		}
		if (k > 1) {
			if (color[j][k - 1] == c && !(visited[j][k - 1]))
				dfs(j, k - 1, c);
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			color[i][j] = c;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (!(visited[i][j])) {
				dfs(i, j, color[i][j]);
				w_sum += (w_c*w_c);
				b_sum += (b_c*b_c);
				w_c = 0;
				b_c = 0;
			}
		}
	}
	cout << w_sum << " " << b_sum << endl;
}
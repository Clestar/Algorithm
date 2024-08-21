#include <iostream>
#include <algorithm>
using namespace std;
int arr[101][101];
int main() {
	int n; cin >> n;
	int m; cin >> m;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			arr[i][j] = 1000000000;
			if (i == j)arr[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = min(c,arr[a][b]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] >= 1000000000)arr[i][j] = 0;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
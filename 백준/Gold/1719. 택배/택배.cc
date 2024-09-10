#include <iostream>
#include <algorithm>
using namespace std;
int arr[201][201];
int arr2[201][201];
int main() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = 1000000000;
			arr2[i][j] = j;
			if (i == j)arr[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		arr[a][b] = c;
		arr[b][a] = c;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (arr[j][k] > arr[j][i] + arr[i][k]) {
					arr2[j][k] = arr2[j][i];
					arr[j][k] = arr[j][i] + arr[i][k];
				}
				
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i==j) {
				cout << "- ";
			}
			else {
				cout << arr2[i][j] << " ";
			}
		}
		cout << endl;
	}
}
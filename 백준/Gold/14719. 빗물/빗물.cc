#include <iostream>
using namespace std;
int arr[500][500];
int main() {
	int H, W; cin >> H >> W;
	for (int i = 0; i < W; i++) {
		int tmp; cin >> tmp;
		for (int j = 0; j < tmp; j++) {
			arr[j][i] = -1;
		}
	}
	int cnt = 0;
	bool flag = false;
	int start;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (arr[i][j] == -1) {
				if (!flag) {
					flag = true;
					start = j;
				}
				else {
					if (j - start - 1 != 0) {
						cnt += j - start - 1;
						start = j;
					}
					else {
						start = j;
					}
				}
			}
		}
		flag = false;
		start = 0;
	}
	cout << cnt << endl;
}
#include <iostream>
#include <math.h>
using namespace std;

int arr[15][15];
bool checkY[15];
bool l[46];
bool r[46];
int N; 
int cnt = 0;
void dfs(int x, int y) {
	if (y == N - 1) {
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (checkY[i] || r[y + 1 + i] || l[i-(y+1)+15]) continue;
		checkY[i] = true;
		l[i - (y + 1) + 15] = true;
		r[y + 1 + i] = true;
		dfs(i, y+1);
		checkY[i] = false;
		l[i - (y + 1) + 15] = false;
		r[y + 1 + i] = false;
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		checkY[i] = true;
		l[i+15] = true;
		r[i] = true;
		dfs(i, 0);
		checkY[i] = false;
		l[i+15] = false;
		r[i] = false;
	}
	cout << cnt << endl;
}
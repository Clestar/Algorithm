#include <iostream>
#include <algorithm>
using namespace std;
int arr[200001];
int main() {
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		int tmp; cin >> tmp;
		arr[i] = tmp;
	}
	int len = 0;
	for (int i = 1; i < N; i++) {
		if (len > N - i) break;
		int cnt = 1;
		int first = arr[i];
		int second = -1;
		int idx = i;
		for (int j = i+1; j <= N; j++) {
			if (arr[j] != arr[j - 1]) {
				if (second == -1) {
					second = arr[j];
				}
				else if (arr[j] != first&&arr[j]!=second) {
					break;
				}
				idx = j;
			}
			cnt++;
		}
		i = idx-1;
		len = max(len, cnt);
	}
	if (N == 1)len = 1;
	cout << len << endl;
}
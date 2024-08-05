#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[51][51];
int main() {
	vector<pair<int,int>> h;
	vector<pair<int, int>> c;
	vector<int>tmp;
	int N, M; cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp; cin >> tmp;
			arr[i][j] = 100000000;
			if (tmp == 2) {
				c.push_back({ i, j });
			}
			else if (tmp == 1) {
				h.push_back({ i,j });
			}
		}
	}
	
	for (int i = 0; i < c.size() - M; i++) {
		tmp.push_back(0);
	}
	for (int i = 0; i < M; i++) {
		tmp.push_back(1);
	}
	int total = 100000000;
	do {

		for (int i = 0; i < tmp.size(); i++) {
			if (tmp[i] == 1) {
				int cx = c[i].second;
				int cy = c[i].first;
				for (int j = 0; j < h.size(); j++) {
					int x = h[j].second;
					int y = h[j].first;
					int dist_x = cx - x;
					int dist_y = cy - y;
					if (dist_x < 0)dist_x *= -1;
					if (dist_y < 0)dist_y *= -1;
					int dist = dist_x + dist_y;
					if (arr[y][x] > dist)arr[y][x] = dist;
				}
			}
		}
		int sum = 0;

		for (int j = 0; j < h.size(); j++) {
			int x = h[j].second;
			int y = h[j].first;
			sum += arr[y][x];
			arr[y][x] = 100000000;
		}
		total = min(total, sum);
	} while (next_permutation(tmp.begin(), tmp.end()));
	
	cout << total << endl;
}
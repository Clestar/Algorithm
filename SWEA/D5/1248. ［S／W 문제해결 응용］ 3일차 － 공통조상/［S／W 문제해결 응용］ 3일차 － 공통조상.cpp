#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;
int main() {
	int t; cin >> t;
	for (int T = 1; T <= t; T++) {
		int v, e, a, b;
		cin >> v >> e >> a >> b;
		vector<vector<int>>vec(v+1);
		map<int, int>m;
		for (int i = 0; i < e; i++) {
			int tmp, tmp2; cin >> tmp >> tmp2;
			vec[tmp].push_back(tmp2);
		}
		int idx = a;
		int node = 0;
		int size = 0;
		while (true) {
			if (idx == 1) {
				m[1] = 1;
				break;
			}
			else {
				for (int i = 1; i <= e; i++) {
					bool flag = false;
					for (int j = 0; j < vec[i].size(); j++) {
						if (vec[i][j] == idx) {
							m[i] = 1;
							idx = i;
							flag = true;
							break;
						}
					}
					if (flag) break;
				}
			}
		}
		idx = b;
		while (true) {
			if (node != 0)break;
			if (idx == 1) {
				m[1] = 1;
				break;
			}
			else {
				for (int i = 1; i <= e; i++) {
					bool flag = false;
					for (int j = 0; j < vec[i].size(); j++) {
						if (vec[i][j] == idx) {
							if (m[i] == 1) {
								node = i;
								flag = true; break;
							}
							m[i] = 1;
							idx = i;
							flag = true;
							break;
						}
					}
					if (flag) break;
				}
			}
		}
		queue<int> q;
		q.push(node);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			size++;
			for (int i = 0; i < vec[x].size(); i++) {
				q.push(vec[x][i]);
			}
		}
		cout << "#" << T << " " << node << " " << size << endl;
	}
}
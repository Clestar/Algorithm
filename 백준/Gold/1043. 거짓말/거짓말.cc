#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool visited[51];
bool visited2[51];
int main() {
	int N, M; cin >> N >> M;
	int a; cin >> a;
	queue<int> q;
	vector<vector<int>>v(M);
	vector<int> v2;
	for (int i = 1; i <= a; i++) {
		int tmp; cin >> tmp;
		q.push(tmp);
		visited2[tmp] = true;
	}
	for (int i = 0; i < M; i++) {
		int tmp2; cin >> tmp2;
		for (int j = 0; j < tmp2; j++) {
			int tmp3; cin >> tmp3;
			v[i].push_back(tmp3);
		}
	}
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < M; i++) {
			if (visited[i])continue;
			for (int j = 0; j < v[i].size(); j++) {
				if (x == v[i][j]) {
					visited[i] = true;
					for (int k = 0; k < v[i].size(); k++) {
						if (visited2[v[i][k]] == false) {
							visited2[v[i][k]] = true;
							q.push(v[i][k]);
						}
					}
					break;
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		if (visited[i] == false) {
			cnt++;
		}
	}
	cout << cnt << endl;
}
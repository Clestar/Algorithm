#include <iostream>
#include<vector>
#include<map>
#include<deque>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	int N, K; cin >> N >> K;
	vector<vector<int>> v(N+1, vector<int>(N+1));
	for (int i = 0; i < K; i++) {
		int a, b; cin >> a >> b;
		v[a][b] = 1;
	}
	map<int, char>m;
	int L; cin >> L;
	for (int i = 0; i < L; i++) {
		int tmp;
		char tmp2;
		cin >> tmp;
		cin>>tmp2;
		m[tmp] = tmp2;
	}
	int cnt = 0;
	int dir = 0;
	deque<pair<int, int>>q;
	q.push_back({ 1,1 });
	while (true) {
		int head_x = q.back().first + dx[dir];
		int head_y = q.back().second + dy[dir];
		cnt++;
		if (head_x > N || head_x <= 0 || head_y > N || head_y <= 0) break;
		if (v[head_y][head_x] == 2) break;
		q.push_back({ head_x,head_y });
		if (v[head_y][head_x] == 0) {
			v[q.front().second][q.front().first] = 0;
			q.pop_front();
		}
		v[head_y][head_x] = 2;
		if(m[cnt]=='L'){
			dir--;
			if (dir < 0) dir += 4;
			dir %= 4;
		}
		else if(m[cnt]=='D') {
			dir++;
			dir %= 4;
		}
		/*
		cout << cnt << endl;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cout << v[i][j] << " ";
			}
			cout << endl;
		}
		*/
		
	}
	cout << cnt << endl;
}
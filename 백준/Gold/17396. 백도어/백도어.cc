#include <iostream>
#include <queue>
#include<vector>
using namespace std;
bool visited[100000];
long long dist[100000];
int main() {
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		dist[i] = 1000000000000;
		if (tmp == 0)visited[i] = true;
	}
	vector<vector<pair<int,int>>>v(N);
	for (int j = 0; j < M; j++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	priority_queue<pair<long long , int>, vector<pair<long long , int>>, greater<pair<long long, int>>>pq;
	pq.push({ 0,0 });
	dist[0] = 0;
	while (!pq.empty()) {
		long long cost = pq.top().first;
		int x = pq.top().second;
		pq.pop();
		if (dist[x] != cost)continue;
		if (x == N - 1) {
			cout << cost << endl;
			return 0;
		}
		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i].first;
			long long nc = v[x][i].second + cost;
			if (visited[nx] == false&&nx!=N-1)continue;
			if (dist[nx] > nc) {
				pq.push({ nc,nx });
				dist[nx] = nc;
			}
		}
	}
	cout << -1 << endl;
}
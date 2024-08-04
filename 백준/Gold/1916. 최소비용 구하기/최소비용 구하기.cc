#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> v[1001][1001];
int dist[1001];
bool visited[1001];
int main() {
	int N, M; cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		dist[i] = 1000000000;
	}
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		v[a][b].push_back(c);
	}
	int A, B; cin >> A >> B;
	pq.push({ 0,A });
	dist[A] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int x = pq.top().second;
		if (x == B) {
			cout << cost << endl;
			break;
		}
		pq.pop();
		if (visited[x])continue;
		visited[x] = true;
		
		
		
		for (int i = 1; i <= N; i++) {
			if (i == x)continue;
			for (int j = 0; j < v[x][i].size(); j++) {
				int n_cost = cost + v[x][i][j];
				if (!visited[i]) {
					pq.push({ n_cost,i });
					dist[i] = n_cost;

				}
			}
			
		}
	}
}
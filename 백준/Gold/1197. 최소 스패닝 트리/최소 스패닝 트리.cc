#include<iostream>
#include <queue>
#include <vector>
using namespace std;
bool visited[10001];
int main() {
	int v, e; cin >> v >> e;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	vector<vector<pair<int, int>>>vec(v + 1);
	for (int i = 1; i <= e; i++) {
		int a, b, c; cin >> a >> b >> c;
		vec[a].push_back({ b,c });
		vec[b].push_back({ a,c });
	}
	pq.push({ 0,1 });
	int size = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int x = pq.top().second;
		pq.pop();
		if (visited[x]) continue;
		visited[x] = true;
		size += cost;
		for (int i = 0; i < vec[x].size(); i++) {
			if (visited[vec[x][i].first]) continue;
			pq.push({ vec[x][i].second,vec[x][i].first });
		}
	}
	cout << size << endl;
}
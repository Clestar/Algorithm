#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int V, E; cin >> V >> E;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int >>> pq;
	vector<vector<pair<int,int>>>v(20001);
	int dist[20001];
	for (int i = 1; i <= 20000; i++) {
		dist[i] = 1000000000;
	}
	int start; cin >> start;
	
	for (int i = 0; i < E; i++) {
		int a, b, c; cin >> a >> b >> c;
		if(v[a].size()==0)v[a].push_back({ b,c });
		else {
			bool flag = false;
			v[a].push_back({ b,c });
		}
	}
	dist[start] = 0;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int x = pq.top().second;
		pq.pop();
		if (cost > dist[x])continue;
		for (int i = 0; i < v[x].size(); i++) {
			int nCost = v[x][i].second+cost;
			if (dist[v[x][i].first] > nCost) {
				pq.push({ nCost,v[x][i].first });
				dist[v[x][i].first] = nCost;
			}
		}

	}
	for (int i = 1; i <= V; i++) {
		if(dist[i]!= 1000000000) cout << dist[i] << endl;
		else cout << "INF" << endl;
	}
}
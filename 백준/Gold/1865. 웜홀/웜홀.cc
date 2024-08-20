#include <iostream>
#include <vector>
using namespace std;
int dist[501];
int main() {
	int TC; cin >> TC;
	while (TC--) {
		ios::sync_with_stdio(false);
		cin.tie(0);
		int N, M, W; cin >> N >> M >> W;
		vector<pair<int, pair<int, int>>>v;
		
		for (int i = 0; i < M; i++) {
			int S, T, E; cin >> S >> E >> T;
			v.push_back({ T,{S,E} });
			v.push_back({ T,{E,S} });
		}
		for (int i = 0; i < W; i++) {
			int S, T, E; cin >> S >> E >> T;
			v.push_back({ -T,{S,E} });
		}
		for (int i = 1; i <= N; i++) {
			dist[i] = 1000000000;
		}
		bool flag = false;
		for (int i = 1; i <= N; i++) {
			dist[i] = 1000000000;
		}
		dist[1] = 0;
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < v.size(); j++) {
				int s = v[j].second.first;
				int e = v[j].second.second;
				int w = v[j].first;
				if (dist[s] + w < dist[e]) {
					dist[e] = dist[s] + w;
				}
			}
		}

		for (int j = 0; j < v.size(); j++) {
			int s = v[j].second.first;
			int e = v[j].second.second;
			int w = v[j].first;
			if (dist[s] + w < dist[e]) {
				flag = true;
				break;
			}
		}
		if (flag)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
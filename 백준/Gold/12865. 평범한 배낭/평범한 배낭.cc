#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[101][100001];
int main() {
	int N, K;
	cin >> N >> K;
	vector<pair<int, int>>v;
	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j < v[i - 1].first) dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = max(dp[i - 1][j - v[i - 1].first] + v[i - 1].second, dp[i - 1][j]);
			}
		}
	}
	cout << dp[N][K] << endl;
}
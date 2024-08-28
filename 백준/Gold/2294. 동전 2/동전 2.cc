#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n, k; cin >> n >> k;
	vector<int>c;
	map<int, int>m;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		if(m[tmp]!=1) c.push_back(tmp);
		m[tmp] = 1;
	}
	int size = c.size();
	vector<int>dp(10001, 100000);
	dp[0] = 0;
	for (int i = 0; i < size; i++) {
		for (int j = c[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - c[i]]+1);
		}
	}
	if (dp[k] == 100000)cout << -1 << endl;
	else
	cout << dp[k] << endl;
}
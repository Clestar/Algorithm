#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string num;
int max_cnt, answer;

void dfs(int idx, int cnt) {
	if (cnt == max_cnt) {
		answer = max(answer, stoi(num));
		return;
	}
	for (int i = idx; i < num.length() - 1; i++) {
		for (int j = i + 1; j < num.length(); j++) {
			if (num[i] <= num[j]) {
				swap(num[i], num[j]);
				dfs(i, cnt + 1);
				swap(num[i], num[j]);
			}
			if (i == num.length() - 2 && j == num.length() - 1) {
				swap(num[i], num[j]);
				dfs(i, cnt + 1);
				swap(num[i], num[j]);
			}
		}
	}
}

int main() {
	int t; cin >> t;


	for (int T = 1; T <= t; T++)
	{
		cin >> num >> max_cnt;
		answer = 0;
		dfs(0, 0);
		cout << "#" << T << " " << answer << "\n";
	}
	return 0;
}
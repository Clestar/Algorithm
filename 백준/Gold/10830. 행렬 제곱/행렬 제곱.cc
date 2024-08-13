#include <iostream>
#include <vector>
#include<algorithm>
#include<math.h>
using namespace std;
vector<vector<vector<int>>>v;
int N;
long long B;
void calc(int n) {
	vector<vector<int>> v2(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			v2[i][j] = 0;
			for (int k = 0; k < N; k++) {
				v2[i][j] += v[n][i][k] * v[n][k][j];
				v2[i][j] %= 1000;
			}
		}
	}
	v.push_back(v2);
}
int main() {
	cin >> N >> B;
	vector<vector<int>> v2(N,vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;
			v2[i][j] = tmp%1000;
		}
	}
	v.push_back(v2);	
	long long cnt = 1;
	while (pow(2,cnt) <= B) {
		calc(cnt-1);
		cnt++;
	}
	vector<vector<int>> ans;
	long long comp = 1;
	cnt = 0;
	while (comp <= B) {
		if ((comp&B) == comp) {
			if (ans.size() == 0) {
				ans = v[cnt];
			}
			else {
				vector<vector<int>> tmp = ans;
				vector<vector<int>> tmp2 = v[cnt];
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						ans[i][j] = 0;
						for (int k = 0; k < N; k++) {
							ans[i][j] += tmp[i][k] * tmp2[k][j];
							ans[i][j] %= 1000;
						}
					}
				}
			}
		}
		cnt++;
		comp = comp << 1;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}
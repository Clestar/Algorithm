#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int N, M; cin >> N >> M;
	vector<int> v;
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}
	vector<int> v2;
	for (int i = 1; i <= M; i++) {
		v2.push_back(0);
	}
	for (int i = 1; i <= N - M; i++) {
		v2.push_back(1);
	}
	
	
	do {
		for (int i = 0; i < v2.size(); i++) {
			if (v2[i] == 0) {
				cout << v[i] << " ";
			}
		}
		cout << endl;
	} while (next_permutation(v2.begin(), v2.end()));
}
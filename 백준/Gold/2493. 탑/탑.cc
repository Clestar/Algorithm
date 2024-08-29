#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main() {
	int N; cin >> N;
	vector<int> tower;
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		tower.push_back(tmp);
	}
	stack<pair<int,int>>st;
	for (int i = N-1; i >= 0; i--) {
		int tmp = tower[i];
		if (st.empty())st.push({ tmp,i });
		else {
			while (!st.empty()&&st.top().first < tmp) {
				tower[st.top().second] = i+1;
				st.pop();
			}
			st.push({ tmp,i });
		}
	}
	while (!st.empty()) {
		tower[st.top().second] = 0;
		st.pop();
	}
	for (int i = 0; i < N; i++) {
		cout << tower[i] << " ";
	}
	cout << endl;
}
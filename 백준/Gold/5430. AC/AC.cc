#include<iostream>
#include<string>
#include<deque>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T; cin >> T;
	while (T--) {
		deque<int>dq;
		string s; cin >> s;
		int cnt; cin >> cnt;
		char left, right; cin >> left;
		for (int i = 0; i < cnt; i++) {
			int tmp; cin >> tmp;
			dq.push_back(tmp);
			if (i != cnt - 1) {
				char tmp2; cin >> tmp2;
			}
		}
		cin >> right;
		bool reverse = false;
		bool err = false;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'R') {
				if (!reverse) reverse = true;
				else reverse = false;
			}
			else {
				if (dq.empty()) {
					err = true;
					cout << "error" << endl;
					break;
				}
				if (!reverse) {
					dq.pop_front();
				}
				else {
					dq.pop_back();
				}
			}
		}
		if (err) continue;
		cout << left;
		while (!dq.empty()) {
			if (!reverse) {
				cout << dq.front();
				dq.pop_front();
			}
			else {
				cout << dq.back();
				dq.pop_back();
			}
			if (!dq.empty()) cout << ",";
		}
		cout << right << endl;
	}
}
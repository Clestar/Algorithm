#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main() {
	int N; cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}
	int subMin = 2100000000;
	pair<int, int> p;
	for (int i = 0; i < N; i++) {
		int left = 0;
		int right = N - 1;
		int mid = (left + right) / 2;
		int first = v[i];
		while (true) {
			if (left > right)break;
			int sum = first + v[mid];
			if (first!=v[mid]&&subMin > abs(sum)) {
				p.first = first;
				p.second = v[mid];
				subMin = abs(sum);
			}
			if (first != v[mid] && sum == 0) {
				cout << first << " " << v[mid] << endl;
				return 0;
			}
			if (sum > 0) {
				right = mid-1;
				mid = (left + right) / 2;
			}
			else {
				left = mid+1;
				mid = (left + right) / 2;
			}
		}
	}
	if (p.first > p.second) {
		cout << p.second << " " << p.first << endl;
	}
	else {
		cout << p.first << " " << p.second << endl;
	}
	
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N; cin >> N;
	vector<int> v(N);
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		sum += tmp;
		v[i] = tmp;
	}
	sort(v.begin(), v.end());
	if (sum % 3 != 0) {
		cout << "NO" << endl;
	}
	else {
		int a = 0;
		int b = 0;
		for (int i = 0; i < N; i++) {
			if (a != b) {
				while (a > b) {
					if (v[i] - 2 > 0) {
						b++;
						v[i] -= 2;
					}
					else break;
				}
				while (a < b) {
					if (v[i] - 1 > 0) {
						a++;
						v[i] -= 1;
					}
					else break;
				}
			}
			if (v[i] % 3 == 1) {
				a++;
			}
			else if (v[i] % 3 == 2) {
				b++;
			}
		}
		if (a == b)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
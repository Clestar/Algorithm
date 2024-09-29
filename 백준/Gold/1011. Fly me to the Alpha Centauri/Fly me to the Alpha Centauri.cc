#include <iostream>
using namespace std;
int main() {
	int T;
	cin >> T;
	while (T--) {
		long long int x, y;
		cin >> x >> y;
		long long int z = y - x;
		long long int cnt = 0;
		long long int a = 1;
		while (true) {
			z -= a;
			cnt++;
			if (z <= 0) {
				break;
			}
			z -= a;
			a++;
			cnt++;
			if (z <= 0) {
				break;
			}
		}
		cout << cnt << endl;
	}
}
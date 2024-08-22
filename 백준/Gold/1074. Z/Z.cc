#include<iostream>
#include<cmath>
using namespace std;
int N;
int r, c;
void find(int x, int y, int n,int start) {
	if (n == 0) {
		cout << start << endl;
		return;
	}
	n--;
	int l = pow(2, n)+x;
	int ll = pow(2, n) + y;
	if (r < ll&&c < l) {
		find(x, y, n, start);
	}
	else if (r < ll&&c >= l) {
		find(l,y, n, start + pow(2, 2*(n+1)-2));
	}
	else if (r >= ll && c < l) {
		find(x, ll, n, start + 2 * pow(2, 2 * (n + 1) - 2));
	}
	else {
		find(l, ll, n, start + 3 * pow(2, 2 * (n + 1) - 2));
	}
}
int main() {
	cin >> N;
	cin >> r >> c;
	find(0, 0, N, 0);
}
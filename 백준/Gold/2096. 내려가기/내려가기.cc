#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N; cin >> N;
	int minarr[3];
	int maxarr[3];
	int a, b, c; cin >> a >> b >> c;
	minarr[0] = a;
	minarr[1] = b;
	minarr[2] = c;
	maxarr[0] = a;
	maxarr[1] = b;
	maxarr[2] = c;
	for (int i = 0; i < N-1; i++) {
		int a, b, c; cin >> a >> b >> c;
		int tmp1 = minarr[0];
		int tmp2 = minarr[1];
		int tmp3 = minarr[2];
		int tmp4 = maxarr[0];
		int tmp5 = maxarr[1];
		int tmp6 = maxarr[2];
		minarr[0] = min(tmp1 + a, tmp2 + a);
		minarr[1] = min(tmp1 + b, min(tmp2 + b, tmp3 + b));
		minarr[2] = min(tmp2 + c, tmp3 + c);
		maxarr[0] = max(tmp4 + a, tmp5 + a);
		maxarr[1] = max(tmp4 + b, max(tmp5 + b, tmp6 + b));
		maxarr[2] = max(tmp5 + c, tmp6 + c);
	}
	int minN = min(minarr[0], min(minarr[1], minarr[2]));
	int maxN = max(maxarr[0], max(maxarr[1], maxarr[2]));
	cout << maxN << " " << minN << endl;
}
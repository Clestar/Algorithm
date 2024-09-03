#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
	long long a, b;
	cin >> a >> b;
	long long sum = 0;
	long long sum2 = 0;
	for (long long i = 1; b > 0; i *= 2) {
		long long tmp;
		if (b & 1)tmp = b / 2 + 1;
		else tmp = b / 2;
		sum2 += tmp * i;
		b -= tmp;
	}
	a--;
	for (long long i = 1; a > 0; i *= 2) {
		long long tmp;
		if (a & 1)tmp = a / 2 + 1;
		else tmp = a / 2;
		sum += tmp * i;
		a -= tmp;
	}
	cout << sum2 - sum << endl;
}

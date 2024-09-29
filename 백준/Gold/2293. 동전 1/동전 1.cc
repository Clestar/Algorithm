#include <iostream>
#include <algorithm>
using namespace std;
int arr2[10001];

int main() {
	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		int c; 
		cin >> c;
		if (c <= 10000)arr2[c] += 1;
		for (int j = c; j <= k; j++) {
			arr2[j] += arr2[j - c];
		}
	}
	cout << arr2[k] << endl;
}
#include <iostream>
#include<string>
#include <algorithm>
using namespace std;
int main() {
	string N;
	int M;
	cin >> N >> M;
	int NN = stoi(N);
	bool num[10];
	for (int i = 0; i < 10; i++) {
		num[i] = true;
	}
	for (int i = 0; i < M; i++) {
		int tmp; cin >> tmp;
		num[tmp] = false;
	}
	int minN = abs(100-NN);
	int loc = 1;
	int i = 0;
	for (i; i <= 1000000; i++) {
		if (i >= 100000) loc = 6;
		else if (i >= 10000) loc = 5;
		else if (i >= 1000) loc = 4;
		else if (i >= 100) loc = 3;
		else if (i >= 10) loc = 2;
		else loc = 1;
		string tmp = to_string(i);
		for (int j = 0; j < loc; j++) {
			if (num[tmp[j]-'0'] == false) {
				break;
			}
			if (j == loc - 1) {
				minN = min(minN, loc + abs(i - NN));
			}
		}
	}
	cout << minN << endl;
}
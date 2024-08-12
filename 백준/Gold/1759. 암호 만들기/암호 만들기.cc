#include <iostream>
#include<string>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int L, C; cin >> L >> C;
	vector<char>c;
	for (int i = 0; i < C; i++) {
		char tmp; cin >> tmp;
		c.push_back(tmp);
	}
	vector<int> v;
	for (int i = 0; i < L; i++) {
		v.push_back(0);
	}
	for (int i = 0; i < C - L; i++) {
		v.push_back(1);
	}

	
	sort(c.begin(), c.end());
	do {
		int vowel = 0;
		int consonant = 0;
		string s;
		for (int i = 0; i < C; i++) {
			if (v[i] == 1)continue;
			if (c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u')vowel++;
			else consonant++;
			s += c[i];
		}
		if (vowel >= 1 && consonant >= 2) {
			cout << s << endl;
		}
	} while (next_permutation(v.begin(), v.end()));
}
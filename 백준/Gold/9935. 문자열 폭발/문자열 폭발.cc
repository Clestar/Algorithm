#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	string first, second;
	cin >> first >> second;
	stack<int> s;
	if (second.length() > first.length()) {
		cout << first << endl;
		return 0;
	}
	for (int i = 0; i < first.length(); i++) {
		if (s.empty()) {
			if (second[0] != first[i])s.push(-1*i);
			else s.push(1);
		}
		else {
			if (s.top()>0) {
				if (second[s.top()] == first[i]) {
					s.push(s.top() + 1);
				}
				else {
					if (second[0] != first[i])s.push(-1 * i);
					else s.push(1);
				}
				
			}
			else {
				if (second[0] != first[i])s.push(-1 * i);
				else s.push(1);
			}
			
		}
		if (s.top() == second.length()) {
			for (int j = 0; j < second.length(); j++) {
				s.pop();
			}
		}
	}
	if (s.empty()) {
		cout << "FRULA" << endl;
	}
	else {
		stack<int> tmp;
		while (!s.empty()) {
			tmp.push(s.top());
			s.pop();
		}
		while (!tmp.empty()) {
			if (tmp.top() <= 0) {
				tmp.top() *= -1;
				cout << first[tmp.top()];
			}
			else {
				cout << second[tmp.top()-1];
			}
			tmp.pop();
		}
		cout << endl;
	}
}
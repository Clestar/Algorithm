#include <iostream>
#include <vector>
using namespace std;

class student {
public:
	student(int i,int n) {
		this->index = i;
		this->number = n;
	}
	int index;
	int number;
	bool team = false;
	bool visited = false;
	bool available = true;
};
vector<student*>  v;
void dfs(student* s) {
	s->visited = true;
	if (s->number == s->index + 1) {
		s->team = true;
		s->available = false;
	}
	else if (v[(s->number) - 1]->visited && v[(s->number) - 1]->available) {
		s->team = true;
		v[(s->number) - 1]->available = false;
	}
	else if (!(v[(s->number) - 1]->team) && !(v[(s->number) - 1]->visited)) {
		dfs(v[(s->number) - 1]);
		if (v[(s->number) - 1]->team && v[(s->number) - 1]->available) {
			s->team = true;
			v[(s->number) - 1]->available = false;
		}
		else {
			s->available = false;
		}
	}
	else {
		s->available = false;
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int k;
			cin >> k;
			v.push_back(new student(i, k));
		}
		for (int i = 0; i < v.size(); i++) {
			if (!v[i]->visited)
			dfs(v[i]);
		}
		
		for (int i = 0; i < v.size(); i++) {
			if (!v[i]->team)
			cnt++;
		}
		cout << cnt << endl;
		cnt = 0;
		v.clear();
	}
}
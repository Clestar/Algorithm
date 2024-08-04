#include<iostream>
#include<queue>
#include<stack>
using namespace std;
#define INF 1000000;
int arr[200002];
stack<int> s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, K; cin >> N >> K;
	queue<int> q;
	q.push(N);
	for (int i = 0; i <= 100000; i++) {
		arr[i] = INF;
	}
	if (N == K) {
		cout << 0 << endl;
		cout << N << endl;
		return 0;
	}
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == K)break;
		if (x * 2 <= 100000 && arr[x * 2] == 1000000) {
			q.push(x * 2);
			arr[x * 2] = x;
		}
		if (x + 1 <= 100000 && arr[x + 1] == 1000000) {
			q.push(x + 1);
			arr[x + 1] = x;
		}
		if (x - 1 >= 0 && arr[x - 1] == 1000000) {
			q.push(x-1);
			arr[x - 1] = x;
		}
		
		
	}
	int tmp = K;
	
	while (tmp != N) {
		s.push(tmp);
		tmp = arr[tmp];
		if (tmp == N)s.push(tmp);
	}
	cout << s.size() - 1 << endl;
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}
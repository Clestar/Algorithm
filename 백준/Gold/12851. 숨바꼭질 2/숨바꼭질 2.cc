#include <iostream>
#include<queue>
using namespace std;
int visited[100001][2];
int main() {
	int N, K;
	cin >> N >> K;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({ 0, N });
	visited[N];
	int maxNum = 1000000;
	int total = 0;
	for (int i = 0; i <= 100000; i++) {
		visited[i][0] = -1;
	}
	visited[N][0] = 0;
	visited[N][1] = 1;
	while (!pq.empty()) {
		int cnt = pq.top().first;
		int x = pq.top().second;
		pq.pop();
		if (cnt > maxNum) break;
		if (x == K) {
			maxNum = cnt;
			total+=visited[x][1];
		}
		cnt++;
		if (x - 1 >= 0) {
			if (visited[x - 1][0] == -1) {
				visited[x - 1][0] = cnt;
				visited[x - 1][1] += visited[x][1];
				pq.push({ cnt,x - 1 });
			}
			else if(visited[x-1][0]==cnt)
				visited[x - 1][1]+= visited[x][1];
		}
		if (x + 1 <= 100000) {
			if (visited[x + 1][0] == -1) {
				visited[x + 1][0] = cnt;
				visited[x + 1][1] += visited[x][1];
				pq.push({ cnt,x + 1 });
			}
			else if (visited[x + 1][0] == cnt)
				visited[x + 1][1]+= visited[x][1];
		}
		if (x * 2 <= 100000) {
			if (visited[x * 2][0] == -1) {
				visited[x * 2][0] = cnt;
				visited[x * 2][1] += visited[x][1];
				pq.push({ cnt,x * 2 });
			}
			else if (visited[x * 2][0] == cnt)
				visited[x * 2][1]+=visited[x][1];
		}
	}
	cout << maxNum << endl;
	cout << total << endl;
}
#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
double arr[100][2];
bool visited[100];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		double tmp, tmp2; cin >> tmp >> tmp2;
		arr[i][0] = tmp;
		arr[i][1] = tmp2;
	}
	priority_queue < pair<double, int>, vector< pair<double, int>>, greater< pair<double, int>>> pq;
	pq.push({ 0, 0 });
	double sum = 0;
	while (!pq.empty()) {
		int x = pq.top().second;
		double cost = pq.top().first;
		pq.pop();
		if (visited[x]) continue;
		visited[x] = true;
		sum += cost;
		for (int i = 0; i < n; i++) {
			if (visited[i])continue;
			double dist = sqrt((arr[i][0] - arr[x][0]) * (arr[i][0] - arr[x][0]) + (arr[i][1] - arr[x][1]) * (arr[i][1] - arr[x][1]));
			pq.push({ dist,i });
		}
	}
	cout << sum << endl;
}

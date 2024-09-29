#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int vis[1003];
vector<pair<int, int>> v[1003]; 
void fc(int a) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push(make_pair(0, a));
    vis[a] = 0; 
    while (!pq.empty())
    {
        int cost = pq.top().first; 
        int x = pq.top().second; 
        pq.pop();

        if (vis[x] < cost)
            continue;

        for (int i = 0; i < v[x].size(); i++) {
            int nx = v[x][i].first; 
            int ncost = cost + v[x][i].second; 

            if (vis[nx] > ncost) {
                pq.push(make_pair(ncost, nx));
                vis[nx] = ncost;
            }
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;

    v[0].push_back(make_pair(0, 0));
    memset(vis, 98765432, sizeof(vis));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
    }
    int st, dt; 
    cin >> st >> dt;
    fc(st);
    cout << vis[dt]; 
    return 0;
}
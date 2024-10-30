
#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5;
vector<int>g[N];
vector<bool>vis(N);
vector<int>level(N);
// if all edge is same weighted then level is the shortest path from source
void bfs(int src) {
	queue<int>q;
	q.emplace(src);
	vis[src] = true;
	while (!q.empty()) {
		int cur_v = q.front();
		q.pop();
		for (int child : g[cur_v]) {
			if (!vis[child]) {
				q.emplace(child);
				vis[child] = true;
				level[child] = level[cur_v] + 1;
			}
		}
	}
}
void tcase() {
	int n; cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int x, y; cin >> x >> y;
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}
	bfs(1);
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
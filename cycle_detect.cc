#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5;
vector<int>g[N];
vector<bool>vis(N, false);
bool dfs(int ver, int par) {
	vis[ver] = true;
	bool cycle = false;
	for (int child : g[ver]) {
		if (vis[child] && par == child)continue;
		if (vis[child])return true;

		cycle |= dfs(child, ver);
	}
	return cycle;
}
void tcase() {
	vis.clear();
	int n , m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}
	bool cycle = false;
	for (int i = 1; i <= n; ++i) {
		if (vis[i])
			continue;
		if (dfs(i,     0)) {
			cout << "Cycle" << '\n';
			return;
		}
	}
	cout << "No Cycle" << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
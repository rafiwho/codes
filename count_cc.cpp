#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1e5;
vector<int>g[N];
vector<bool>vis(N);
void dfs(int ver) {
	vis[ver] = true;
	for (int child : g[ver]) {
		if (!vis[child])
			dfs(child);
	}
}
void tcase() {
	int n , m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}
	int cc = 0;
	for (int i = 1; i <= n; ++i) {
		if (vis[i])
			continue;
		else
			dfs(i), cc++;
	}
	cout << cc << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}

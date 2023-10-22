#include <bits/stdc++.h>

using namespace std;
constexpr int N = 2e5;
vector<int>g[N];
int height[N], depth[N];
void dfs(int ver, int par = 0) {
	for (int child : g[ver]) {
		if (child == par)continue;
		depth[child] = depth[ver] + 1;
		dfs(child, ver);
		height[ver] = max(height[ver], height[child] + 1);
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
	dfs(0);
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
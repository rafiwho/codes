#include "bits/stdc++.h"
using namespace std;

const int N = int(1e5 + 7);
std::vector<int> g[N];
int depth[N];
int height[N];
void dfs(int ver , int par = 0) {
	for (auto child : g[ver]) {
		if (child == par)
			continue;
		depth[child] = depth[ver] + 1;
		dfs(child, ver);
		height[ver] = max(height[ver], height[child] + 1);
	}
}

void tcase() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	for (int i = 0; i < n; ++i) {
		cout << height[i + 1] << ' ';
	}
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1e5;
vector<int>v[N];
int depth[N];
void dfs(int ver, int par = 0) {
	for (int child : v[ver]) {
		if (child == par)continue;
		depth[child] = depth[ver] + 1;
		dfs(child, ver);
	}
}
void tcase() {
	int n; cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int x, y; cin >> x >> y;
		v[x].emplace_back(y);
		v[y].emplace_back(x);
	}
	dfs(1);
	int node_1 = max_element(depth, depth + N) - depth;
	memset(depth, 0, N);
	dfs(node_1);
	int diameter = *max_element(depth, depth + N);
	cout << diameter << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
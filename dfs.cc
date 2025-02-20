#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int>g[N];
vector<bool>vis(N);
void dfs(int ver) {
	vis[ver] = true;
	cout << ver << '\n';
	for (int child : g[ver]) {
		if (!vis[child])
			dfs(child);
	}
}
void tcase() {
	int n , m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int v1, v2;
		cin >> v1 >> v2;
		g[v1].emplace_back(v2);
		g[v2].emplace_back(v1);
	}
	dfs(1);
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
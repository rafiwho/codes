#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1E5;
vector<int>v[N];
int par[N];
void dfs(int ver, int p = -1) {
	par[ver] = p;
	for (int child : v[ver]) {
		if (child == p)continue;
		dfs(child, ver);
	}
}
vector<int>path(int ver) {
	vector<int>ans;
	while (ver != -1) {
		ans.emplace_back(ver);
		ver = par[ver];
	}
	reverse(ans.begin(), ans.end());
	return  ans;
}
void tcase() {
	int n; cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int x, y; cin >> x >> y;
		v[x].emplace_back(y);
		v[y].emplace_back(x);
	}
	dfs(1);
	int x, y;
	cin >> x >> y;
	auto path_x = path(x);
	auto path_y = path(y);
	int sz = min(path_x.size(), path_y.size());
	int lca = -1;
	for (int i = 0; i < sz; ++i) {
		if (path_x[i] == path_y[i])
			lca = path_x[i];
		else
			break;
	}

	cout << lca << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 1e5;
constexpr int M = 1e9 + 7;
vector<int>g[N];
int sub_s[N];
int val[N];
void dfs(int ver, int par = -1) {
	sub_s[ver] += val[ver];
	for (int child : g[ver]) {
		if (child == par)continue;
		dfs(child, ver);
		sub_s[ver] += sub_s[child];
	}
}
void tcase() {
	int n; cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int x, y; cin >> x >> y;
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}
	// have to take val array for result
	dfs(1);
	ll mx = -1E9;
	for (int i = 2; i <= n; ++i) {
		ll part1 = sub_s[i];
		ll part2 = sub_s[1] - part1; // sub_s[1] store level 0 nodes sub_s
		mx = max(mx, (part1 * part1) % M);
	}
	cout << mx << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
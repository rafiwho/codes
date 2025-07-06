#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1E5 + 5;
vector<int>v[N] , v_rev[N];
vector<bool>used(N);
vector<int>comp;
vector<int>order;
void dfs1(int ver) {
	used[ver] =  true;
	for (int child : v[ver]) {
		if (!used[child])
			dfs1(child);
	}
	order.emplace_back(ver); // order
}
void dfs2(int ver) {
	used[ver] = true;
	comp.emplace_back(ver); // pushing comp
	for (int child : v_rev[ver]) {
		if (!used[child])
			dfs2(child);
	}
}
void tcase() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		int x, y; cin >> x >> y;
		v[x].emplace_back(y);
		v_rev[y].emplace_back(x);
	}
	for (int i = 1; i <= n; ++i) {
		if (!used[i])
			dfs1(i);
	}
	used.assign(N, false);
	reverse(order.begin(), order.end());
	for (int x : order) {
		if (!used[x])
			dfs2(x);
		for (int c : comp)
			cout << c << ' ';
		cout << '\n';
		comp.clear();
	}
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
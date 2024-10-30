#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1E5 + 5;
int par[N];
int sz[N];
int cc = 0;
void make(int v) {
	par[v] = v;
	sz[v] = 1;
	cc++;
}
int Find(int v) {
	return v == par[v] ? v : par[v] = Find(par[v]);
}
bool Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b)return true;
	if (sz[a] < sz[b])
		swap(a, b);
	par[b] = a;
	sz[a] += sz[b];
	cc--;
	return false;
}
void tcase() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		make(i);
	}
	auto cmp = [](auto a, auto b) {
		return a[2] > b[2];
	};
	priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(cmp)>pq(cmp);
	for (int i = 0; i < m; ++i) {
		int a, b , w; cin >> a >> b >> w;
		pq.push({a, b, w});
	}
	int ans = 0;
	while (!pq.empty()) {
		auto [a, b, w] = pq.top();
		pq.pop();
		if (Find(a) == Find(b))continue;
		Union(a, b);
		ans += w;
	}
	cout << ans << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
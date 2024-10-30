#include <bits/stdc++.h>
using namespace std;
/*Given Q queries,Q <=1e5
	In each Q given V ,
	print subtree sum and even num count
	of that subtree v
*/
constexpr int N = 1e5;
vector<int>v[N];
int sub_sum[N];
int even_cnt[N];

void dfs(int ver, int par = 0) {
	sub_sum[ver] += ver;
	even_cnt[ver] += (ver & 1 ? 0 : 1);
	for (int child : v[ver]) {
		if (child == par)continue;
		dfs(child, ver);
		sub_sum[ver] += sub_sum[child];
		even_cnt[ver] += even_cnt[child];
	}
}
void tcase() {
	int n; cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		v[x].emplace_back(y);
		v[y].emplace_back(x);
	}
	dfs(1);
	for (int i = 1; i <= n; ++i) {
		cout << sub_sum[i] << ' ' << even_cnt[i] << '\n';
	}
	/*int q; cin >> q;
	while (q--) {
		int v; cin >> v;
		cout << sub_sum[v] << '\n';
		cout<<even_cnt[v]<<'\n';
	}*/
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
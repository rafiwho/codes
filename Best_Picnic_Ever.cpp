#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif

#define pb push_back
#define in insert
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()

const int N = int(1e3 + 7);
std::vector<int> v[N];
int cnt[N];
bool vis[N];
void dfs(int ver) {
	if (vis[ver])
		return ;
	vis[ver] = true;
	cnt[ver]++;
	for (auto child : v[ver]) {
		dfs(child);
	}
}

int xx = 1;
void tcase() {
	int k, n, m;
	cin >> k >> n >> m;
	vector<int>p(k);
	for (auto&A : p)
		cin >> A;

	for (int i = 0; i < m; ++i) {
		int a , b;
		cin >> a >> b;
		v[a].pb(b);
	}

	for (int i = 0; i < k; ++i) {
		dfs(p[i]);
		memset(vis, false, sizeof vis);
	}

	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		ans += cnt[i] == k;
	}
	for (int i = 0; i < N; ++i) {
		v[i].clear();
		cnt[i] = 0;
		vis[i] = false;
	}
	cout << "Case " << xx++ << ": " << ans << '\n';

}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	cin >> t;

	while (t-- > 0)
		tcase();
}
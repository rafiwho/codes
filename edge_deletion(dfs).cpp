#include <cstdint>
#include <iostream>
#include <vector>
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

const int N = int(1e5 + 7);
vector<int>v[N];
int cnt[N];
int val[N];

void dfs(int ver , int par = -1) {
	cnt[ver] += val[ver];
	for (auto&child : v[ver]) {
		if (child == par)
			continue;
		else {
			dfs(child, ver);
			cnt[ver] += cnt[child];
		}
	}
}

void tcase() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int x , y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}

	dfs(1, 0);
	int64_t ans = 0;
	for (int i = 2; i <= n; ++i) {
		int part1 = cnt[i];
		int part2 = cnt[1] - part1;
		ans = max(ans, part1 * 1ll * part2);
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
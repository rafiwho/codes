#include <bits/stdc++.h>
using namespace std;

const int N = 1E6 + 5;
const int BIT = 31;
using ll = long long;
int nxt[N * BIT][2], cnt[N * BIT];
int id = 1;

void add(int num) {
	int cur_node = 1;
	for (int k = BIT - 1; ~k; --k) {
		if (nxt[cur_node][1 & num >> k] == 0) {
			nxt[cur_node][1 & num >> k] = ++id;
		}
		cur_node = nxt[cur_node][1 & num >> k];
		cnt[cur_node]++;
	}
}

// number of prefix in the tree such that xor ^ tar >= k
ll gtr(int K, int tar) {
	ll res = 0, cur_node = 1, cur_xor = 0;
	for (int k = BIT - 1; ~k; --k) {
		int tar_bit = 1 & tar >> k;
		if ((cur_xor ^ 1 << k) >= K) {
			res += cnt[nxt[cur_node][!tar_bit]];
			cur_node = nxt[cur_node][tar_bit];
		} else {
			if (nxt[cur_node][!tar_bit] == 0) return res;
			else cur_node = nxt[cur_node][!tar_bit] , cur_xor ^= 1 << k;
		}
	}
	return res;
}

void tcase() {
	int n, k;
	cin >> n >> k;
	int xr = 0;
	add(xr);
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		add(xr = xr ^ x);
		ans += gtr(k, xr);
	}
	cout << ans << '\n';
}
int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int32_t t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
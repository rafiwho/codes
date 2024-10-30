#include <bits/stdc++.h>
using namespace std;
const int MX = 5e4;
using ll = int64_t;

struct seg {
	ll ans, pre, suf, sum;
} T[MX << 2];

vector<ll>v(MX);

seg mrge(seg l, seg r) {
	ll ans = max({l.ans, r.ans, l.suf + r.pre});
	ll pre = max({l.pre, l.sum + r.pre});
	ll suf = max({r.suf, r.sum + l.suf});
	ll sum = l.sum + r.sum;
	return {ans, pre, suf, sum};
}
void build(ll N, ll s, ll e) {
	if (s == e) {
		T[N] = {v[s], v[s], v[s], v[s]};
		return;
	}
	int m = (s + e) >> 1;
	build(N << 1, s, m);
	build(N << 1 | 1, m + 1, e);
	T[N] = mrge(T[N << 1], T[N << 1 | 1]);
}
seg query(int N, int s, int e, int l, int r) {
	if (s > r || e < l)
		return {INT_MIN, INT_MIN, INT_MIN, 0};
	if (s >= l && e <= r)
		return T[N];
	int m = (s + e) >> 1;
	return mrge(query(N << 1, s, m, l, r), query(N << 1 | 1, m + 1, e, l, r));
}
void tcase() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}
	build(1, 1, n);
	int q; cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << query(1, 1, n, l, r).ans << '\n';
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
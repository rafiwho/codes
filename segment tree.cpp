#include <bits/stdc++.h>
using namespace std;
constexpr int N = 100005;
int a[N], t[N << 2];
int combine(int a, int b, int c = 0) {
	return min(a, b);
}
void build(int node, int st, int en) {
	if (st == en) {
		t[node] = a[st];
		return;
	}
	int mid = (st + en) >> 1;
	build(node << 1, st, mid);
	build(node << 1 | 1, mid + 1, en);
	t[node] = combine(t[node << 1], t[node << 1 | 1]);
}
void update(int node, int st, int en, int i, int v) {
	if (i < st || i > en)return;
	if (st == en) {
		t[node] = v;
		return;
	}
	int mid = (st + en) >> 1;
	update(node << 1, st, mid, i, v);
	update(node << 1 | 1, mid + 1, en, i, v);
	t[node] = combine(t[node << 1], t[node << 1 | 1]);
}
int query(int node, int st, int en, int l, int r) {
	if (l > en || r < st)return INT_MAX;
	if (st >= l && en <= r)return t[node];
	int mid = (st + en) >> 1;
	int p = query(node << 1, st, mid, l, r);
	int q = query(node << 1 | 1, mid + 1, en, l, r);
	return combine(p, q);
}
void tcase() {
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	build(1, 1, n);
	while (q--) {
		int type; cin >> type;
		if (type == 1) {
			int i, val; cin >> i >> val;
			update(1, 1, n, i + 1, val);
		} else {
			int l, r; cin >> l >> r;
			cout << query(1, 1, n, l + 1, r) << '\n';
		}
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

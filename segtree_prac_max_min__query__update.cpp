#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "EMNI.HPP"
#endif

//min query on segment treew
const int N = int(1e5) + 9;
const int INF = int(2e9) + 10;
int n, q;
vector<int>tree(4 * N);
vector<int>v(N);
void build(int node, int st, int en) {
	if (st == en) {
		tree[node] = v[st];
		return;
	}
	int mid = (st + en) >> 1;
	build(2 * node, st, mid);;
	build(2 * node + 1, mid + 1, en);
	tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}
int query(int node , int st, int en, int l, int r) {
	if (st > r || en < l) {
		return INF;
	}
	if (st >= l && en <= r) {
		return tree[node];
	}
	int mid = (st + en) >> 1;
	int q1 = query(2 * node, st, mid, l, r);
	int q2 = query(2 * node+1, mid + 1, en, l, r);
	return min(q1, q2);
}
void update(int node , int st, int en, int idx, int val) {
	if (st == en) {
		v[st] = val;
		tree[node] = val;
		return;
	}
	int mid = (st + en) >> 1;
	if (idx <= mid)
		update(2 * node, st, mid, idx, val);
	else
		update(2 * node + 1, mid + 1, en, idx, val);
	tree[node] = min(tree[2 * node] , tree[2 * node + 1]);
}
void tcase() {
	cin >> n >> q;
	v.resize(n);
	for (auto&A : v)
		cin >> A;
	build(1, 0, n - 1);
	while (q--) {
		int type, idx, val;
		cin >> type >> idx >> val;
		if (type == 1) {
			update(1, 0, n - 1, idx, val);
		} else {
			cout << query(1, 0, n - 1, idx, val - 1) << '\n';
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
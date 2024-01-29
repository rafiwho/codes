#include <bits/stdc++.h>
using namespace std;

const int N = int(1e5) + 10;
vector<int64_t>tree(4 * N);
vector<int>v(N);

void build(int node , int st, int en) {
	if (st == en) {
		tree[node] = v[st];
		return;
	}
	int mid = (st + en) >> 1;
	build(2 * node, st, mid);
	build(2 * node + 1, mid + 1, en);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}
int64_t query(int node , int st, int en, int l, int r) {
	if (st > r || en < l) {
		return 0;
	}
	if (st >= l && en <= r) {
		return tree[node];
	}
	int mid = (st + en) >> 1;
	int64_t q1 = query(2 * node, st, mid, l, r);
	int64_t q2 = query(2 * node + 1, mid + 1, en, l, r);
	return q1 + q2;
}
void update(int node , int st, int en, int idx, int new_val) {
	if (st == en) {
		v[idx] = new_val;
		tree[node] = new_val;
		return;
	}
	int mid = (st + en) >> 1;
	if (idx <= mid) {
		update(2 * node, st, mid, idx, new_val);
	} else {
		update(2 * node + 1, mid + 1, en, idx, new_val);
	}
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}
void tcase() {
	int n , q;
	cin >> n >> q;
	for (auto i = 0; i < n; ++i) {
		cin >> v[i];
	}

	build(1, 0, n - 1);
	while (q--) {
		int a, idx, new_val;
		cin >> a >> idx >> new_val;

		if (a == 1) {
			update(1, 0, n - 1, idx, new_val);
		} else {
			cout << query(1, 0, n - 1, idx, new_val - 1) << '\n';
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

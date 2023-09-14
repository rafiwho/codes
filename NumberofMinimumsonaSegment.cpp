#include <bits/stdc++.h>
using namespace std;

const int MAXN = int(1e5) + 10;
const int INF = int(2e9) + 7;
pair<int, int>tree[4 * MAXN];
vector<int>v;
pair<int, int>ck(pair<int, int>&a, pair<int, int>&b) {
	if (a.first < b.first)
		return a;
	if (a.first > b.first)
		return b;
	return make_pair(a.first, a.second + b.second);
}
void build(int node, int st, int en) {
	if (st == en) {
		tree[node] = {v[st], 1};
	} else {
		int mid = (st + en) >> 1;
		build(node << 1, st, mid);
		build((node << 1) + 1, mid + 1, en);
		tree[node] = ck(tree[node << 1], tree[(node << 1) + 1]);
	}
}
void update(int node, int st, int en, int idx, int val) {
	if (st == en) {
		tree[node] = {val, 1};
		return ;
	}
	int mid = (st + en) >> 1;
	if (idx <= mid)
		update(node << 1, st, mid, idx, val);
	else
		update((node << 1) + 1, mid + 1, en, idx, val);
	tree[node] = ck(tree[node << 1], tree[(node << 1) + 1]);
}
pair<int, int> query(int node, int st , int en, int l, int r) {
	if (st > r || en < l) {
		return {INF, 0};
	}
	if (st >= l && en <= r) {
		return tree[node];
	}
	int mid = (st + en) >> 1;
	pair<int, int> q1 = query(node << 1, st, mid, l, r);
	pair<int, int> q2 = query((node << 1) + 1, mid + 1, en, l, r);
	return ck(q1, q2);
}

void tcase() {
	int N, M;
	cin >> N >> M;
	v.resize(N);
	for (auto&A : v)
		cin >> A;
	build(1, 0, N - 1);
	while (M--) {
		int type;
		cin >> type;
		if (type == 1) {
			int idx, val;
			cin >> idx >> val;
			update(1, 0, N - 1, idx, val);
		} else {
			int l, r;
			cin >> l >> r;
			auto [a, b] = query(1, 0, N - 1, l , r - 1);
			cout << a << ' ' << b << '\n';
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
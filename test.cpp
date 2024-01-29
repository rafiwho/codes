#include <bits/stdc++.h>
using namespace std;
constexpr int  N = 30001;
constexpr int M = 200001;
vector<int64_t>tree(N<<2);

void build(int node , int st, int en) {
	if (st == en) {
		tree[node] = 0;
		return;
	}
	int mid = (st + en) >> 1;
	build(node<<1, st, mid);
	build(node<<1|1, mid + 1, en);
	tree[node] = tree[node<<1] + tree[node<<1|1];
}
int64_t query(int node , int st, int en, int l, int r) {
	if (st > r || en < l) {
		return 0;
	}
	if (st >= l && en <= r) {
		return tree[node];
	}
	int mid = (st + en) >> 1;
	int64_t q1 = query(node<<1, st, mid, l, r);
	int64_t q2 = query(node<<1|1, mid + 1, en, l, r);
	return q1 + q2;
}
void update(int node , int st, int en, int idx, int new_val) {
	if (st == en) {
		tree[node] += new_val;
		return;
	}
	int mid = (st + en) >> 1;
	if (idx <= mid) {
		update(node<<1, st, mid, idx, new_val);
	} else {
		update(node<<1|1, mid + 1, en, idx, new_val);
	}
	tree[node] = tree[node<<1] + tree[node<<1|1];
}
int arr[N],ans[N];
vector<array<int, 2>>Q[N];
void tcase() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	int q; cin >> q;
	for (int i = 1; i <= q; ++i) {
		int l,r; cin >> l >> r;
		Q[r].push_back({l,i});
	}
	build(1, 1, n);
	map<int, int>last_occur;
	for (int r = 1; r <= n; ++r) {
		if(last_occur.find(arr[r])!=last_occur.end()){
			update(1,1,n,last_occur[arr[r]],-1);
		}
		last_occur[arr[r]] = r;
		update(1,1,n,r,+1);
		for(auto [l,id]:Q[r]){
			ans[id] = query(1,1,n,l,r);
		}
	}

	for (int i = 1; i <= q; ++i) {
		cout << ans[i] << '\n';
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
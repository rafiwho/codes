#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5E5+5;
int a[N], t[N << 2],D,dp[N],n;
int combine(int a, int b) {
	return max(a, b);
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
	if (l > en || r < st)return 0;
	if (st >= l && en <= r)return t[node];
	int mid = (st + en) >> 1;
	int p = query(node << 1, st, mid, l, r);
	int q = query(node << 1 | 1, mid + 1, en, l, r);
	return combine(p, q);
}
void tcase() {
	cin >> n >> D;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		dp[i] = max(1,1+query(1,1,N,max(0,a[i]-D),min(N,a[i]+D)));
		update(1,1,N,a[i],dp[i]);
	}
	int ans=0;
	for (int i = 1; i <= n; ++i) {
		ans = max(ans,dp[i]);
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
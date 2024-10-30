#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr int N = 2E5 + 5;
constexpr i64 INF = 1E15;
int H[N],B[N],n;
i64 dp[N];
i64 t[N << 2];

i64 query(int node, int st, int en, int l, int r) {
    if (st > r || en < l) {
        return -INF;
    }
    if (st >= l && en <= r) {
        return t[node];
    }
    int mid = (st + en) >> 1;
    i64 q1 = query(node << 1, st, mid, l, r);
    i64 q2 = query((node << 1) + 1, mid + 1, en, l, r);
    return max(q1, q2);
}

void update(int node, int st, int en, int idx,i64 x) {
    if (st > idx || en < idx) {
        return ;
    }
    if (st == en) {
        t[node] = x;
        return;
    }
    int mid = (st + en) >> 1;
    update(node << 1, st, mid, idx,x);
    update((node << 1) + 1, mid + 1,en,idx,x);
    t[node] = max(t[node << 1], t[(node << 1) + 1]);
}
void tcase() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> H[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> B[i];
	}
	for (int i = 1; i <= n; ++i) {
		dp[i] = B[i];
		dp[i] = max(dp[i],query(1,1,n,1,H[i]-1) + B[i]);
		update(1,1,n,H[i],dp[i]);
	}
	i64 ans=0;
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
#include <bits/stdc++.h>
using namespace std;
const int N = 1E5 + 5;
const int LOG = __bit_width(N);
int a[N];
int sp[N][LOG];
int query(int L, int R) {
	int len = R - L + 1;
	int k = __bit_width(len) - 1;
	return min(sp[L][k], sp[R - (1 << k) + 1][k]);
}
void tcase() {
	int n , k; cin >> n >> k;
	int mn = INT_MIN - 1;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sp[i][0] = a[i];
		mn = min(mn, a[i]);
	}

	for (int k = 1; k <= LOG; ++k) {
		for (int i = 0; i + (1 << k) <= n; ++i) {
			sp[i][k] = min(sp[i][k - 1], sp[i + (1 << (k - 1))][k - 1]);
		}
	}

	if (k == 1) {
		cout << mn << '\n';
		return;
	}

	if (k == 2) {
		int ans = INT_MAX + 1;
		for (int i = 0; i < n; ++i) {
			ans = max({ans, query(0, i), query(i, n - 1)});
		}
		cout << ans << '\n';
		return;
	}

	cout << *max_element(a, a + n) << '\n';

}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int32_t t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
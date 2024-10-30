#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1e6 + 7;

void tcase() {
	int n;
	cin >> n;
	vector<int>v(n);
	bitset<N>bs;
	bs.reset();
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		bs[v[i]] = 1;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; ++i) {
		for (int j = 2; 1LL * j * j <= v[i]; ++j) {
			if (v[i] % j == 0) {
				if (!bs[v[i] / j] || !bs[j]) {
					cout << -1 << '\n';
					return;
				}
			}
		}
	}
	int64_t ans = 1LL * v[0] * v[n - 1];
	for (int i = 0; i < n; ++i) {
		if (1LL * v[i]*v[n - i - 1] != ans) {
			cout << -1 << '\n';
			return;
		}
	}
	cout << ans << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin >> t;

	while (t-- > 0)
		tcase();
}
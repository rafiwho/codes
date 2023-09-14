#include <bits/stdc++.h>
using namespace std;

void tcase() {
	int64_t n, k;
	cin >> n >> k;
	vector<int>v(n);
	for (auto &A : v)
		cin >> A;
	sort(v.rbegin(), v.rend());
	auto posi = [&](int x)->bool{
		int64_t cnt = 0;
		for (auto i = 0; i < n; ++i) {
			cnt += (v[i] / x);
		}
		return cnt >= k;
	};
	int lo = 1, hi = 1e9, ans = 0;
	while (hi >= lo) {
		int mid = (hi + lo) >> 1;
		if (posi(mid)) {
			ans = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	cout << ans << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	cin >> t;

	while (t-- > 0)
		tcase();
}
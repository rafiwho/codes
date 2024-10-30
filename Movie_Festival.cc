#include <bits/stdc++.h>
using namespace std;

void tcase() {
	int n;
	cin >> n;
	vector<pair<int, int>>v(n);
	for (auto &[y, x] : v)
		cin >> x >> y;
	sort(v.begin(), v.end());
	int cnt = 0, max_end = -1;
	for (auto[end, start] : v) {
		if (start >= max_end) {
			max_end = end;
			++cnt;
		}
	}
	cout << cnt << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
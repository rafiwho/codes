#include <bits/stdc++.h>
using namespace std;

void tcase() {
	int n;
	cin >> n;
	vector<int>v(n), lis;
	for (auto &x : v)
		cin >> x;
	for (int i = 0; i < n; ++i) {
		if (lis.empty()) {
			lis.emplace_back(v[i]);
		} else if (lis.back() < v[i]) {
			lis.emplace_back(v[i]);
		} else {
			int idx = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
			lis[idx] = v[i];
		}
	}
	cout << lis.size() << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
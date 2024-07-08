#include <bits/stdc++.h>
using namespace std;

void tcase() {
	int n;
	cin >> n;
	vector<int>v[n + 1];
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	long long ans = 0 ;
	for (int i = 1; i <= n; ++i) {
		int sz = v[i].size();
		ans += sz * (sz - 1) / 2;
	}
	cout << ans << '\n';
}
int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int32_t t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
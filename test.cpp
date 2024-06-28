#include <bits/stdc++.h>

using namespace std;

void tcase() {
	int n;
	cin >> n;
	vector<int>v(n);
	for (int &x : v)
		cin >> x;

	std::map<int , int> fre;
	int64_t ans = 0;

	for (int i = 0; i < n; ++i) {
		for (int k = 0; k <= 30; ++k) {
			if (fre.contains((1 << k) - v[i])) {
				ans += fre[(1 << k) - v[i]];
			}
		}
		fre[v[i]]++;
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
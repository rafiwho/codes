#include <bits/stdc++.h>
using namespace std;

void tcase() {
	vector<int>v = {1, 2, 3};
	int n = 3; // every v[i] will contribute 2*n*v[i]
	int ans = 0 ;  // (_n_,_n_) 2*n contribution of every ele
	for (int i = 0; i < n; ++i) {
		ans += (n << 1) * v[i];
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
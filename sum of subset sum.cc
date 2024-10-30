#include <bits/stdc++.h>
using namespace std;

void tcase() {
	int n; cin >> n;
	int v[n + 1];
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}
	int sum = 0 ;
	for (int i = 1; i <= n; ++i) {
		sum += v[i] * (1 << (n - 1));
	}
	cout << sum << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
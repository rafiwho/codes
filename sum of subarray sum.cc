
#include <bits/stdc++.h>
using namespace std;

void tcase() {
	int n; cin >> n;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum += v[i] * (i) * (n - i + 1); //a1,a2,a3,a4,a5,a6
		//                               1, 2, 3, 4, 5, 6
		//                               a[i] * i * (n-i+1)
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
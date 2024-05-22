#include <bits/stdc++.h>
using namespace std;

auto tcase()->void{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i < n; ++i) {
		if (max(a[i], a[i - 1]) - min(a[i], a[i - 1]) > 1) {
			cout << "YES\n" <<  i << ' ' << i + 1 << '\n';
			return ;
		}
	}

	cout << "NO\n";
}
auto main()->int32_t{

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int32_t t = 1;
	cin >> t;

	while (t-- > 0)
		tcase();
}
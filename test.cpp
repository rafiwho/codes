#include <bits/stdc++.h>
using namespace std;

void tcase() {
	int n;
	cin >> n;
	multiset<int>ms;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		auto it = ms.upper_bound(x);
		if (it == ms.end()) {
			ms.insert(x);
		} else {
			ms.erase(it);
			ms.insert(x);
		}
	}

	cout << int(ms.size()) << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
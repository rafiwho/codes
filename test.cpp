#include <bits/stdc++.h>
using namespace std;

void tcase() {
	int n;
	cin >> n;
	int cur = 0;
	for (int i = 1; i < n; ++i) {
		int x; cin >> x >> x;
		cout << cur++ << '\n';
	}
}
int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int32_t t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
#include <bits/stdc++.h>
using namespace std;

void tcase() {
	for (int i = 0; i < 4; ++i) {
		int x; cin >> x;
		cout << bitset<10>(x) << '\n';
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
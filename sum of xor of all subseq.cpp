// or of whole array * 2^n-1
#include <bits/stdc++.h>
using namespace std;

void tcase() {
	vector<int> arr = {1, 2, 3, 4};
	int orr = (1 | 2 | 3 | 4);
	int ans = orr * (1 << arr.size());
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
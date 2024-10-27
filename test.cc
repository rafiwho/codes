#include <bits/stdc++.h>
using namespace std;
void tcase() {
	int n; cin >> n;
	if (n == 1 || n == 3) {
		cout << -1 << '\n';
		return ;
	}
	string ans = string(n - 2, '3') + "66";
	if (n & 1) ans[n - 4] = '6';
	cout << ans << '\n';
}
int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int32_t t = 1;
	cin >> t;

	while (t-- > 0)
		tcase();
}
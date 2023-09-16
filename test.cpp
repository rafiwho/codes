#include <bits/stdc++.h>
using namespace std;

void tcase() {
	string s;
	cin >> s;
	size_t sz = s.size();
	int ans = 1e3;
	for (auto i = 'a'; i <= 'z'; ++i) {
		int cnt = 0;
		int x = 0;
		for (auto j = 0; j < sz; ++j) {
			if (s[j] == i) {
				x = max(x, cnt ? __lg(cnt) + 1 : 0);
				cnt = 0;
			} else {
				cnt++;
			}
		}
		x = max(x, cnt ? __lg(cnt) + 1 : 0);
		ans = min(ans, x);
	}
	cout << ans << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	cin >> t;

	while (t-- > 0)
		tcase();
}
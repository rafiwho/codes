#include <bits/stdc++.h>
using namespace std;

void tcase() {
	int n , s;
	cin >> n >> s;
	vector<int>c(n);
	for (auto i = 0LL; i < n; ++i) {
		cin >> c[i];
	}
	vector<int>dp(s + 1, s + 1);
	dp[0] = 0;
	for (auto i = 1LL; i <= s; ++i)
		for (auto x : c)
			if (i - x >= 0)
				dp[i] = min(dp[i], dp[i - x] + 1);
	cout << (dp[s] == s + 1 ? -1 : dp[s]) << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
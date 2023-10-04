#include <bits/stdc++.h>
using namespace std;

void tcase() {
	vector<int>profit = { 60, 100, 120 };
	vector<int>weight = { 10, 20, 30 };
	int W = 50;
	int dp[W + 1];
	memset(dp, 0, sizeof dp);
	for (auto i = 1; i < int(profit.size()) + 1; ++i) {
		for (auto w = W; w >= 0; --w) {
			if (weight[i - 1] <= w)
				dp[w] = max(dp[w], profit[i - 1] + dp[w - weight[i - 1]]);
		}
	}
	cout << dp[W] << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
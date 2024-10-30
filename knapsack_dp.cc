#include <bits/stdc++.h>
using namespace std;

void tcase() {
	int n; cin >> n;
	int sack_size; cin >> sack_size;

	vector<int>profit(n);
	for (int i = 0; i < n; ++i) {
		cin >> profit[i];
	}

	vector<int>weight(n);
	for (int i = 0; i < n; ++i) {
		cin >> weight[i];
	}


	int dp[sack_size + 1];
	memset(dp, 0, sizeof dp);

	for (auto i = 1; i < int(profit.size()) + 1; ++i) {
		for (auto w = sack_size; w >= 0; --w) {
			if (weight[i - 1] <= w) {
				dp[w] = max(dp[w], profit[i - 1] + dp[w - weight[i - 1]]);
			}
		}
	}

	cout << dp[sack_size] << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
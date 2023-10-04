#include <bits/stdc++.h>
using namespace std;

void tcase() {
	int ammount = 12;
	vector<int>coins = {1, 2, 3, 4, 5};
	vector<int>dp(ammount + 1, ammount + 1);

	dp[0] = 0;
	for (auto a = 1LL; a <= ammount; ++a)
		for (auto c : coins)
			if (a - c >= 0)
				dp[a] = min(dp[a], dp[a - c] + 1);

	cout << dp[ammount] << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
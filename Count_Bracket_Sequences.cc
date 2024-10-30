#include <bits/stdc++.h>
using namespace std;

string s;
const int64_t M = 998244353;
const int64_t N = int(3010 + 7);
vector<vector<int64_t>>dp(N, vector<int64_t>(N, -1));

int64_t fun (int64_t i , int64_t sum) {

	if (sum < 0)
		return 0;

	if (i == int(s.size()))
		return !sum;

	if (dp[i][sum] != -1)
		return dp[i][sum];

	if (s[i] == '?')
		return dp[i][sum] = (fun(i + 1, sum + 1) + fun(i + 1, sum - 1)) % M;
	else
		return dp[i][sum] = (fun(i + 1, sum + (s[i] == '(' ? 1 : -1))) % M ;
}

void tcase() {
	cin >> s;
	cout << fun(0ll, 0ll) << '\n';

}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	// cin >> t;

	while (t-- > 0)
		tcase();
}
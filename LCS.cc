#include <bits/stdc++.h>
using namespace std;
string c_lcs(const string &s1, const string &s2) {
	int n = s1.size();
	int m = s2.size();
	int dp[n + 1][m + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);


	string con;
	while (n > 0 && m > 0) {
		if (s1[n - 1] == s2[m - 1]) {
			con.push_back(s1[n - 1]);
			n--, m--;
		} else if (dp[n - 1][m] > dp[n][m - 1]) {
			n--;
		} else {
			m--;
		}
	}
	return string(con.rbegin(), con.rend());
}
void tcase() {
	string a, b; cin >> a >> b;
	cout << c_lcs(a, b) << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
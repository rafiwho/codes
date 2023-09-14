#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif

#define pb push_back
#define in insert
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()

const int N = 1e3;
std::vector<std::vector<int>>dp(N, std::vector<int>(N, -1));

int LCS( string &s1 , string &s2, int i = 0, int j = 0) {
	if (i == int(s1.size()) || j == int(s2.size()))
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];

	int ans = LCS(s1, s2, i + 1, j);
	ans = max(ans , LCS(s1, s2, i, j + 1));
	ans = max(ans , LCS(s1, s2, i + 1, j + 1) + (s1[i] == s2[j]));
	return dp[i][j] = ans;
}

void tcase() {
	string s1 , s2;
	cin >> s1 >> s2;
	cout << LCS(s1, s2) << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
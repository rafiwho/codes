#include "bits/stdc++.h"
using namespace std;
template <typename T>
T Construct_LCS(const T &S, const T &t) {
	int n = int(S.size());
	int m = int(t.size());
	vector<int> dp(m + 1, 0);
	vector<vector<bool>> previous(n + 1, vector<bool>(m + 1, false));

	for (int i = 0; i < n; i++) {
		vector<int> next_dp(m + 1, 0);

		for (int j = 0; j < m; j++)
			if (S[i] == t[j]) {
				next_dp[j + 1] = dp[j] + 1;
			} else {
				next_dp[j + 1] = max(dp[j + 1], next_dp[j]);
				previous[i + 1][j + 1] = next_dp[j + 1] == next_dp[j];
			}

		swap(dp, next_dp);
	}

	int a = n, b = m;
	T common;

	while (a > 0 && b > 0) {
		if (S[a - 1] == t[b - 1]) {
			common.push_back(S[a - 1]);
			a--; b--;
			continue;
		}

		if (previous[a][b])
			b--;
		else
			a--;
	}

	reverse(common.begin(), common.end());
	return common;
}

void tcase() {
	string s1 , s2;
	cin >> s1 >> s2;
	cout << Construct_LCS(s1, s2) << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
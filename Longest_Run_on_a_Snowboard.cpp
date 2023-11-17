#include <bits/stdc++.h>
using namespace std;
constexpr int N = 205;
int dp[N][N];
int v[N][N];
int r, c;
vector<array<int, 2>>moves = {
	{0, 1}, {1, 0}, {0, -1}, { -1, 0}
};
bool val(int i, int j) {
	return i >= 0 && j >= 0 && i < r && j < c;
}
int dfs(int i, int j) {
	if (dp[i][j])
		return dp[i][j];
	for (auto move : moves) {
		int n_i = i + move[0];
		int n_j = j + move[1];
		if (val(n_i, n_j)) {
			if (v[i][j] > v[n_i][n_j]) {
				dp[i][j] = max(dp[i][j], 1 + dfs(n_i, n_j));
			}
		}
	}
	return dp[i][j];
}
void tcase() {
	memset(dp, 0, sizeof dp);
	int ans = 0;
	string s; cin >> s;
	cout << s << ": ";
	cin >> r >> c;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> v[i][j];
		}
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			ans = max(ans, dfs(i, j));
		}
	}
	cout << ans + 1 << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	cin >> t;

	while (t-- > 0)
		tcase();
}
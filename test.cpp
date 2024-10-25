#include <bits/stdc++.h>
using namespace std;

const int N  = 1E5 + 5;
vector<vector<int>>dp(N, vector<int>(3, -1));
vector<array<int, 3>>v;
int n;

int f(int i, int X) {
	if (i >= n) return 0;
	int &ans = dp[i][X];
	if (~ans) return ans;
	ans = 0;
	for (int x : {0, 1, 2})
		if (X ^ x)
			ans = max(ans, v[i][x] + f(i + 1, x));

	return ans;
}
void tcase() {
	cin >> n;
	v.resize(n);
	for (auto &[x, y, z] : v) {
		cin >> x >> y >> z;
	}
	int ans = 0;
	cout << max({f(0, 1), f(0, 0), f(0, 2)}) << '\n';
}
int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int32_t t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
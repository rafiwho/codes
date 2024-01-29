
#include <bits/stdc++.h>
using namespace std;
constexpr int Mod = 100000007;
int solve_ge(vector<int>&e, int t) {
	int ways = 1;
	for (int i = 0; i < e.size(); ++i) {
		ways = 1LL * ways * (e[i] / t + 1) % Mod;
	}
	return ways;
}
int solve(vector<int>&e, int t) {
	return (solve_ge(e, t) - solve_ge(e, t + 1) + Mod) % Mod;
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, t, cs = 1;

	while (cin >> n >> m >> t && (n | m | t)) {
		cout << "Case " << cs++ << ": ";
		vector<int>e;
		for (int i = 2; i * i <= n; ++i) {
			if (n % i == 0) {
				int cnt = 0;
				while (n % i == 0) {
					++cnt;
					n /= i;
				}
				e.emplace_back(cnt * m);
			}
		}
		if (n > 1) {
			e.emplace_back(m);
		}
		cout << solve(e, t) << '\n';
	}
}
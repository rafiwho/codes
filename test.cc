#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 101;
ll a[N];
int n, dp[64][N][64][2];
array<int, 2> fre[64];
const int BIT = 62;

int f(int i, int sz, int bit_cnt, bool nisi) {
	// cout << i << ' ' << sz << ' ' << bit_cnt << '\n';
	if (i == BIT) {
		if (nisi)
			return sz - bit_cnt;
		else
			return INT_MIN;
	}

	int &ans = dp[i][sz][bit_cnt][nisi];
	if (~ans) return ans;
	ans = 0;
	ans = max(ans, f(i + 1, sz = min(sz, fre[i][0]) , bit_cnt, true));
	ans = max(ans, f(i + 1, sz = min(sz , fre[i][1]) , bit_cnt + 1, true));
	ans = max(ans, f(i + 1, sz, bit_cnt, nisi));
	return ans;
}

void tcase() {
	for (int i = 0; i < 64; ++i) {
		fre[i] = {};
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < 64; ++k) {
				for (int l = 0; l < 2; ++l) {
					dp[i][j][k][l] = -1;
				}
			}
		}
	}

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (int k = 0; k < 63; ++k) {
			if (1 & (a[i] >> k)) {
				fre[k][1]++;
			} else {
				fre[k][0]++;
			}
		}
	}
	cout << f(0, n, 0, 0) << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int32_t t = 1;
	cin >> t;
	while (t-- > 0)
		tcase();
}

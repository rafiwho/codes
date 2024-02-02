#include <bits/stdc++.h>
using namespace std;
constexpr int N = 55;
constexpr int MOD = 100000007;
int coins[N], fre[N], n, req, dp[N][1001];

void tcase() {
	 cin >> n >> req;
	 for (int i = 0; i < n; ++i) {
	     cin >> coins[i];
	 }
	 for (int i = 0; i < n; ++i) {
	     cin >> fre[i];
	 }

	 for (int i = n; i >= 0; --i) {
	     for (int sum = 0; sum <= req; ++sum) {
	         int &ans = dp[i][sum];
	         if (i == n) {
	             ans = (sum == req);
	         } else {
	             ans = 0;
	             for (int k = 0; k <= fre[i]; ++k) {
	                 if (sum + coins[i] * k <= req) {
	                     ans += dp[i + 1][sum + coins[i] * k];
	                     // ans %= MOD;
	                     if(ans > MOD){
	                     	ans -= MOD;                        }
	                 }
	             }
	         }
	     }
	 }
	 cout << dp[0][0] << '\n';
	}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1, cs = 1;
    cin >> t;

    while (t-- > 0) {
        cout << "Case " << cs++ << ": ";
        tcase();
    }
}

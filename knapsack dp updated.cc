#include <bits/stdc++.h>
using namespace std;

constexpr int N = 101;
constexpr int M = 1E5 + 5;
int weight[N], value[N];
long long dp[M];

void tcase() {
    int n, max_cap;
    cin >> n >> max_cap;
    for (int i = 1; i <= n; ++i) {
        cin >> weight[i] >> value[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int w = max_cap; w >= 0; --w) { 
            if (w - weight[i] >= 0) {
                long long &ans = dp[w];
                ans = max(ans, dp[w - weight[i]] + value[i]);
            }
        }
    }
    cout << dp[max_cap] << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while (t-- > 0)
        tcase();
}

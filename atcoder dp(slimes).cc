#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int N = 404;
constexpr i64 INF = 1E15;
int arr[N], n;
i64 sum = 0;
i64 pre[N];
i64 dp[N][N];

i64 f(int l, int r) {
  if (l == r) {
    return 0;
  }
  i64 &ans = dp[l][r];
  if(~ans)return ans;
  ans = INF;
  for (int i = l; i < r; ++i) {
    ans = min(ans,f(l,i)+f(i+1,r)+pre[r]-pre[l-1]);
  }
  return ans;
}
void tcase() {
  cin >> n;
  memset(dp,-1,sizeof dp);
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    pre[i] = pre[i - 1] + arr[i];
  }
  cout << f(1, n) << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  //cin >> t;

  while (t-- > 0)
    tcase();
}

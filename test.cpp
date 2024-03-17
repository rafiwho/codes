#include <bits/stdc++.h>
using namespace std;

void tcase() {
  string s; cin >> s;
  int n = s.size();
  int dp[n+1];
  memset(dp,0,sizeof dp);
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      if(s[i] == s[j] || s[i] == '?' || s[j] == '?'){
        dp[j] = 1 + dp[i];
      }else{
        dp[j] = 1;
      }
    }
  }
  cout << *max_element(dp,dp+n) << '\n';
}
int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int t = 1;
   cin >> t;

   while (t-- > 0)
     tcase();
}
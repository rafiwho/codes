#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int dp[N][N],DP[N][N];
string s; 
int n;
bool is_pal(int l,int r){
  if(r-l+1 < 3){
    return s[l] == s[r];
  }else{
    int& ans = DP[l][r];
    if(~ans)return ans;
    ans = s[l] == s[r] && is_pal(l+1,r-1);
    return ans;
  }
}
int f(int l,int r){
  if(l == r)return 1;
  if(!is_pal(l,r))return 0;
  int& ans = dp[l][r];
  if(~ans)return ans;
  ans = 1;
  int l_r = (l+r) >> 1;
  l_r -= (r-l+1) % 2;
  if(is_pal(l,l_r)){
    ans += f(l,l_r);
  }
  return ans;
}
long long cnt[N];
void tcase() {
  memset(dp,-1,sizeof dp);
  memset(DP,-1,sizeof DP);
  cin >> s;
  n = s.size();
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = i; j < n; ++j) {
      cnt[f(i,j)]++;
    }
  }
  for (size_t i = n; i > 0; --i) {
    cnt[i] += cnt[i+1];
  }
  for (size_t i = 1; i <= n; ++i) {
    cout << cnt[i] <<" \n"[i == n];
  }
}
int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int t = 1;
   //cin >> t;

   while (t-- > 0)  
     tcase();
}
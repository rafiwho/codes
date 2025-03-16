int dp[10][2][11];
int f(int pos, bool tight, int cnt1) {
  if (pos == size(num)) return cnt1;
  int &ans = dp[pos][tight][cnt1];
  if (~ans) return ans;
  ans = {};
  int lim = tight ? num[pos] - '0' : 9;
  for (int d = 0; d <= lim; ++d) {
    ans += f(pos + 1, tight && (d == lim), cnt1 + (d == 1));
  }
  return ans;
}
// count of fre[1] from 1 to N

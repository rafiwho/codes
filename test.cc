#include <bits/stdc++.h>
using namespace std;
const int inf = 1E9;
void tcase() {
  int n; cin >> n;
  int arr[2][n];
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
    }
  }

  int pre[n],suf[n];
  fill(pre,pre + n,-inf);
  fill(suf,suf + n,-inf);

  for (int i = 0; i < n; ++i) {
    pre[i] = (i ? pre[i - 1] : 0) + max(arr[0][i],arr[1][i]);
    suf[n - i - 1] = (n - i < n ? suf[n - i] : 0) + max(arr[0][n - i - 1],arr[1][n - i - 1]);
  }
  
  int ans = -inf;
  for (int i = 0; i < n; ++i) {
    if(i == 0){
      ans = max(ans,arr[0][i] + arr[1][i] + (i + 1 < n ? suf[i + 1] : 0));
    }else if(i == n - 1){
      ans = max(ans,arr[0][i] + arr[1][i] + (i ? pre[i - 1] : 0));
    }else{
      ans = max(ans,arr[0][i] + arr[1][i] + (i ? pre[i - 1] : 0) + (i + 1 < n ? suf[i + 1] : 0));
    }
  }
  cout << ans << '\n';
}
int32_t main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int32_t t = 1;
  cin >> t;

  while (t-- > 0)
    tcase();
}
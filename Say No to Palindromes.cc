#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2E5 + 5;
int pre[6][N];
string p[6];
void tcase() {
  int n,q; cin >> n >> q;
  string s; cin >> s;
  string d = "abc";
  int id = 0;
  do{
    while(p[id].size() < n) p[id] += d;
    id++;
  }while(next_permutation(d.begin(),d.end()));
  for (size_t id = 0; id < 6; ++id) {
    for (size_t i = 0; i < n; ++i) {
      pre[id][i] = p[id][i] != s[i];
      if(i)
        pre[id][i] += pre[id][i-1];
    }
  }
  while(q--){
    int l,r; cin >> l >> r;
    --l,--r;
    int ans = n;
    for (size_t id = 0; id < 6; ++id) {
      int cur = pre[id][r] - (l ? pre[id][l-1] : 0);
      ans = min(ans,cur);
    }
    cout << ans << '\n';
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
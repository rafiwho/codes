#include <bits/stdc++.h>
using namespace std;
const int N = 1E6+5, base1 = 121,base2 = 277,mod1 = 1E9 + 7, mod2 = 1E9 + 9;
string s;
array<int,2>pw[N],invpw[N],pref[N];
int p(int a, int b,int M) {
    int ans = 1 % M;
    while (b) {
        if (b & 1) {
            ans = 1LL * ans * a % M;
        }
        a = 1LL * a * a % M;
        b >>= 1;
    }
    return ans;
}
int inv(int a,int m){
  return p(a,m-2,m);
}
void pre(){
  pw[0][0] = 1;
  pw[0][1] = 1;
  for (int i = 1; i < N; ++i) {
    pw[i][0] = 1LL * base1 * pw[i-1][0] % mod1; 
    pw[i][1] = 1LL * base2 * pw[i-1][1] % mod2; 
  }
  invpw[0][0] = 1;
  invpw[0][1] = 1;
  int iv1 = inv(base1,mod1);
  int iv2 = inv(base2,mod2);
  for (int i = 1; i < N; ++i) {
    invpw[i][0] = 1LL * iv1 * invpw[i-1][0] % mod1;
    invpw[i][1] = 1LL * iv2 * invpw[i-1][1] % mod2;
  }
}
array<int,2> get_h(string &s){
  array<int,2> hash = {0,0};
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    hash[0] += 1LL * s[i] * pw[i][0] % mod1;
    hash[0] %= mod1;
    hash[1] += 1LL * s[i] * pw[i][1] % mod2;
    hash[1] %= mod2;
  }
  return hash;
}
void build(string &s){
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    pref[i][0] = 1LL * s[i] * pw[i][0] % mod1;
    if(i)
      pref[i][0] = (pref[i-1][0]  + pref[i][0]) % mod1; 
    pref[i][1] = 1LL * s[i] * pw[i][1] % mod2;
    if(i)
      pref[i][1] = (pref[i-1][1]  + pref[i][1]) % mod2;
  }
}
array<int,2>get_substr_h(int l,int r){
  assert(l <= r);
  array<int,2>hash = {0,0};
  hash[0] = (pref[r][0] - pref[l-1][0] + mod1) % mod1;
  hash[0] = (1LL *hash[0] * invpw[l][0]) % mod1;
  hash[1] = (pref[r][1] - pref[l-1][1] + mod2) % mod2;
  hash[1] = (1LL *hash[1] * invpw[l][1]) % mod2;
  return hash;
}

void tcase() {
  cin >> s;
  int n = s.size();
  build(s);
  for (int len = 1; len <= n; ++len) {
    bool yo = true;
    for (int i = len; i < n; i+=len) {
      int j = min(i + len - 1,n-1);
      yo &= get_substr_h(i,j)==get_substr_h(0,j-i);
      if(!yo)break;
    }
    if(yo){
      cout << len << ' ';
    }
  }
  cout << '\n';
}
int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);pre();

   int t = 1;
   //cin >> t;

   while (t-- > 0)
     tcase();
}
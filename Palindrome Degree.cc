#include <bits/stdc++.h>
using namespace std;
constexpr  int base1 = 121, base2 = 263;
constexpr  int mod1 = 1E9 + 7, mod2 = 1E9 + 9;
constexpr  int N = 5E6 + 5; // modify

array<int, 2> pw[N], invpw[N];
int dp[N];
int p(int a, int b, int M) {
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
 
int inv(int n, int m) {
  return p(n, m - 2, m);
}
void pre() {
      pw[0][0] = 1;
      pw[0][1] = 1;
      for (int i = 1; i < N; ++i) {
          pw[i][0] = (1LL * pw[i - 1][0] * base1) % mod1;
          pw[i][1] = (1LL * pw[i - 1][1] * base2) % mod2;
      }
      invpw[0][0] = 1;
      invpw[0][1] = 1;
      int iv1 = inv(base1, mod1);
      int iv2 = inv(base2, mod2);
      for (int i = 1; i < N; ++i) {
          invpw[i][0] = (1LL * invpw[i - 1][0] * iv1) % mod1;
          invpw[i][1] = (1LL * invpw[i - 1][1] * iv2) % mod2;
      }
  }

struct Hashing {
  string s;
  array<int, 2> pref[N];

  void build(string &t) {
      s = t;
      int n = s.size();
      for (int i = 0; i < n; ++i) {
          pref[i][0] = (1LL * s[i] * pw[i][0]) % mod1;
          if (i) pref[i][0] = (pref[i][0] + pref[i - 1][0]) % mod1;
          pref[i][1] = (1LL * s[i] * pw[i][1]) % mod2;
          if (i) pref[i][1] = (pref[i][1] + pref[i - 1][1]) % mod2;
      }
  }

  array<int, 2> get_sub_hash(int l, int r) {
      // assert(l <= r);
      array<int, 2> hs{0, 0};
      hs[0] = pref[r][0];
      if (l) hs[0] = (hs[0] - pref[l - 1][0] + mod1) % mod1;
      hs[0] = (1LL * hs[0] * invpw[l][0]) % mod1;
      hs[1] = pref[r][1];
      if (l) hs[1] = (hs[1] - pref[l - 1][1] + mod2) % mod2;
      hs[1] = (1LL * hs[1] * invpw[l][1]) % mod2;
      return hs;
  }
}S,R;

int n;
bool ispal(int l,int r){
	return S.get_sub_hash(l,r) == R.get_sub_hash(n-r-1,n-l-1);
}
string s,r;
bool is_pal[N];

// int f(int i) {
//     if (!is_pal[i]) return 0;
//     if (i == 0) return 1;

//     int& dp[i] = dp[i];
//     if (~dp[i]) return dp[i];

//     int mid = i >> 1;
//     if(((i + 1)&1))
//     	mid--;
//     dp[i] = 1;
//     if (is_pal[mid]) {
//         dp[i] += f(mid);
//     }
//     return dp[i];
// }
// int dp[N];
void tcase() {
	cin >> s;
	n = s.size();
	r = string(s.rbegin(),s.rend());
	S.build(s);
	R.build(r);
	for (size_t i = 0; i < n; ++i) {
		is_pal[i] = ispal(0,i);
	}
	long long res=0;
	for (size_t i = 0; i < n; ++i) {
		if(i == 0){
			dp[i] = 1;
			continue;
		}
		if(!is_pal[i]){
			dp[i] = 0;
			continue;
		}
		int mid = (i >> 1);
		mid -= ((i + 1) & 1);
		dp[i] = 1;
		if(is_pal[mid]){
			dp[i] += dp[mid];
		}
	}
	for (size_t i = 0; i < n; ++i) {
		res += dp[i];
	}
	cout << res << '\n';
}
int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr); pre();

   int t = 1;
   //cin >> t;

   while (t-- > 0)
     tcase();
}
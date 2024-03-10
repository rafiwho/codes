#include <bits/stdc++.h>
using namespace std;
const int base1 = 121, base2 = 263;
const int mod1 = 1E9 + 7, mod2 = 1E9 + 9;
const int N = 1E6 + 5; // modify

array<int, 2> pw[N], invpw[N];

class Hashing {
private:

  string s;
  array<int, 2> pref[N];

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
 
public:
  Hashing() {
      pre();
  }
 
  void pre() {
      pw[0][0] = 1;
      pw[0][1] = 1;
      for (int i = 1; i < N; ++i) {
          pw[i][0] = 1LL * pw[i - 1][0] * base1 % mod1;
          pw[i][1] = 1LL * pw[i - 1][1] * base2 % mod2;
      }
      invpw[0][0] = 1;
      invpw[0][1] = 1;
      int iv1 = inv(base1, mod1);
      int iv2 = inv(base2, mod2);
      for (int i = 1; i < N; ++i) {
          invpw[i][0] = 1LL * invpw[i - 1][0] * iv1 % mod1;
          invpw[i][0] %= mod1;
          invpw[i][1] = 1LL * invpw[i - 1][1] * iv2 % mod2;
          invpw[i][1] %= mod2;
      }
  }
 
  array<int, 2> get_hash(string &s) {
      int n = s.size();
      array<int, 2> hash{0, 0};
      for (int i = 0; i < n; ++i) {
          hash[0] = (hash[0] + 1LL * s[i] * pw[i][0]) % mod1;
          hash[1] = (hash[1] + 1LL * s[i] * pw[i][1]) % mod2;
      }
      return hash;
  }
 
  void build(string &t) {
      s = t;
      int n = s.size();
      for (int i = 0; i < n; ++i) {
          pref[i][0] = 1LL * s[i] * pw[i][0] % mod1;
          if (i) pref[i][0] = (pref[i][0] + pref[i - 1][0]) % mod1;
          pref[i][1] = 1LL * s[i] * pw[i][1] % mod2;
          if (i) pref[i][1] = (pref[i][1] + pref[i - 1][1]) % mod2;
      }
  }
 
  array<int, 2> get_sub_hash(int l, int r) {
      assert(l <= r);
      array<int, 2> hs{0, 0};
      hs[0] = pref[r][0];
      if (l) hs[0] = (hs[0] - pref[l - 1][0] + mod1) % mod1;
      hs[0] = (1LL * hs[0] * invpw[l][0]) % mod1;
      hs[1] = pref[r][1];
      if (l) hs[1] = (hs[1] - pref[l - 1][1] + mod2) % mod2;
      hs[1] = (1LL * hs[1] * invpw[l][1]) % mod2;
      return hs;
  }
}H,h;
int odd[N],even[N];
void tcase() {
	string s; cin >> s;

	string r = string(s.rbegin(), s.rend());
	int n = s.size();

	H.build(s);
	h.build(r);
	// a b c d e f
	// 0 1 2 3 4 5
	// f e d c b a

	auto ok = [&](int l,int r)->bool{
		return H.get_sub_hash(l,r) == h.get_sub_hash(n-r-1,n-l-1);
	};

	for (int cen = 0; cen < n; ++cen) {
		int lo = 1,hi = min(cen,n-cen-1),ans=0;
		while(hi >= lo){
			int mid = (hi + lo) >> 1;
			if(ok(cen-mid,cen+mid)){
				ans = mid;
				lo = mid+1;
			}else{
				hi = mid-1;
			}
		}
		odd[cen] = ans;
	}

	// a b c d e f
	// 0 1 2 3 4 5
	// f e d c b a

	for (int cen = 0; cen < n; ++cen) {
		int lo = 1,hi = min(cen,n-cen),ans=0;
		while(hi >= lo){
			int mid = (hi + lo) >> 1;
			if(ok(cen-mid,cen+mid-1)){
				ans = mid;
				lo = mid+1;
			}else{
				hi = mid-1;
			}
		}
		even[cen] = ans;
	}

	auto ans = array{0,0};
	int mx_len = 0;

	for (int i = 0; i < n; ++i) {
		int len = 2 * odd[i] + 1;
		if(len > mx_len){
			mx_len = len;
			ans = {i - odd[i],i + odd[i]};
		}
	}

	for (int i = 0; i < n; ++i) {
		int len = 2 * even[i];
		if(len > mx_len){
			mx_len = len;
			ans = {i-even[i],i + even[i]-1};
		}
	}
	cout << s.substr(ans[0],ans[1] - ans[0] + 1) << '\n';
}
int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int t = 1;
   //cin >> t;

   while (t-- > 0)
     tcase();
}
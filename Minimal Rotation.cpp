#include <bits/stdc++.h>
using namespace std;
constexpr static int base1 = 121, base2 = 263;
constexpr static int mod1 = 1E9 + 7, mod2 = 1E9 + 9;
constexpr static int N = 2E6 + 5; // modify

array<int, 2> pw[N], invpw[N];
array<int, 2> pref[N];

class Hashing {
private:

  string s;

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
};
void tcase() {
	string s; cin >> s;
	int sz = s.size();
	Hashing h;
	s += s;
	int n = s.size();
	h.build(s);

	auto prev = array{0,sz-1};

	auto get_lcp = [&](int i,int j,int l,int r)->int{
		int len = min(j-i+1,r-l+1);
		int lo = 1,hi = len,ans=0;
		while(lo <= hi){
			int mid = (hi + lo) >> 1;
			if(h.get_sub_hash(i,i+mid-1) == h.get_sub_hash(l,l+mid-1)){
				ans = mid;
				lo = mid+1;
			}else{
				hi = mid-1;
			}
		}
		return ans;
	};
	
	auto cmp = [&](int i,int j,int l,int r)->bool{
		int lcp = get_lcp(i,j,l,r);
		int len1 = j-i+1,len2= r-l+1;
		if(lcp == len1 && lcp == len2){
			return false;
		}else if(lcp == len1){
			return false;
		}else if(lcp == len2){
			return false;
		}else{
			return s[i+lcp] > s[l+lcp];
		}
	};



	for (int i = 0; i < sz; ++i) {
		if(cmp(prev[0],prev[1],i,i+sz-1)){
			prev = {i,i+sz-1};
		}
	}


	cout << s.substr(prev[0],sz) << '\n';
}
int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int t = 1;
   //cin >> t;

   while (t-- > 0)
     tcase();
}
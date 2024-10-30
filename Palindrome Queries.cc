#include <bits/stdc++.h>
using namespace std;
constexpr  int base1 = 121, base2 = 263;
constexpr  int mod1 = 1E9 + 7, mod2 = 1E9 + 9;
constexpr  int N = 2E5 + 5; // modify
 
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
array<int,2>pw[N],invpw[N];
 
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
 
 
using Node = array<int, 2>;
struct hashing {
    string s;
    int n;
 
    vector<Node> t;
    hashing() {}
 
    hashing(string _s) {
        s = _s;
        n = s.size();
        t.resize(n << 2);
        build(1, 0, n - 1);
    }
 
    Node combine(Node a, Node b) {
        Node x = Node{(a[0] + b[0]) % mod1, (a[1] + b[1]) % mod2};
        return x;
    }
 
    Node mul(Node a, int x) {
        Node P = {int(1LL * a[0] * x % mod1), int(1LL * a[1] * x % mod2)};
        return P;
    }
    Node mul(Node a,Node b){
    	a[0] = 1LL * a[0] * b[0] % mod1;
    	a[1] = 1LL * a[1] * b[1] % mod2;
    	return a;
    }
 
    void build(int node, int st, int en) {
        if (st == en) {
            t[node] = mul(pw[st], s[st]);
            return;
        }
        int mid = (st + en) >> 1;
        build(node << 1, st, mid);
        build(node << 1 | 1, mid + 1, en);
        t[node] = combine(t[node << 1], t[node << 1 | 1]);
    }
 
    void update(int node, int st, int en, int i, char v) {
        if (i < st || i > en)
            return;
        if (st == en) {
            t[node] = mul(pw[i], v);
            s[i] = v;
            return;
        }
        int mid = (st + en) >> 1;
        update(node << 1, st, mid, i, v);
        update(node << 1 | 1, mid + 1, en, i, v);
        t[node] = combine(t[node << 1], t[node << 1 | 1]);
    }
 
    Node query(int node, int st, int en, int l, int r) {
        if (l > en || r < st)
            return Node{0, 0};
        if (st >= l && en <= r)
            return t[node];
        int mid = (st + en) >> 1;
        Node p = query(node << 1, st, mid, l, r);
        Node q = query(node << 1 | 1, mid + 1, en, l, r);
        return combine(p, q);
    }
 
    void upd(int pos, char ch) {
        update(1, 0, n - 1, pos, ch);
    }
 
    Node qry(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
    Node get_hash(int l,int r){
    	return mul(qry(l,r),invpw[l]);
    }
};
 
void tcase() {
    int n,q; cin >> n >> q;
    string s; cin >> s;
    string r = string(s.rbegin(),s.rend());
    hashing S(s);
    hashing R(r);
    while(q--){
    	int ty; cin >> ty;
    	if(ty == 1){
    		int pos; char ch; cin >> pos >> ch;
    		--pos;
    		S.upd(pos,ch);
    		R.upd(n-pos-1,ch);
    	}else{
    		int l,r; cin >> l >> r;
    		--l,--r;
    		if(S.get_hash(l,r) == R.get_hash(n-r-1,n-l-1)){
    			cout << "YES\n";
    		}else{
    			cout << "NO\n";
    		}
    	}
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    pre();
 
    int t = 1;
    // cin >> t;
 
    while (t-- > 0)
        tcase();
 
    return 0;
}
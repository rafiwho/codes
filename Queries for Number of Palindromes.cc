#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int dp1[N][N],dp[N][N];
int n; string s;
bool is_pal(int i,int j){
	if(i == j || j - i + 1 == 2){
		return s[i] == s[j];
	}
	int &ans = dp1[i][j];
	if(~ans)return ans;
	ans = (s[i] == s[j]) && is_pal(i+1,j-1);
	return ans;
}
int f(int i,int j){
	if(i > j)return 0;
	int &ans = dp[i][j];
	if(~ans)return ans;
	ans = 0;
	ans = is_pal(i,j) + f(i+1,j) + f(i,j-1) - f(i+1,j-1);
	return ans;
}
void tcase() {
	cin >> s;
	n = s.size();
	int q; cin >> q;
	memset(dp,-1,sizeof dp);
	memset(dp1,-1,sizeof dp1);
	while(q--){
		int l,r; cin >> l >> r;
		--l,--r;
		cout << f(l,r) << '\n';
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
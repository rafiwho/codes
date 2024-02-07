#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1001,MOD = 1E9+7;
std::vector<string> v;
int dp[N][N],n,m;
int f(int i,int j){
	if(i >= n || j >= m)return 0;
	if(v[i][j] == '#')return 0;
	if(i == n-1 && j == m-1)return 1;
	int &ans = dp[i][j];
	if(~ans)return ans;
	ans = 0;
	ans += f(i,j+1);
	ans %= MOD;
	ans += f(i+1,j);
	ans %=MOD;
	return ans;
}
void tcase() {
	memset(dp,-1,sizeof dp);
	cin >> n >> m;
	v.resize(n);
	for(auto& row:v)
		cin >> row;
	cout << f(0,0) << '\n';
}
int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int t = 1;
   //cin >> t;

   while (t-- > 0)
     tcase();
}
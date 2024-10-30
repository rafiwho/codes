#include <bits/stdc++.h>
using namespace std;
constexpr int N = 51;
string a,b,c;
int dp[N][N][N];
// LCS between a,b,c
int f(int i,int j,int k){
	if(i == a.size() || j == b.size() || k == c.size())return 0;
	int &ans = dp[i][j][k];
	if(~ans)return ans;
	ans = 0;
	if(a[i] == b[j] && b[j] == c[k]){
		ans = 1 + f(i+1,j+1,k+1);
	}else{
		ans = max({ans,f(i+1,j,k),f(i,j+1,k),f(i,j,k+1)});
	}
	return ans;
}
void tcase() {
	memset(dp,-1,sizeof dp);
	cin >> a >> b >> c;
	cout << f(0,0,0) << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1, cs = 1;
	cin >> t;

	while (t-- > 0) {
		cout << "Case " << cs++ << ": ";
		tcase();
	}
}
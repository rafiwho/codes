#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3003;
string a,b;
int dp[N][N];
int f(int i,int j){
	if(i >= a.size() || j >= b.size())return 0;
	int &ans=dp[i][j];
	if(~ans)return ans;
	ans = 0;
	if(a[i] == b[j]){
		ans = max(ans,1+f(i+1,j+1));
	}else{
		ans = max({ans,f(i+1,j),f(i,j+1)});
	}
	return ans;
}
void lcs(int i,int j){
	if(i == a.size() || j == b.size())return;
	if(a[i] == b[j]){
		cout << a[i];
		lcs(i+1,j+1);
	}else{
		int x = f(i+1,j);
		int y = f(i,j+1);
		if(x >= y){
			lcs(i+1,j);
		}else{
			lcs(i,j+1);
		}
	}
}
void tcase() {
	memset(dp,-1,sizeof dp);
	cin >> a >> b;
	lcs(0,0);
}
int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int t = 1;
   //cin >> t;

   while (t-- > 0)
     tcase();
}
#include <bits/stdc++.h>
using namespace std;
string s;
constexpr int N = 1001;
int dp[N][N];
int f(int i,int j){
	if(i < 0 || j >= s.size())return 0;
	int& ans=dp[i][j];
	if(~ans)return ans;
	ans = 0;
	if(i == j){
		ans = 1 + f(i-1,j+1);
	}else if(s[i] == s[j]){
		ans = max(ans,2+f(i-1,j+1));
	}
	return ans;
}
void tcase() {
	memset(dp,-1,sizeof dp);
	cin >> s;
	int ans = 0;
	for (int i = 0; i < int(s.size()); ++i) {
		ans = max(ans,f(i,i));
	}
	cout << ans << '\n';
}
int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int t = 1;
   cin >> t;

   while (t-- > 0)
     tcase();
}
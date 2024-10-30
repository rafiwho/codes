#include <bits/stdc++.h>
using namespace std;
string s;
constexpr int N = 1001;
int dp[N][N];
void tcase() {
	getline(cin,s);
	int n = s.size();
	for (int i = n; i >= 0; --i) {
		for (int j = 0; j < n; ++j) {
			int &ans = dp[i][j];
			if(i > j){
				ans = 0;
			}
			else if(i == j){
				ans = 1;
			}else{
				ans = 0;
				if(s[i] == s[j]){
					ans = 2 + dp[i+1][j-1];
				}else{
					ans = max({ans,dp[i+1][j],dp[i][j-1]});
				}
			}
		}
	}
	cout << dp[0][n-1] << '\n';
	memset(dp,0,sizeof dp);
}
int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int t = 1;
   cin >> t;
   cin.ignore();

   while (t-- > 0)
     tcase();
}
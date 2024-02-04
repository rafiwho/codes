#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3000;
double v[N], dp[N][N],vis[N][N];
int n;
double f(int i,int heads,int tails){
	if(i == n){
		return heads > tails;
	}
	if(vis[i][heads])return dp[i][heads];
	vis[i][heads] = true;
	double ans = f(i+1,heads+1,tails)*v[i];
	ans += (1 - v[i]) * f(i+1,heads,tails+1);
	return dp[i][heads] = ans; 
}
void tcase() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	cout << fixed<<setprecision(10) << f(0,0,0) << '\n';
}
int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int t = 1;
   //cin >> t;

   while (t-- > 0)
     tcase();
}
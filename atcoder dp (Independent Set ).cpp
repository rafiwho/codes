#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1E5 + 5 , MOD = 1E9 + 7;
std::vector<int> v[N];
int dp[N][2];
void dfs(int ver,int p=-1){
	dp[ver][0] = dp[ver][1] = 1;
	for(int child:v[ver]){
		if(child == p)continue;
		dfs(child,ver);
		dp[ver][0] = 1LL * dp[ver][0] * (dp[child][0] + dp[child][1]) % MOD; // for white i can assign white or black in adj
		dp[ver][1] = 1LL * dp[ver][1] * dp[child][0] % MOD; // for black i have to assign white only
	}
}
void tcase() {
	int n; cin >> n;
	for (int i = 0; i < n-1; ++i) {
		int a,b; cin >> a >> b;
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	dfs(1);
	cout << (dp[1][1] + dp[1][0]) % MOD << '\n';
}
int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int t = 1;
   //cin >> t;

   while (t-- > 0)
     tcase();
}
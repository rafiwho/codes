#include <bits/stdc++.h>
using namespace std;
constexpr int N = 3001;
using i64 = long long;
int arr[N];
i64 dp1[N][N];
i64 dp2[N][N];
bool vis1[N][N];
bool vis2[N][N];
i64 f1(int,int);
i64 f2(int l,int r){
	if(l > r)return 0;
	if(vis2[l][r])return dp2[l][r];
	vis2[l][r] = true;
	i64 ans_l = -arr[l] + f1(l+1,r);
	i64 ans_r = -arr[r] + f1(l,r-1);
	return dp2[l][r] = min(ans_l,ans_r);
}
i64 f1(int l,int r){
	if(l > r)return 0;
	if(vis1[l][r])return dp1[l][r];
	vis1[l][r] = true;
	i64 ans_l = arr[l] + f2(l+1,r);
	i64 ans_r = arr[r] + f2(l,r-1);
	return dp1[l][r] = max(ans_l,ans_r);
}
void tcase() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	cout << f1(0,n-1) << '\n';
}
int32_t main() {
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);

   int t = 1;
   //cin >> t;

   while (t-- > 0)
     tcase();
}
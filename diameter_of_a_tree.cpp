#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define debug(...)
#endif

#define pb push_back
#define in insert
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
const int N = int(1e5);
std::vector<int> v[N];
int depth[N];
void dfs(int ver , int par = 0) {
	for (auto child : v[ver]) {
		if (child == par)
			continue;

		depth[child] = depth[ver] + 1;
		dfs(child, ver);
	}
}
void tcase() {
	int n ;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x , y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1);

	int mx_depth = -1;
	int mx_node;

	for (int i = 1; i <= n; ++i) {
		if (depth[i] > mx_depth) {
			mx_depth = depth[i];
			mx_node = i;
		}
		depth[i] = 0;
	}
	dfs(mx_node);
	int diameter = *max_element(depth, depth + n);
	cout << diameter << '\n';

}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
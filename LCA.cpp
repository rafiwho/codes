#include <algorithm>
#include <iostream>
#include <vector>
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
const int N = int(1e5 + 7);
vector<int>v[N];
int pr[N];
void dfs(int ver , int par = -1) {
	pr[ver] = par;
	for (auto child : v[ver]) {
		if (par == child)
			continue;
		else
			dfs(child, ver);
	}
}

vector<int> path(int v) {
	vector<int>ans;
	while (v != -1) {
		ans.pb(v);
		v = pr[v];
	}
	reverse(all(ans));
	return ans;
}
void tcase() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int x , y;
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}

	dfs(1);
	// enter two node to find their lca
	int a, b;
	cin >> a >> b;
	vector<int>path_a = path(a);
	vector<int>path_b = path(b);


	int lca = -1;
	for (int i = 0; i < int(min(path_a.size() , path_b.size())); ++i) {
		if (path_a[i] == path_b[i])
			lca = path_a[i] ;
		else {
			break;
		}
	}
	cout << lca << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
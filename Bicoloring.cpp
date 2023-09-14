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

const int N = 210;
std::vector<int> g[N];
bool vis[N];
bool col[N];
bool f ;

void dfs(int ver) {
	vis[ver] = true;
	for (auto child : g[ver]) {
		if (!vis[child]) {
			col[child] = !col[ver];
			dfs(child);
		}
		if (col[child] == col[ver]) {
			f = true;
		}
	}
}

void tcase() {
	int n, m;
	while (cin >> n >> m && n) {

		for (int i = 0; i < m; ++i) {
			int x , y;
			cin >> x >> y;
			g[x].pb(y);
			g[y].pb(x);
		}

		f = false;
		for (int i = 0; i < n; ++i) {
			if (!vis[i]) {
				dfs(i);
			}
			if (f) {
				break;
			}
		}

		cout << (f ? "NOT BICOLORABLE.\n" : "BICOLORABLE.\n");
		for (int i = 0; i < N; ++i) {
			g[i].clear();
			vis[i] = false;
			col[i] = false;
		}
	}

}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
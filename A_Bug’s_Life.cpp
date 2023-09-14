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

const int N = 1e6 + 10;
std::vector<int>g[N];
bool vis[N];
bool color[N];
bool f ;

void dfs(int vertex) {
	vis[vertex] = true;
	for (auto&child : g[vertex]) {
		if (!vis[child]) {
			color[child] = !color[vertex];
			dfs(child);
		}
		if (color[child] == color[vertex]) {
			f = false;
		}
	}
}
int xx = 0;
void tcase() {
	int n , m ;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int x , y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}

	f = true;
	for (int i = 1; i <= n; ++i) {
		if (!vis[i])
			dfs(i);
		if (!f)
			break;
	}

	cout << "Scenario #" << ++xx << ":\n";
	cout << (!f ? "Suspicious bugs found!\n" : "No suspicious bugs found!\n");

	memset(vis , false , sizeof vis);
	memset(color , false , sizeof color);
	for (int i = 0; i < N; ++i) {
		g[i].clear();
	}
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	cin >> t;

	while (t-- > 0)
		tcase();
}
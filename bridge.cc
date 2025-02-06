
#include <bits/stdc++.h>
using namespace std;
const int N = 1E5 + 5;
vector<int>v[N];
vector<int>in(N), low(N);
vector<bool> vis(N);
int timer = 1, n, m;
void dfs(int ver, int par) {
	vis[ver] = true;
	in[ver] = low[ver] = timer++;
	for (int nei : v[ver]) {
		if (nei == par) continue;
		if (vis[nei] == 0) {
			dfs(nei, ver);
			low[ver] = min(low[nei], low[ver]);
			if (low[nei] > in[ver]) {
				cout << 0 << '\n'; // bridge
				exit(0);
			}
		} else {
			low[ver] = min(low[nei], low[ver]);
		}
	}
}
void tcase() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y; cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1, -1);
}
int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int32_t t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
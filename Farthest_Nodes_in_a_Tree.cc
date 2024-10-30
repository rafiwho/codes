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
const int N = 3e4 + 9;
std::vector<pair<int, int>> v[N];
void tcase() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int x , y , w;
		cin >> x >> y >> w;
		v[x].pb({y, w});
		v[y].pb({x, w});
	}

	vector<int>cost(n);
	function<int(int)>bfs = [&](int source) {
		vector<bool>vis(n);
		queue<int>q;
		q.push(source);
		vis[source] = true;
		cost[source] = 0;
		while (!q.empty()) {
			int cur_v = q.front();
			q.pop();
			for (auto[v, w] : v[cur_v]) {
				if (!vis[v]) {
					cost[v] = cost[cur_v] + w;
					vis[v] = true;
					q.push(v);
				}
			}
		}
		return max_element(all(cost)) - cost.begin();
	};

	int cur = bfs(0);
	cur = bfs(cur);
	cout << cost[cur] << '\n';
	for (int i = 0; i < N; ++i) {
		v[i].clear();
	}
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t = 1, xx = 1;
	cin >> t;
	while (t--) {
		cout << "Case " << xx++ << ": ";
		tcase();
	}
}

#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1E5 + 5;
constexpr int64_t INF = 1E15;
void tcase() {
	int n; cin >> n;
	vector<array<int, 2>>v[N];
	for (int i = 0; i < n; ++i) {
		int a, b, w; cin >> a >> b >> w;
		v[a].push_back({b, w});
		v[b].push_back({a, w});
	}
	auto dijkstra = [&](int ver)->void{
		queue<array<int64_t, 2>>q;
		vector<int64_t>dis(N, INF);
		vector<bool>vis(N, false);
		q.push({0, ver});
		dis[ver] = 0;
		while (!q.empty()) {
			auto [cur_w, cur_v] = q.front();
			q.pop();
			if (vis[cur_v])continue;
			vis[cur_v] = true;
			for (auto [c_v, c_w] : v[cur_v]) {
				if (dis[cur_v] + c_w < dis[c_v]) {
					dis[c_v] = dis[cur_v] + c_w;
					q.push({dis[c_v], c_v});
				}
			}
		}
	};
	dijkstra(1);
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
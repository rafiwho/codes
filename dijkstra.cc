#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
constexpr i64 INF = 1E15;
constexpr int N = 2E5 + 5;
std::vector<array<int, 2>> graph[N];
void tcase() {

	int n; cin >> n;
	for (int i = 1; i <= n - 1; ++i) {
		int u, v, weight; cin >> u >> v >> weight;
		graph[u].push_back({v, weight});
		graph[v].push_back({u, weight});
	}

	auto dijkstra = [&](int source)->i64{

		min_heap<array<i64, 2>>q;
		vector<bool>vis(N, false);
		vector<i64>dis(N, INF);

		q.push({0, source});
		dis[source] = 0;

		while (!q.empty()) {
			auto [cur_w, cur_v] = q.top();
			q.pop(); if (vis[cur_v])continue;
			vis[cur_v] = true;

			for (auto [child_v, child_w] : graph[cur_v]) {

				if (dis[cur_v] + child_w < dis[child_v]) {
					dis[child_v] = dis[cur_v] + child_w;
					q.push({dis[child_v], child_v});
				}

			}
		}

		return dis[n];
	};

	cout << dijkstra(1) << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
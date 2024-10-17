#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
constexpr i64 INF = 1E15;
constexpr int N = 2E5 + 5;
std::vector<array<int, 2>> v[N];
int cs = 1;
void tcase() {

	int n, m; cin >> n >> m;
	int st, en; cin >> st >> en;
	++st; ++en;

	for (int i = 1; i <= m; ++i) {
		int a, b, x; cin >> a >> b >> x;
		v[++a].push_back({++b, x});
		v[b].push_back({a, x});
	}

	auto dijkstra = [&](int source)->i64{

		min_heap<array<i64, 2>>q;
		vector<i64>dis(N, INF);

		q.push({0, st});
		dis[st] = 0;

		while (!q.empty()) {
			auto [cur_w, cur_v] = q.top();
			q.pop();
			if (dis[cur_v] < cur_w) continue;


			for (auto [child_v, child_w] : v[cur_v]) {

				if (dis[cur_v] + child_w < dis[child_v]) {
					dis[child_v] = dis[cur_v] + child_w;
					q.push({dis[child_v], child_v});
				}

			}
		}

		return dis[en];
	};
	cout << "Case #" << cs++ << ": ";
	i64 ans = dijkstra(st);
	if (ans == INF) {
		cout << "unreachable\n";
	} else {
		cout << ans << '\n';
	}
	for (int i = 0; i < n; ++i) {
		v[i + 1].clear();
	}
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	cin >> t;

	while (t-- > 0)
		tcase();
}
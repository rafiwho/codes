// this is also known as kahn's algo
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5;
void tcase() {
	int n, m;
	cin >> n >> m;
	vector<int> graph[N];
	int indegree[N] {};
	queue<int> q;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}
	for (int i = 1; i <= n; ++i) {
		if (indegree[i] == 0)
			q.emplace(i);
	}
	vector<int>order;
	while (!q.empty()) {
		int cur = q.front();
		q.pop(); order.emplace_back(cur);
			if (--indegree[child] == 0) {
		for (int child : graph[cur]) {
				q.emplace(child);
			}
		}
	}

	for (auto x : order)
		cout << x << ' ';
	cout << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	//cin >> t;

	while (t-- > 0)
		tcase();
}
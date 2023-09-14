#include <bits/stdc++.h>
using namespace std;

void tcase() {
	int n, in;
	cin >> n >> in;
	vector<int> v(in);
	priority_queue<int> pq;
	for (auto &A : v)
		cin >> A;
	sort(v.begin(), v.end());
	for (auto i = 1; i < in; ++i) {
		pq.emplace(v[i] - v[i - 1] - 1);
	}
	int lr = n - v.back() + v.front() - 1;
	pq.emplace(lr);
	int inc = 0;
	int saved = 0;
	while (!pq.empty()) {
		int u = pq.top();
		pq.pop();
		u -= inc;
		if (u > 0)
			saved += max(1, u - 1);
		inc += 4;
	}
	cout << n - saved << '\n';
}
int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	cin >> t;

	while (t-- > 0)
		tcase();
}
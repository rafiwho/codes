#include <algorithm>
#include <any>
#include <bits/stdc++.h>
#include <set>
#include <vector>
using namespace std;
#include "EMNI.HPP"

void tcase() {
	int n;
	cin >> n;
	std::vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	map<int, int>mp;
	for (int i = 1; i <= n; ++i) {
		mp[i] = i - 1;
	}
	mp[1] = n;
	debug(mp);
	vector<bool>used(n + 1, false);
	vector<int>ans1, ans2;
	for (int i = 0; i < n; ++i) {
		if (!used[mp[v[i]]]) {
			ans1.push_back(mp[v[i]]);
			used[mp[v[i]]] = true;
		} else {
			ans1.push_back(v[i]);
		}
	}
	used.assign(n + 1, false);
	for (int i = 0; i < n; ++i) {
		if (!used[mp[ans1[i]]]) {
			ans2.push_back(mp[ans1[i]]);
			used[mp[ans1[i]]] = true;
		} else {
			ans2.push_back(ans1[i]);
		}
	}
	set<int>st1(ans1.begin(), ans1.end());
	set<int>st2(ans2.begin(), ans2.end());
	bool ans = st1.size() == n && st2.size() == n;

	vector<int>construct(n);
	for (int i = 0; i < n; ++i) {
		construct[i] = max(ans1[i], ans2[i]);
	}
	debug(ans1);
	debug(ans2);
	debug(construct);
	ans &= construct == v;

	if (ans) {
		cout << "YES\n";
		for (int i = 0; i < n; ++i) {
			cout << ans1[i] << ' ';
		}
		cout << '\n';
		for (int i = 0; i < n; ++i) {
			cout << ans2[i] << ' ';
		}
		cout << '\n';
	} else {
		cout << "NO\n";
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